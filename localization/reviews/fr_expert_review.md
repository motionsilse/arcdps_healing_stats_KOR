# French Healing Stats Expert Review

Status: conservatively_reviewed_draft

## Scope

- Reviewed all 161 French strings against `localization/canonical/Healing_Stats.en.ini`.
- Draft reviewed: `localization/drafts/fr/Healing_Stats.fr.ini`.
- Review mode: conservative language edit plus Guild Wars 2/arcdps terminology check.
- No GitHub, push, upload, package, or release artifact work was performed.

## Public Terminology Evidence

- French GW2 wiki `Barrière`: https://wiki-fr.guildwars2.com/wiki/Barri%C3%A8re
- French GW2 wiki `Guérison`: https://wiki-fr.guildwars2.com/wiki/Gu%C3%A9rison
- French GW2 wiki `Escouade`: https://wiki-fr.guildwars2.com/wiki/Escouade
- Official French GW2 squad UI article: https://www.guildwars2.com/fr/news/enhanced-squad-ui-features-on-guild-chat-a-summary/

These sources support `barrière`, `guérison`/healing context, `escouade`, `groupe`, and subgroup-style squad terminology. The draft uses compact `soins` for UI statistics, which is idiomatic for displayed healing done while remaining aligned with GW2 healing terminology.

## High-Risk Decisions

- `Peers outgoing` is `Soins des pairs` / `soins des pairs`. This is addon peer/network wording and avoids implying a GW2 shared-healing mechanic.
- `Live stats sharing` uses `partage de stats en direct` only for the addon feature itself.
- `Hits` is `ticks`, because the addon counts healing/barrier event ticks rather than weapon hits.
- `Barrier generation` uses `barrière générée` / `barrière`, not shield/block wording.
- `From Damage Dealt` is `Issu des dégâts infligés`, treated as an aggregate/pseudo entry rather than a skill name.
- `Group` / `Squad` are `Groupe` / `Escouade`.
- Skill, profession, and elite specialization names were not introduced or localized.

## Edits Made

- No French draft edits were needed in this pass. Existing terminology and strict newline layout were acceptable.

## Verification

- `python localization/tools/verify_healing_stats_locale.py --root . --targets de es fr pt --strict-newlines`
- Result for `fr`: PASS.
- Warnings are intentional unchanged source-adjacent UI tokens: `{1} ({4}/s)`, `Style`, and `Position`.

## Remaining Uncertainty

- `pairs` is technically precise for addon peers, though `membres de l'escouade` would be more explicit and longer.
- `ticks` is kept as a compact MMO/parser loanword; `événements` would be less likely to be read as English but less close to the source and wider in UI.
