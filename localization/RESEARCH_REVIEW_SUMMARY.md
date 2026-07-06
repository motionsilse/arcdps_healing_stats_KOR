# Healing Stats Research Review Summary

This is a local, research-backed review summary for the multilingual `arcdps_healing_stats` language pack work.

Nothing in this pass was pushed or uploaded to GitHub.

## Review Philosophy

The review followed the Korean-pack lesson:

- stay close to the original English UI
- preserve the addon's meaning and data model
- localize only enough to prevent target-language misunderstanding
- avoid creative rewriting
- keep technical/MMORPG loanwords when they are clearer than invented terms
- never translate skill names, profession/class names, or elite specialization names

## Core Meaning Decisions

- `Peers outgoing` means outgoing stats from other squad members through the addon's live stats sharing path. It is not a shared-healing combat mechanic.
- `Live stats sharing` can use share/sharing wording only when describing the addon feature itself.
- `Hits` means healing/barrier event ticks in this addon context.
- `Barrier generation` is the Guild Wars 2 barrier mechanic, not a shield/block/protection concept.
- `From Damage Dealt` is an aggregate/pseudo entry, not a skill name.
- `Group` and `Squad` keep the GW2 group/squad distinction.

## Research Sources

- Krappa322 arcdps_healing_stats README: https://github.com/Krappa322/arcdps_healing_stats
- Guild Wars 2 Wiki, Healing: https://wiki.guildwars2.com/wiki/Healing
- Guild Wars 2 Wiki, Barrier: https://wiki.guildwars2.com/wiki/Barrier
- Guild Wars 2 Wiki, Squad: https://wiki.guildwars2.com/wiki/Squad
- Guild Wars 2 forum discussions on arcdps healing/stat sharing:
  - https://en-forum.guildwars2.com/topic/152638-arcdps-and-healing/
  - https://en-forum.guildwars2.com/topic/135096-anyone-familiar-with-arcdps-healing-stats-extension/
- Localized GW2 wiki/community sources used by language reviews are recorded in each `localization/reviews/*_expert_review.md`.

## Status By Language

| Code | Status | Notes |
|---|---|---|
| de | conservatively_reviewed_draft | Uses official/community GW2 German terms such as `Barriere`, `Heilung`, `Einsatztrupp`; kept `Peers` as technical addon wording. |
| es | conservatively_reviewed_draft | Uses Spanish GW2 terms such as `Curación`, `Barrera`, `Escuadrón`; strict newline verified after layout correction. |
| fil | conservatively_reviewed_draft | Intentional Filipino/English MMORPG code-switching; many unchanged English UI tokens are deliberate. |
| fr | conservatively_reviewed_draft | Uses `Barrière`, `Escouade`, `soins`; `pairs` kept as technical peer wording but noted as review-sensitive. |
| id | conservatively_reviewed_draft | Intentional Indonesian MMORPG code-switching; `Squad`, `tick`, `barrier`, `heal` retained where clearer. |
| ja | conservatively_reviewed_draft | Keeps peer labels as `メンバー別`, avoiding `共有` where it could imply shared-healing mechanics. |
| ms | conservatively_reviewed_draft | Peer labels changed toward `ahli skuad` to preserve squad-member source meaning. |
| pl | conservatively_reviewed_draft | Uses Polish compact overlay wording; `Inni ze składu` avoids shared-healing interpretation. |
| pt | conservatively_reviewed_draft | Portuguese spelling/layout corrected; keeps compact MMO loanwords where safer. |
| ru | conservatively_reviewed_draft | Russian grammar corrected for barrier total; uses community/MMORPG terms such as `хил`, `барьер`, `отряд`. |
| th | conservatively_reviewed_draft | Peer labels clarified as stats from squad members; keeps `Squad`, `tick`, `cast` as recognizable MMO tokens. |
| tr | conservatively_reviewed_draft | Keeps `Squad`, `cast`, `Heal Stats` as common MMO/product tokens; avoids shared-healing wording. |
| vi | conservatively_reviewed_draft | Peer labels clarified as stats/barrier from squad members; keeps `squad`, `barrier`, `tick` where no official Vietnamese GW2 term was verified. |
| ko | existing_reviewed_reference | Existing Korean pack retained. Placeholder verification passes; strict newline-only layout warnings remain because Korean text was not reworked in this pass. |

## Verification

- Non-Korean multilingual drafts pass strict structural verification with literal escaped newline parity:
  - `python localization\tools\verify_healing_stats_locale.py --root . --targets de es fil fr id ja ms pl pt ru th tr vi --strict-newlines`
- Korean plus all multilingual drafts pass placeholder/key verification:
  - `python localization\tools\verify_healing_stats_locale.py --root . --targets ko de es fil fr id ja ms pl pt ru th tr vi`

## Remaining Risk

This is the strongest practical agent-side review available from public sources and conservative GW2/MMO terminology research. It is still not the same as real native-player in-game UI testing.

The highest residual risk is style preference in languages that commonly code-switch with English MMO terms: `fil`, `id`, `ms`, `th`, and `vi`.
