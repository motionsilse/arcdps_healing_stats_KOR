# German Healing Stats Expert Review

Status: conservatively_reviewed_draft

## Scope

- Reviewed all 161 German strings against `localization/canonical/Healing_Stats.en.ini`.
- Draft reviewed: `localization/drafts/de/Healing_Stats.de.ini`.
- Review mode: conservative language edit plus Guild Wars 2/arcdps terminology check.
- No GitHub, push, upload, package, or release artifact work was performed.

## Public Terminology Evidence

- German GW2 wiki `Heilung`: https://wiki-de.guildwars2.com/wiki/Heilung
- German GW2 wiki `Barriere`: https://wiki-de.guildwars2.com/wiki/Barriere
- German GW2 wiki `Einsatztrupp`: https://wiki-de.guildwars2.com/wiki/Einsatztrupp

These sources support `Heilung`, `Barriere`, `Einsatztrupp`, and `Untergruppe` as stable German GW2 terms. The `Einsatztrupp` page also describes Untergruppen and group-priority behavior inside squads.

## High-Risk Decisions

- `Peers outgoing` remains `Peers ausgehend`. This stays close to the addon/network meaning and avoids implying a GW2 shared-healing mechanic.
- `Live stats sharing` is translated only where the addon feature itself is described; compact peer labels do not use shared-healing wording.
- `Hits` is `Ticks`, because the addon counts healing/barrier event ticks rather than weapon hits.
- `Barrier generation` uses `Barriereaufbau` / `Barriere`; this preserves the GW2 barrier mechanic and avoids shield/block/protection wording.
- `From Damage Dealt` is `Aus verursachtem Schaden`, treated as an aggregate/pseudo entry rather than a skill name.
- `Group` / `Squad` are `Untergruppe` / `Einsatztrupp`.
- Skill, profession, and elite specialization names were not introduced or localized.

## Edits Made

- No German draft edits were needed in this pass. Existing terminology and strict newline layout were acceptable.

## Verification

- `python localization/tools/verify_healing_stats_locale.py --root . --targets de es fr pt --strict-newlines`
- Result for `de`: PASS.
- Warnings are intentional unchanged technical/UI tokens: `{1} ({4}/s)`, `Position`, `Hotkey`, and `Heal Stats`.

## Remaining Uncertainty

- `Peers` and `Casts` are retained as compact technical/MMO parser terms. This is conservative for arcdps users, but a native in-game UI pass could choose more Germanized wording if clipping permits.
- `Beschwörungen` for summons is plausible, but addon internals may include pets/minions/clones/spawns; no clearer public German GW2 umbrella term was found for this addon-specific filter.
