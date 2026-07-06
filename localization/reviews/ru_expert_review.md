# Russian Healing Stats expert review

Status: conservatively_reviewed_draft

## Scope

- Reviewed draft: `localization/drafts/ru/Healing_Stats.ru.ini`
- Source: `localization/canonical/Healing_Stats.en.ini`
- Existing report considered: `localization/reports/ru_review.md`
- Scope limited to Russian (`ru`) Healing Stats strings. No packaging, upload, push, GitHub use, or unrelated language edits.

## Verification

Command:

```powershell
python localization\tools\verify_healing_stats_locale.py --root . --targets pl ru tr --strict-newlines
```

Result for `ru`: PASS.

## Public evidence used

- Russian GW2 wiki, Barrier: https://wiki.guildwars-2.ru/Barrier
- Russian GW2 wiki, Well of Blood, for `исцеление` and per-tick/tact healing language: https://wiki.guildwars-2.ru/Well_of_Blood
- Russian GW2 wiki, 2015 squad UI update, for `отряд` and `подгруппа`: https://wiki.guildwars-2.ru/Обновления_игры/2015-11-17
- ru.gw2skills Barrier page, current public Russian GW2 build-data terminology: https://ru.gw2skills.net/wiki/misc/barrier/
- Hardstuck 10-player squad composition guide, for current squad/subgroup/healer role context: https://hardstuck.gg/gw2/guides/strike-missions/10-player-pve-squad-composition-guide/

## Expert decisions

- `Peers outgoing`: kept as `Исх. хил отряда` / `исх. хил отряда`. It is compact, close to source, and points to squad-member outgoing healing data rather than a named shared-healing mechanic.
- `Live stats sharing`: kept as `live-обмен` / `live-обмен статистикой` in the main UI. This distinguishes addon data transport from combat healing mechanics.
- `Hits`: kept as `тики` / `/тик`. Russian GW2 wiki evidence uses `такт` for periodic healing, but `тик` is the closer parser/MMO loanword for event ticks and avoids weapon-hit wording.
- `Barrier generation`: kept as `барьер`; Russian public GW2 sources consistently use `Барьер` for the mechanic.
- `From Damage Dealt`: `От нанесенного урона` correctly reads as an aggregate/pseudo entry, not a skill name.
- `Group` / `Squad`: `Подгруппа` / `Отряд` are backed by Russian GW2 wiki squad UI/update wording.
- Skill, profession, and elite specialization names do not appear as concrete translatable entries; the generic UI label `profession` remains translated as `профессия`.

## Fixes applied

- Changed `[details] total_barrier_generation` from `всего барьер` to `всего барьера` for correct compact Russian grammar while preserving the source meaning.

## Remaining uncertainty

There is no official Russian Guild Wars 2 localization source. The draft intentionally mixes formal GW2 evidence-backed terms (`барьер`, `исцеление`, `отряд`, `подгруппа`) with common compact MMO/parser loanwords (`хил`, `тик`, `каст`) where those stay closer to arcdps overlay usage.
