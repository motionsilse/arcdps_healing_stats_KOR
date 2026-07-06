# Polish Healing Stats expert review

Status: conservatively_reviewed_draft

## Scope

- Reviewed draft: `localization/drafts/pl/Healing_Stats.pl.ini`
- Source: `localization/canonical/Healing_Stats.en.ini`
- Existing report considered: `localization/reports/pl_review.md`
- Scope limited to Polish (`pl`) Healing Stats strings. No packaging, upload, push, GitHub use, or unrelated language edits.

## Verification

Command:

```powershell
python localization\tools\verify_healing_stats_locale.py --root . --targets pl ru tr --strict-newlines
```

Result for `pl`: PASS.

Expected warning: `[default_windows] 0_entry_format` is unchanged from English because it is a placeholder/numeric format string: `{1} ({4}/s)`.

## Public evidence used

- Guild Wars 2 Wiki, Barrier: https://wiki.guildwars2.com/wiki/Barrier
- Guild Wars 2 Wiki, Healing: https://wiki.guildwars2.com/wiki/Healing
- Guild Wars 2 Wiki, Squad: https://wiki.guildwars2.com/wiki/Squad
- Hardstuck 10-player squad composition guide, for squad/subgroup/healer context: https://hardstuck.gg/gw2/guides/strike-missions/10-player-pve-squad-composition-guide/
- Steam Community GW2 chat-command guide, for public `/squad` and `/subgroup` command context: https://steamcommunity.com/sharedfiles/filedetails/?id=2853513842

## Expert decisions

- `Peers outgoing`: kept as `Inni ze składu` / `Inni ze składu: leczenie`. This stays close to the current draft and describes other squad-member data without implying a GW2 shared-healing mechanic.
- `Live stats sharing`: kept as `udostępnianie statystyk na żywo`, used only for the addon network-sharing feature.
- `Hits`: kept as `tiki` / `/tik`, matching event ticks rather than weapon hits.
- `Barrier generation`: kept as `bariera` / `generowanie bariery`, matching the GW2 barrier mechanic and avoiding shield/block/protection wording.
- `From Damage Dealt`: `Z zadanych obrażeń` correctly reads as an aggregate/pseudo entry, not a skill name.
- `Group` / `Squad`: `Podgrupa` / `Skład` preserves the subgroup-versus-squad distinction. Public Polish GW2-specific terminology is thin, so I did not replace these with more inventive terms.
- Skill, profession, and elite specialization names do not appear as concrete translatable entries; the generic UI label `profession` remains translated as `profesja`.

## Fixes applied

No Polish draft changes were necessary in this pass.

## Remaining uncertainty

There is no official Polish Guild Wars 2 localization source to settle every UI convention. The draft therefore stays conservative: established Polish UI/MMO wording where clear, technical loanwords where closer to source, and no invented official-sounding profession/skill terminology.
