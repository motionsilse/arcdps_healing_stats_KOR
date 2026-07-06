# Vietnamese Healing Stats Expert Review

Status: `conservatively_reviewed_draft`

## Scope

- Reviewed `localization/drafts/vi/Healing_Stats.vi.ini` against `localization/canonical/Healing_Stats.en.ini`.
- Used `localization/EXPERT_REVIEW_STANDARD.md`, `localization/SOURCE_NOTES.md`, `localization/AGENT_BRIEF.md`, and `localization/reports/vi_review.md`.
- No GitHub, upload, push, packaging, or release artifact work was performed.

## Public Evidence Used

- Guild Wars 2 Wiki: [Healing](https://wiki.guildwars2.com/wiki/Healing), [Barrier](https://wiki.guildwars2.com/wiki/Barrier), [Squad](https://wiki.guildwars2.com/wiki/Squad), [Party](https://wiki.guildwars2.com/wiki/Party).
- GuildWars2.com: [Introducing Enhanced Squad UI](https://www.guildwars2.com/en/news/introducing-enhanced-squad-ui/) and [Enhanced Squad UI Features on Guild Chat](https://www.guildwars2.com/en/news/enhanced-squad-ui-features-on-guild-chat-a-summary/) for squad/subgroup behavior.
- Guild Wars 2 forum thread on Healing Stats: [Peers outgoing requires stat sharing from both sides](https://en-forum.guildwars2.com/topic/135096-anyone-familiar-with-arcdps-healing-stats-extension/).
- Vietnamese public game-writing examples support `kỹ năng`, `hồi máu`, `sát thương`, `buff`, `class`, and loanword-heavy UI when no official locale exists: [GameK MU article](https://gamek.vn/kham-pha-magic-gladiator-bieu-tuong-suc-manh-cua-mu-luc-dia-vng-17825052321014702.chn), [BunnyForever GW2 Elementalist translation](https://bunnyforever.wordpress.com/category/video-games/page/3/), and [Download.com.vn MistBound/Guild Wars article](https://download.com.vn/mistbound-cho-android-204064).

## Direct Fixes

- `5_name`: `Stats thành viên squad` -> `Stats từ thành viên squad`
- `6_name`: `Barrier thành viên squad` -> `Barrier từ thành viên squad`
- `[enum_data_source] peers_outgoing`: `stats thành viên squad` -> `stats từ thành viên squad`

These are minimal source/actor clarifications. They preserve the original loanword-heavy style while making clear that the stats come from other squad members through live stats sharing.

## Review Findings

- `Peers outgoing` now uses `từ thành viên squad`, avoiding any reading like a shared-healing mechanic or healing applied to squad members.
- `Live stats sharing` remains `chia sẻ stats live` only where the addon feature itself is described.
- `Hits` remains `tick`, which is safer than a Vietnamese weapon-hit wording because the addon counts healing/barrier event ticks.
- `Barrier generation` keeps `barrier` and `tạo barrier`, avoiding generic `khiên`, `chặn`, or shield/block wording.
- `From Damage Dealt` is `Từ sát thương gây ra`, a source/aggregate label rather than a skill name.
- `Group`, `Squad`, and `subgroup` are kept as `nhóm`, `Squad`/`squad`, and `subgroup`. This keeps the party/squad distinction visible without inventing official Vietnamese GW2 terminology.
- Skill, profession, and elite specialization names are not present as concrete names. Generic `kỹ năng` is localized, while `profession` remains an English GW2 class-token in compact option labels.

## Verification

Command run:

```powershell
python localization\tools\verify_healing_stats_locale.py --targets ja th vi --strict-newlines
```

Result for `vi`: `PASS`.

Warnings reviewed as intentional:

- `[default_windows] 0_entry_format` unchanged from English because it is only placeholders and `/s` formatting.
- `[group_filter] squad` remains English as a GW2/MMO loanword.

## Remaining Uncertainty

- No official Vietnamese GW2 localization was found. The draft therefore keeps common MMO/UI loanwords such as `stats`, `squad`, `subgroup`, `profession`, `tick`, `cast`, and `barrier` where they are closer to source and public community usage than invented official-sounding terms.
- `nhóm` is used for the group/subgroup context where a compact Vietnamese label is needed; `subgroup` is kept in color options because that is closer to the GW2 squad UI term.
