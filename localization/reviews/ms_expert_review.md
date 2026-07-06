# Malay Healing Stats Expert Review

status: conservatively_reviewed_draft

## Scope

- Reviewed file: `localization/drafts/ms/Healing_Stats.ms.ini`
- Review date: 2026-07-06
- Scope limited to Malay (`ms`) Healing Stats strings.
- No GitHub, upload, push, package, or human-review packet work was used.

## Public Sources Used

- Canonical source: `localization/canonical/Healing_Stats.en.ini`
- Project meaning notes: `localization/EXPERT_REVIEW_STANDARD.md`, `localization/AGENT_BRIEF.md`, `localization/SOURCE_NOTES.md`
- GW2 Wiki: [Healing](https://wiki.guildwars2.com/wiki/Healing), [Barrier](https://wiki.guildwars2.com/wiki/Barrier), [Squad](https://wiki.guildwars2.com/wiki/Squad), [Party](https://wiki.guildwars2.com/wiki/Party), [Skill](https://wiki.guildwars2.com/wiki/Skill), [Profession](https://wiki.guildwars2.com/wiki/Profession)
- GW2 forum evidence: [Peers outgoing / stat sharing](https://en-forum.guildwars2.com/topic/135096-anyone-familiar-with-arcdps-healing-stats-extension/), [arcdps and healing stats sharing](https://en-forum.guildwars2.com/topic/152638-arcdps-and-healing/)
- arcdps context: [deltaconnected arcdps](https://www.deltaconnected.com/arcdps/)
- Malay code-switching/game-language evidence: [Explaining the Diversity in Malay-English Code-Switching Patterns](https://www.mdpi.com/2226-471X/7/4/299), [Gaming Slang in Malay Language](https://talkpal.ai/vocabulary/gaming-slang-in-malay-language/)

## Expert Findings

- `Peers outgoing` needed one narrow correction. `skuad lain` can naturally read as "another squad", but the addon means other members/peers in the current squad who share stats. The label now uses `ahli skuad`.
- `Live stats sharing` is rendered as `perkongsian stat langsung` for the addon feature. This is close to source while remaining readable Malay; English tokens remain where closer to game UI usage.
- `Hits` is rendered as `tick`, preserving the event/tick meaning and avoiding weapon-hit wording.
- `Barrier generation` uses `jana barrier` / `barrier`, preserving the GW2 barrier mechanic and avoiding shield/block/protection wording.
- `From Damage Dealt` is `Daripada damage diberi`, which stays close to source and reads as an aggregate/pseudo entry, not a skill name.
- `Group` / `Squad` are `Kumpulan` / `Skuad`. `Skill`, `profession`, `combat`, `window`, and related labels remain loanwords where that is closer to compact MMO UI usage.
- Skill names, profession names, and elite specialization names are not localized by this file; `Skill` and `profession` are UI/category labels.

## Changes Made

- `5_name=Stat skuad lain` -> `5_name=Stat ahli skuad`
- `6_name=Barrier skuad lain` -> `6_name=Barrier ahli skuad`
- `peers_outgoing=stat skuad lain` -> `peers_outgoing=stat ahli skuad`

## Remaining Uncertainty

- No official Malay Guild Wars 2 localization was found, so this remains a conservative expert draft rather than a community-approved release candidate.
- `Kumpulan` for GW2 group/party and the balance between Malay wording and English loanwords may vary by player community. The current choices intentionally stay close to source and compact overlay usage.
