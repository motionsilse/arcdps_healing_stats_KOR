# Turkish Healing Stats expert review

Status: conservatively_reviewed_draft

## Scope

- Reviewed draft: `localization/drafts/tr/Healing_Stats.tr.ini`
- Source: `localization/canonical/Healing_Stats.en.ini`
- Existing report considered: `localization/reports/tr_review.md`
- Scope limited to Turkish (`tr`) Healing Stats strings. No packaging, upload, push, GitHub use, or unrelated language edits.

## Verification

Command:

```powershell
python localization\tools\verify_healing_stats_locale.py --root . --targets pl ru tr --strict-newlines
```

Result for `tr`: PASS.

Expected warnings: `[group_filter] squad` and `[addon_options] title` are unchanged from English. Both are intentional: `Squad` is a GW2/MMO UI loanword, and `Heal Stats` is the addon menu/product label.

## Public evidence used

- Guild Wars 2 Wiki, Barrier: https://wiki.guildwars2.com/wiki/Barrier
- Guild Wars 2 Wiki, Healing: https://wiki.guildwars2.com/wiki/Healing
- Guild Wars 2 Wiki, Squad: https://wiki.guildwars2.com/wiki/Squad
- Hardstuck 10-player squad composition guide, for squad/subgroup/healer role context: https://hardstuck.gg/gw2/guides/strike-missions/10-player-pve-squad-composition-guide/
- Steam Community GW2 chat-command guide, for public `/squad` and `/subgroup` command context: https://steamcommunity.com/sharedfiles/filedetails/?id=2853513842
- Public Turkish GW2 guide title evidence retaining `Squad` in UI context: https://www.youtube.com/watch?v=rzM1YtQ1VSM

## Expert decisions

- `Peers outgoing`: kept as `Squad üyeleri` / `Squad üyeleri: iyileştirme`. This prevents a misleading shared-healing reading while staying close to source and common Turkish MMO loanword usage.
- `Live stats sharing`: kept as `canlı istatistik paylaşımı`, used only for the addon network-sharing feature.
- `Hits`: kept as `tik` / `tikler`, matching event ticks rather than weapon hits.
- `Barrier generation`: kept as `bariyer üretimi` / `bariyer`, preserving the GW2 barrier mechanic and avoiding shield/block wording.
- `From Damage Dealt`: `Verilen hasardan` correctly reads as an aggregate/pseudo entry, not a skill name.
- `Group` / `Squad`: `Grup` / `Squad` stays close to source and matches Turkish MMO/UI loanword expectations better than inventing a formal localized squad label.
- `Cast`, `peer`, `Heal Stats`, `EVTC`, `RPC`, `TLS`, `kiB/s`, `evtc_rpc`, and `Guild Wars 2` remain technical/product tokens where they are closer to source and recognizable.
- Skill, profession, and elite specialization names do not appear as concrete translatable entries; the generic UI label `profession` remains translated as `sınıf`.

## Fixes applied

No Turkish draft changes were necessary in this pass.

## Remaining uncertainty

There is no official Turkish Guild Wars 2 localization source. The draft therefore keeps Turkish for clear UI meaning (`iyileştirme`, `bariyer`, `veri kaynağı`) and retains common technical loanwords where translating them would be more likely to mislead arcdps/GW2 users.
