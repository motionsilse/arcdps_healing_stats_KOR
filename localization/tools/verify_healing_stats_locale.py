#!/usr/bin/env python3
from __future__ import annotations

import argparse
import configparser
from collections import Counter
from dataclasses import dataclass, field
from pathlib import Path
import re
import sys


PLACEHOLDER_RE = re.compile(r"(?:\{[0-9]+\}|%llu|%u|%s|###HEALING_STATS_UPDATE)")
NEWLINE_RE = re.compile(r"\\n")


@dataclass
class LocaleResult:
    code: str
    path: Path
    errors: list[str] = field(default_factory=list)
    warnings: list[str] = field(default_factory=list)

    @property
    def ok(self) -> bool:
        return not self.errors


def read_ini(path: Path) -> configparser.ConfigParser:
    parser = configparser.ConfigParser(interpolation=None, strict=True)
    parser.optionxform = str
    with path.open("r", encoding="utf-8-sig", newline="") as handle:
        parser.read_file(handle)
    return parser


def value_placeholders(value: str) -> Counter[str]:
    return Counter(PLACEHOLDER_RE.findall(value))


def escaped_newline_count(value: str) -> int:
    return len(NEWLINE_RE.findall(value))


def compare_locale(
    code: str,
    canonical_path: Path,
    target_path: Path,
    strict_newlines: bool,
) -> LocaleResult:
    result = LocaleResult(code=code, path=target_path)

    if not target_path.exists():
        result.errors.append("file is missing")
        return result

    try:
        canonical = read_ini(canonical_path)
        target = read_ini(target_path)
    except UnicodeDecodeError as exc:
        result.errors.append(f"UTF-8 decode failed: {exc}")
        return result
    except configparser.Error as exc:
        result.errors.append(f"INI parse failed: {exc}")
        return result

    canonical_sections = canonical.sections()
    target_sections = target.sections()

    missing_sections = [section for section in canonical_sections if section not in target_sections]
    extra_sections = [section for section in target_sections if section not in canonical_sections]
    if missing_sections:
        result.errors.append(f"missing sections: {', '.join(missing_sections)}")
    if extra_sections:
        result.errors.append(f"extra sections: {', '.join(extra_sections)}")

    for section in canonical_sections:
        if section not in target:
            continue

        canonical_keys = list(canonical[section].keys())
        target_keys = list(target[section].keys())

        missing_keys = [key for key in canonical_keys if key not in target[section]]
        extra_keys = [key for key in target_keys if key not in canonical[section]]
        if missing_keys:
            result.errors.append(f"[{section}] missing keys: {', '.join(missing_keys)}")
        if extra_keys:
            result.errors.append(f"[{section}] extra keys: {', '.join(extra_keys)}")

        for key in canonical_keys:
            if key not in target[section]:
                continue

            canonical_value = canonical[section][key]
            target_value = target[section][key]
            if "\ufffd" in target_value:
                result.errors.append(f"[{section}] {key}: replacement character found")

            canonical_tokens = value_placeholders(canonical_value)
            target_tokens = value_placeholders(target_value)
            if canonical_tokens != target_tokens:
                result.errors.append(
                    f"[{section}] {key}: placeholder mismatch "
                    f"expected={dict(canonical_tokens)} actual={dict(target_tokens)}"
                )

            canonical_newlines = escaped_newline_count(canonical_value)
            target_newlines = escaped_newline_count(target_value)
            if canonical_newlines != target_newlines:
                message = (
                    f"[{section}] {key}: escaped newline count differs "
                    f"expected={canonical_newlines} actual={target_newlines}"
                )
                if strict_newlines:
                    result.errors.append(message)
                else:
                    result.warnings.append(message)

            if target_value == canonical_value and any(ch.isalpha() for ch in canonical_value):
                result.warnings.append(f"[{section}] {key}: unchanged from English")

    return result


def target_path_for(root: Path, code: str) -> Path:
    draft_path = root / "localization" / "drafts" / code / f"Healing_Stats.{code}.ini"
    if draft_path.exists() or code != "ko":
        return draft_path
    return root / "Healing_Stats.ko.ini"


def discover_targets(root: Path) -> list[str]:
    draft_root = root / "localization" / "drafts"
    codes = sorted(
        path.parent.name
        for path in draft_root.glob("*/Healing_Stats.*.ini")
        if path.is_file()
    )
    if (root / "Healing_Stats.ko.ini").exists() and "ko" not in codes:
        codes.insert(0, "ko")
    return codes


def write_report(report_path: Path, results: list[LocaleResult]) -> None:
    lines: list[str] = ["# Healing Stats locale verification", ""]
    for result in results:
        status = "PASS" if result.ok else "FAIL"
        lines.append(f"## {result.code} - {status}")
        lines.append("")
        lines.append(f"File: `{result.path}`")
        lines.append("")
        if result.errors:
            lines.append("Errors:")
            lines.extend(f"- {error}" for error in result.errors)
            lines.append("")
        if result.warnings:
            lines.append("Warnings:")
            lines.extend(f"- {warning}" for warning in result.warnings[:50])
            if len(result.warnings) > 50:
                lines.append(f"- ... {len(result.warnings) - 50} more warnings")
            lines.append("")
        if not result.errors and not result.warnings:
            lines.append("No issues found.")
            lines.append("")

    report_path.parent.mkdir(parents=True, exist_ok=True)
    report_path.write_text("\n".join(lines), encoding="utf-8", newline="\n")


def main() -> int:
    parser = argparse.ArgumentParser(description="Verify Healing Stats localization INI files.")
    parser.add_argument("--root", type=Path, default=Path.cwd())
    parser.add_argument("--canonical", type=Path, default=None)
    parser.add_argument("--targets", nargs="*", default=None)
    parser.add_argument("--report-md", type=Path, default=None)
    parser.add_argument("--strict-newlines", action="store_true")
    args = parser.parse_args()

    root = args.root.resolve()
    canonical_path = args.canonical or root / "localization" / "canonical" / "Healing_Stats.en.ini"
    target_codes = args.targets if args.targets is not None else discover_targets(root)

    results = [
        compare_locale(code, canonical_path, target_path_for(root, code), args.strict_newlines)
        for code in target_codes
    ]

    for result in results:
        status = "PASS" if result.ok else "FAIL"
        print(f"{result.code}: {status} ({result.path})")
        for error in result.errors:
            print(f"  ERROR: {error}")
        for warning in result.warnings[:10]:
            print(f"  WARN: {warning}")
        if len(result.warnings) > 10:
            print(f"  WARN: ... {len(result.warnings) - 10} more warnings")

    if args.report_md is not None:
        report_path = args.report_md
        if not report_path.is_absolute():
            report_path = root / report_path
        write_report(report_path, results)

    return 1 if any(not result.ok for result in results) else 0


if __name__ == "__main__":
    sys.exit(main())
