# Healing Stats Expert Review Standard

This repository contains local draft language packs for the Guild Wars 2 arcdps Healing Stats addon.

Do not upload, push, or publish anything from this review pass unless the user explicitly asks.

## Review Goal

Move each locale from `reviewed_draft` toward `release_candidate_candidate` quality:

- structurally valid INI
- placeholders preserved
- escaped newline layout reviewed
- compact UI labels
- no obvious machine-translation residue
- Guild Wars 2 / arcdps meaning preserved
- uncertain language choices documented for real native/in-game review

This pass is not allowed to pretend that a real outside native speaker or GW2 player approved the translation. Since the user cannot personally review every language, prefer external/public research plus conservative MMORPG terminology and record confidence honestly.

## Translation Philosophy

Stay close to the original. The goal is not creative rewriting.

- Preserve the original UI structure and conceptual boundaries.
- Localize meaning only enough that target-language users understand the same thing an English GW2/arcdps user would understand.
- Prefer direct, compact, domain-accurate labels over polished marketing-like language.
- Do not add meaning that is not in the source.
- Do not remove source meaning to make a label prettier.
- When the original is a technical/addon term, a target-language technical loanword can be better than an over-localized phrase.
- Only depart from a literal translation when a literal translation would mislead players, such as `Peers outgoing` reading as a shared-healing game mechanic.

## Source Priority

1. `localization/canonical/Healing_Stats.en.ini`
2. The current target locale draft
3. `localization/AGENT_BRIEF.md`
4. Per-language review notes in `localization/reports`
5. Guild Wars 2 official wiki/community wiki terminology
6. Current Korean localization only as semantic reference for concepts already settled by the user

Do not translate from Korean into another language.

## High-Risk Meaning Rules

- `Peers outgoing` means outgoing healing/barrier stats from other squad members via live stats sharing. It is not a Guild Wars 2 mechanic named shared healing.
- In compact labels, avoid terms equivalent to "shared healing" when they can be misread as a game mechanic.
- `Live stats sharing` can use "share/sharing" wording only when describing the addon network feature itself.
- `Hits` means healing/barrier event ticks in this addon context, not weapon hits.
- `Healing per hit` means healing per event/tick.
- `Barrier generation` is the Guild Wars 2 barrier mechanic, not shield, block, guard, or protection.
- `From Damage Dealt` is an aggregate/pseudo entry, not a skill name.
- `Group` is the GW2 party/subgroup context.
- `Squad` is the GW2 squad context.
- Skill names, profession/class names, and elite specialization names must not be localized by this addon language pack.

## UI Style Rules

- Compact menu labels should be nouns or short noun phrases.
- Long explanatory sentences belong in tooltips, not menu labels.
- Technical tokens may remain English where that is normal for the target-language GW2/MMO community.
- If the target language has no official Guild Wars 2 localization, prefer stable community/MMO wording over invented official-sounding terms.
- Preserve technical tokens: `Guild Wars 2`, `arcdps`, `EVTC`, `RPC`, `TLS`, `kiB/s`, `CPU`, `evtc_rpc`, paths, hotkey wording, and format examples.

## Structural Rules

- Preserve all sections and keys from the canonical English file.
- Preserve all placeholders exactly: `{1}`-`{7}`, `%s`, `%u`, `%llu`, `###HEALING_STATS_UPDATE`.
- Preserve literal path escapes such as `addons\\logs\\arcdps_healing_stats\\`.
- Prefer matching escaped `\n` counts with the canonical file unless the review note explicitly records a layout decision.
- UTF-8 is the target encoding.

## Required Review Output

For each language, write or update:

```text
localization/reviews/<lang>_expert_review.md
```

Use this status vocabulary:

- `needs_revision`: clear errors remain
- `research_reviewed`: external/public research plus conservative expert/GW2 review completed
- `conservatively_reviewed_draft`: agent-side expert/GW2 review completed when external research is thin
- `low_confidence_needs_more_research`: language quality cannot be responsibly judged from available public sources

Do not mark any language `final` from agent-side review alone.
