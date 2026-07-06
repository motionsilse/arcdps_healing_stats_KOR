# Thai Healing Stats Expert Review

Status: `conservatively_reviewed_draft`

## Scope

- Reviewed `localization/drafts/th/Healing_Stats.th.ini` against `localization/canonical/Healing_Stats.en.ini`.
- Used `localization/EXPERT_REVIEW_STANDARD.md`, `localization/SOURCE_NOTES.md`, `localization/AGENT_BRIEF.md`, and `localization/reports/th_review.md`.
- No GitHub, upload, push, packaging, or release artifact work was performed.

## Public Evidence Used

- Guild Wars 2 Wiki: [Healing](https://wiki.guildwars2.com/wiki/Healing), [Barrier](https://wiki.guildwars2.com/wiki/Barrier), [Squad](https://wiki.guildwars2.com/wiki/Squad), [Party](https://wiki.guildwars2.com/wiki/Party).
- GuildWars2.com: [Introducing Enhanced Squad UI](https://www.guildwars2.com/en/news/introducing-enhanced-squad-ui/) and [Enhanced Squad UI Features on Guild Chat](https://www.guildwars2.com/en/news/enhanced-squad-ui-features-on-guild-chat-a-summary/) for squad/subgroup behavior.
- Guild Wars 2 forum thread on Healing Stats: [Peers outgoing requires stat sharing from both sides](https://en-forum.guildwars2.com/topic/135096-anyone-familiar-with-arcdps-healing-stats-extension/).
- Thai public game-writing examples support `สกิล`, `อาชีพ`, `ฮีล`, `ปาร์ตี้`, `บาเรีย`, and technical loanwords: [Online Station GW2 beginner guide](https://www.online-station.net/pc-console-game/140804/), [Playulti GW2 races](https://playulti.com/news/%E0%B9%80%E0%B8%9C%E0%B9%88%E0%B8%B2%E0%B8%9E%E0%B8%B1%E0%B8%99%E0%B8%98%E0%B9%8C%E0%B8%97%E0%B8%B1%E0%B9%89%E0%B8%87-5-%E0%B8%82%E0%B8%AD%E0%B8%87-Guildwars2), and [Playulti Lineage W class article](https://www.playulti.com/news/%E0%B8%A3%E0%B8%A7%E0%B8%A1%E0%B8%97%E0%B8%B8%E0%B8%81%E0%B8%AD%E0%B8%B2%E0%B8%8A%E0%B8%B5%E0%B8%9E-Lineage-W-%E0%B9%80%E0%B8%81%E0%B8%A1%E0%B8%AD%E0%B8%AD%E0%B8%99%E0%B9%84%E0%B8%A5%E0%B8%99%E0%B9%8C%E0%B8%9F%E0%B8%A3%E0%B8%B5-MMORPG-%E0%B9%80%E0%B8%99%E0%B9%89%E0%B8%99%E0%B9%83%E0%B8%AB%E0%B9%89%E0%B8%8A%E0%B8%B2%E0%B8%95%E0%B8%B4%E0%B9%84%E0%B8%97%E0%B8%A2-Vs-%E0%B8%8A%E0%B8%B2%E0%B8%95%E0%B8%B4%E0%B8%AD%E0%B8%B7%E0%B9%88%E0%B8%99-%E0%B8%A1%E0%B8%B5%E0%B8%A0%E0%B8%B2%E0%B8%A9%E0%B8%B2%E0%B9%84%E0%B8%97%E0%B8%A2).

## Direct Fixes

- `5_name`: `ฮีลสมาชิก squad` -> `ฮีลจากสมาชิก squad`
- `5_title_format`: `ฮีลสมาชิก squad ...` -> `ฮีลจากสมาชิก squad ...`
- `6_name`: `บาเรียสมาชิก squad` -> `บาเรียจากสมาชิก squad`
- `[enum_data_source] peers_outgoing`: `ฮีลสมาชิก squad` -> `ฮีลจากสมาชิก squad`

These are minimal source/actor clarifications. They preserve the original compact label style while making clear that the stats come from other squad members through live stats sharing.

## Review Findings

- `Peers outgoing` now uses `จากสมาชิก squad`, avoiding any reading like a shared-healing game mechanic or healing applied to squad members.
- `Live stats sharing` remains `แชร์ live stats` only where the addon feature itself is described.
- `Hits` remains `tick`, which is safer than a Thai weapon-hit wording because the addon counts healing/barrier event ticks.
- `Barrier generation` uses `สร้างบาเรีย` / `บาเรีย`, preserving the GW2 barrier mechanic and avoiding shield/block/protection wording.
- `From Damage Dealt` is `จากดาเมจที่ทำ`, a source/aggregate label rather than a skill name.
- `Group` uses `ปาร์ตี้`; `Squad` remains the English loanword `Squad`. This is conservative for Thai MMO users and keeps the GW2 party/squad distinction visible.
- Skill, profession, and elite specialization names are not present as concrete names. Generic UI labels `สกิล` and `อาชีพ` are acceptable local game terms.

## Verification

Command run:

```powershell
python localization\tools\verify_healing_stats_locale.py --targets ja th vi --strict-newlines
```

Result for `th`: `PASS`.

Warnings reviewed as intentional:

- `[enum_position] manual` remains English as a compact technical UI mode.
- `[group_filter] squad` remains English as a GW2/MMO loanword.

## Remaining Uncertainty

- No official Thai GW2 localization was found. The draft therefore keeps common Thai MMO loanwords such as `ฮีล`, `สกิล`, `ปาร์ตี้`, `บาเรีย`, `squad`, `tick`, and `cast` where they are closer to community UI usage than invented official-sounding terms.
- `ปาร์ตี้` is used for the group/subgroup context; this is compact and familiar, though GW2's technical squad UI term is "subgroup".
