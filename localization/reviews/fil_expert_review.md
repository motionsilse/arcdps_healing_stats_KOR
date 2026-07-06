# Filipino Healing Stats Expert Review

status: conservatively_reviewed_draft

## Scope

- Reviewed file: `localization/drafts/fil/Healing_Stats.fil.ini`
- Review date: 2026-07-06
- Scope limited to Filipino (`fil`) Healing Stats strings.
- No GitHub, upload, push, package, or human-review packet work was used.

## Public Sources Used

- Canonical source: `localization/canonical/Healing_Stats.en.ini`
- Project meaning notes: `localization/EXPERT_REVIEW_STANDARD.md`, `localization/AGENT_BRIEF.md`, `localization/SOURCE_NOTES.md`
- GW2 Wiki: [Healing](https://wiki.guildwars2.com/wiki/Healing), [Barrier](https://wiki.guildwars2.com/wiki/Barrier), [Squad](https://wiki.guildwars2.com/wiki/Squad), [Party](https://wiki.guildwars2.com/wiki/Party), [Skill](https://wiki.guildwars2.com/wiki/Skill), [Profession](https://wiki.guildwars2.com/wiki/Profession)
- GW2 forum evidence: [Peers outgoing / stat sharing](https://en-forum.guildwars2.com/topic/135096-anyone-familiar-with-arcdps-healing-stats-extension/), [arcdps and healing stats sharing](https://en-forum.guildwars2.com/topic/152638-arcdps-and-healing/)
- arcdps context: [deltaconnected arcdps](https://www.deltaconnected.com/arcdps/)
- Filipino game-language evidence: [A Diverse Application of Language: Filipino Gamers](https://www.academia.edu/12100373/A_Diverse_Application_of_Language_Filipino_Gamers), [TagLish overview](https://www.talkio.ai/blog/taglish-understanding-the-filipino-code-switching-phenomenon)

## Expert Findings

- `Peers outgoing` is rendered as `Outgoing ng squad members` / `outgoing ng squad members`. This stays close to source while avoiding a Filipino phrase for "shared healing" that could imply a GW2 mechanic.
- `Live stats sharing` remains code-switched only for the addon feature. This is appropriate for a compact arcdps option and is backed by public GW2 forum usage around stat sharing.
- `Hits` is rendered as `ticks` / `tick`, which preserves the addon meaning of healing/barrier events instead of weapon hits.
- `Barrier generation` uses `barrier gen`, not shield/block/protection wording. This keeps the GW2 barrier mechanic distinct.
- `From Damage Dealt` remains `Mula sa Damage Dealt`. This is intentionally close to source and reads as an aggregate label, not a skill name.
- `Group`, `Squad`, `Skills`, `profession`, `combat`, `target`, and similar terms are left as technical/code-switched MMO UI terms where that is closer to the source and common Filipino gamer usage.
- Skill names, profession names, and elite specialization names are not localized by this file; the category label `Skills` is a UI bucket, not a skill name.

## Changes Made

- No direct changes were required for Filipino in this pass.

## Remaining Uncertainty

- No official Filipino Guild Wars 2 localization was found, so this remains a conservative expert draft rather than a community-approved release candidate.
- In-game UI clipping and player preference between heavier Tagalog and Taglish style were not tested. The current draft intentionally favors compact Taglish/MMO overlay wording.
