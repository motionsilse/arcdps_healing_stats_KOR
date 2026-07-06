#!/usr/bin/env python3
from __future__ import annotations

import argparse
from pathlib import Path
import zipfile


def find_default_dll(root: Path) -> Path:
    candidates = [
        root / "x64" / "Release" / "Healing_Stats.dll",
        root / "x64" / "Release" / "arcdps_healing_stats" / "Healing_Stats.dll",
    ]
    for candidate in candidates:
        if candidate.exists():
            return candidate
    raise FileNotFoundError("Healing_Stats.dll was not found. Build Release x64 first or pass --dll.")


def collect_locale_files(root: Path) -> list[Path]:
    files: list[Path] = []
    korean = root / "Healing_Stats.ko.ini"
    if korean.exists():
        files.append(korean)
    draft_root = root / "localization" / "drafts"
    files.extend(sorted(draft_root.glob("*/Healing_Stats.*.ini")))
    return files


def main() -> int:
    parser = argparse.ArgumentParser(description="Create a local multilingual Healing Stats ZIP.")
    parser.add_argument("--root", type=Path, default=Path.cwd())
    parser.add_argument("--dll", type=Path, default=None)
    parser.add_argument("--output", type=Path, default=None)
    args = parser.parse_args()

    root = args.root.resolve()
    dll_path = args.dll.resolve() if args.dll else find_default_dll(root)
    output = args.output or root / "dist" / "Healing_Stats_multilang_local.zip"
    if not output.is_absolute():
        output = root / output
    output.parent.mkdir(parents=True, exist_ok=True)

    locale_files = collect_locale_files(root)
    if not locale_files:
        raise FileNotFoundError("No Healing_Stats.<lang>.ini files found.")

    readme_path = root / "localization" / "README.md"
    locale_example_path = root / "localization" / "Healing_Stats.locale.example.ini"

    with zipfile.ZipFile(output, "w", compression=zipfile.ZIP_DEFLATED) as archive:
        archive.write(dll_path, "Healing_Stats.dll")
        if readme_path.exists():
            archive.write(readme_path, "README.md")
        if locale_example_path.exists():
            archive.write(locale_example_path, "Healing_Stats.locale.ini")
        for locale_file in locale_files:
            archive.write(locale_file, locale_file.name)

    print(output)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
