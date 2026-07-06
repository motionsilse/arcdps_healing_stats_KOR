# Portuguese Healing Stats Expert Review

Status: conservatively_reviewed_draft

## Scope

- Reviewed all 161 Portuguese strings against `localization/canonical/Healing_Stats.en.ini`.
- Draft reviewed and edited: `localization/drafts/pt/Healing_Stats.pt.ini`.
- Review mode: conservative language edit plus Guild Wars 2/arcdps terminology check.
- No GitHub, push, upload, package, or release artifact work was performed.

## Public Terminology Evidence

- ArenaNet support FAQ lists the supported Guild Wars 2 client languages as English, French, German, and Spanish: https://help.guildwars2.com/hc/en-us/articles/201862738-FAQ-Game-Regions

No reliable official Portuguese GW2 client terminology was found. The Portuguese draft therefore uses common Brazilian Portuguese MMORPG/addon wording while staying close to the English source: `cura`, `barreira`, `esquadrão`, `grupo`, `stats`, `ticks`, and `casts`.

## High-Risk Decisions

- `Peers outgoing` is `Membros: cura` / `membros: cura feita`. This avoids a false shared-healing mechanic and points to other live-sharing squad members.
- `Live stats sharing` uses `compartilhamento de stats ao vivo` only for the addon feature itself.
- `Hits` is `ticks`, because the addon counts healing/barrier event ticks rather than weapon hits.
- `Barrier generation` uses `barreira gerada` / `barreira`, not shield/block/protection wording.
- `From Damage Dealt` is `Do dano causado`, an aggregate/pseudo entry rather than a skill name.
- `Group` / `Squad` are `Grupo` / `Esquadrão`; this is a conservative non-official PT choice.
- Skill, profession, and elite specialization names were not introduced or localized.

## Edits Made

- Corrected clear Portuguese orthography in existing tooltip/update text while preserving source meaning, technical loanwords, placeholders, and escaped newline layout.
- Examples: `estatisticas` -> `estatísticas`, `nao` -> `não`, `opcao` -> `opção`, `versao` -> `versão`, `atualizacao` -> `atualização`.
- No creative terminology rewrite was made.

## Verification

- `python localization/tools/verify_healing_stats_locale.py --root . --targets de es fr pt --strict-newlines`
- Result for `pt`: PASS.
- Warnings are intentional unchanged technical/UI tokens: `{1} ({4}/s)`, `manual`, and `casts`.

## Remaining Uncertainty

- Because Portuguese is not an official GW2 client language, `esquadrão`, `stats`, `ticks`, and `casts` should be understood as community/MMO choices rather than official terminology.
- The draft is suitable as a conservative reviewed draft, but not a release-candidate claim of native or in-game Portuguese approval.
