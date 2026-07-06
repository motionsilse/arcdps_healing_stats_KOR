# Indonesian Healing Stats Expert Review

status: conservatively_reviewed_draft

## Scope

- Reviewed file: `localization/drafts/id/Healing_Stats.id.ini`
- Review date: 2026-07-06
- Scope limited to Indonesian (`id`) Healing Stats strings.
- No GitHub, upload, push, package, or human-review packet work was used.

## Public Sources Used

- Canonical source: `localization/canonical/Healing_Stats.en.ini`
- Project meaning notes: `localization/EXPERT_REVIEW_STANDARD.md`, `localization/AGENT_BRIEF.md`, `localization/SOURCE_NOTES.md`
- GW2 Wiki: [Healing](https://wiki.guildwars2.com/wiki/Healing), [Barrier](https://wiki.guildwars2.com/wiki/Barrier), [Squad](https://wiki.guildwars2.com/wiki/Squad), [Party](https://wiki.guildwars2.com/wiki/Party), [Skill](https://wiki.guildwars2.com/wiki/Skill), [Profession](https://wiki.guildwars2.com/wiki/Profession)
- GW2 forum evidence: [Peers outgoing / stat sharing](https://en-forum.guildwars2.com/topic/135096-anyone-familiar-with-arcdps-healing-stats-extension/), [arcdps and healing stats sharing](https://en-forum.guildwars2.com/topic/152638-arcdps-and-healing/)
- arcdps context: [deltaconnected arcdps](https://www.deltaconnected.com/arcdps/)
- Indonesian game-localization/code-switching evidence: [LocalizeDirect Indonesian game localization](https://www.localizedirect.com/posts/indonesian-game-localization), [Code Switching and Code Mixing in Mobile Legends Online Game Dialogue](https://www.atlantis-press.com/article/125990475.pdf)

## Expert Findings

- `Peers outgoing` is rendered as `Heal rekan squad` / `heal rekan squad`. This is close to source, points to squad peers, and avoids "shared healing" wording.
- `Live stats sharing` is rendered as `berbagi live stats` when describing the addon feature. Keeping `live stats` as a loan phrase is consistent with Indonesian game-localization guidance to keep familiar English game terms when clearer.
- `Hits` is rendered as `tick`, preserving the event/tick meaning and avoiding Indonesian wording that would imply weapon hits.
- `Barrier generation` uses `barrier gen` / `barrier`, preserving the GW2 barrier mechanic and avoiding shield/block/protection wording.
- `From Damage Dealt` is `Dari damage yang diberikan`, which stays close to source and reads as an aggregate/pseudo entry, not a skill name.
- `Group` is rendered as `Party`; `Squad` remains `Squad`. This follows the GW2 party/squad distinction while using common Indonesian MMO loanwords.
- `Skill` and `profesi` labels are UI/category labels only. No actual skill, profession, or elite specialization names are localized.

## Changes Made

- No direct changes were required for Indonesian in this pass.

## Remaining Uncertainty

- No official Indonesian Guild Wars 2 localization was found, so this remains a conservative expert draft rather than a community-approved release candidate.
- Some players may prefer fuller Indonesian wording for `heal`, `stats`, `combat`, or `window`, but the current code-switching is intentional and closer to public game UI usage.
