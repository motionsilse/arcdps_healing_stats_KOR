# Japanese Healing Stats Expert Review

Status: `conservatively_reviewed_draft`

## Scope

- Reviewed `localization/drafts/ja/Healing_Stats.ja.ini` against `localization/canonical/Healing_Stats.en.ini`.
- Used `localization/EXPERT_REVIEW_STANDARD.md`, `localization/SOURCE_NOTES.md`, `localization/AGENT_BRIEF.md`, and `localization/reports/ja_review.md`.
- No GitHub, upload, push, packaging, or release artifact work was performed.
- No edits were required in the Japanese draft during this pass.

## Public Evidence Used

- Guild Wars 2 Wiki: [Healing](https://wiki.guildwars2.com/wiki/Healing), [Barrier](https://wiki.guildwars2.com/wiki/Barrier), [Squad](https://wiki.guildwars2.com/wiki/Squad), [Party](https://wiki.guildwars2.com/wiki/Party).
- GuildWars2.com: [Introducing Enhanced Squad UI](https://www.guildwars2.com/en/news/introducing-enhanced-squad-ui/) and [Enhanced Squad UI Features on Guild Chat](https://www.guildwars2.com/en/news/enhanced-squad-ui-features-on-guild-chat-a-summary/) for squad/subgroup behavior.
- Guild Wars 2 forum thread on Healing Stats: [Peers outgoing requires stat sharing from both sides](https://en-forum.guildwars2.com/topic/135096-anyone-familiar-with-arcdps-healing-stats-extension/).
- Japanese game terminology references: [Game8 DoT/HoT explanation](https://game8.jp/ff14/290852) and [GameMakers Tick glossary](https://gamemakers.jp/glossary/tick/).

## Review Findings

- `Peers outgoing` is rendered as `メンバー別回復` / `メンバー別`. This stays away from `共有` in compact labels and does not imply a GW2 shared-healing mechanic. `共有` is used only where the addon feature itself, live stats sharing, is described.
- `Hits` is consistently `ティック`, matching the addon meaning of healing/barrier event ticks rather than weapon hits.
- `Barrier generation` uses `バリア生成`, preserving the GW2 barrier mechanic and avoiding shield/block/protection wording.
- `From Damage Dealt` is `与ダメージ由来`, which reads as an aggregate/source label rather than a skill name.
- `Group` / `Squad` are kept distinct as `サブグループ` / `スクワッド`, aligned with GW2 squad/subgroup organization.
- Skill, profession, and elite specialization names do not appear as concrete names in the canonical strings. Generic UI labels such as `スキル` and `職業` are acceptable.

## Verification

Command run:

```powershell
python localization\tools\verify_healing_stats_locale.py --targets ja th vi --strict-newlines
```

Result for `ja`: `PASS`.

Warning reviewed as intentional:

- `[default_windows] 0_entry_format` unchanged from English because it is only placeholders and `/s` formatting.

## Remaining Uncertainty

- `メンバー別` is intentionally compact. `スクワッドメンバー別` would be more explicit but longer; the current wording is acceptable because the tooltip and disabled-message strings explain live stats sharing.
- Japanese GW2 has no official locale to anchor every UI convention. Loanwords such as `スクワッド`, `ティック`, `キャスト`, and `バリア` are conservative MMO-style choices.
