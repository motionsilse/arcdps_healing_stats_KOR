# Spanish Healing Stats Expert Review

Status: conservatively_reviewed_draft

## Scope

- Reviewed all 161 Spanish strings against `localization/canonical/Healing_Stats.en.ini`.
- Draft reviewed: `localization/drafts/es/Healing_Stats.es.ini`.
- Review mode: conservative language edit plus Guild Wars 2/arcdps terminology check.
- No GitHub, push, upload, package, or release artifact work was performed.

## Public Terminology Evidence

- Spanish GW2 wiki `Barrera`: https://wiki-es.guildwars2.com/wiki/Barrera
- Spanish GW2 wiki `Combate`: https://wiki-es.guildwars2.com/wiki/Combate
- Spanish GW2 wiki `Escuadrón`: https://wiki-es.guildwars2.com/wiki/Escuadr%C3%B3n

These sources support `Curación`, `Poder de curación`, `Barrera`, `Escuadrón`, and `subgrupo` in the GW2 context. The `Barrera` page explicitly discusses `barrera generada`, which matches the addon stat.

## High-Risk Decisions

- `Peers outgoing` is `Compañeros: curación` / `curación de compañeros`. This stays user-facing and avoids a false GW2 mechanic like shared healing.
- `Live stats sharing` uses sharing wording only for the addon feature itself.
- `Hits` is `ticks`, because the addon counts healing/barrier event ticks rather than weapon hits.
- `Barrier generation` uses `barrera generada` / `barrera`, not shield/block wording.
- `From Damage Dealt` is `Por daño infligido`, an aggregate/pseudo entry rather than a skill name.
- `Group` / `Squad` are `Grupo` / `Escuadrón`.
- Skill, profession, and elite specialization names were not introduced or localized.

## Edits Made

- No Spanish terminology rewrite was needed in this pass.
- The current draft already preserves strict escaped-newline layout for the high-risk live sharing tooltips.

## Verification

- `python localization/tools/verify_healing_stats_locale.py --root . --targets de es fr pt --strict-newlines`
- Result for `es`: PASS.
- Warnings are intentional unchanged source-adjacent UI tokens: `{1} ({4}/s)` and `manual`.

## Remaining Uncertainty

- `compañeros` is clearer than technical `pares` for compact peer labels, but it means addon peers/squad members via live stats sharing, not a GW2 shared-healing mechanic.
- `stats`, `ticks`, and `heal stats` are retained as MMO/arcdps loanwords where they keep compact UI close to the source.
