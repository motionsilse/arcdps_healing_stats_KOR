# arcdps Healing Stats Multilingual Pack

Unofficial multilingual localization build of
[Krappa322/arcdps_healing_stats](https://github.com/Krappa322/arcdps_healing_stats)
for Guild Wars 2 arcdps.

This is not an official build from the original author. It keeps skill names,
profession names, and elite specialization names in English, while localizing
the addon's UI, options, tooltips, and default window names.

한국어:

[Krappa322/arcdps_healing_stats](https://github.com/Krappa322/arcdps_healing_stats)를
기반으로 만든 길드워2 arcdps 치유 통계 애드온의 비공식 다국어 로컬라이징 빌드입니다.

원작자의 공식 빌드가 아닙니다. 스킬명, 직업명, 전문화명은 영어 원문을 유지하고,
애드온의 UI, 옵션, 도움말, 기본 창 이름만 로컬라이징합니다.

## Download / 다운로드

Download the latest ZIP from [Releases](../../releases).

최신 ZIP 파일은 [Releases](../../releases)에서 받을 수 있습니다.

The ZIP contains:

```text
Healing_Stats.dll
Healing_Stats.locale.ini
Healing_Stats.ko.ini
Healing_Stats.de.ini
Healing_Stats.es.ini
Healing_Stats.fil.ini
Healing_Stats.fr.ini
Healing_Stats.id.ini
Healing_Stats.ja.ini
Healing_Stats.ms.ini
Healing_Stats.pl.ini
Healing_Stats.pt.ini
Healing_Stats.ru.ini
Healing_Stats.th.ini
Healing_Stats.tr.ini
Healing_Stats.vi.ini
README.md
```

## Install / 설치

1. Install [ArcDPS](https://www.deltaconnected.com/arcdps/) first.
2. Install `Healing_Stats.dll` the same way you normally install arcdps Healing Stats.
3. Put `Healing_Stats.locale.ini` and the language INI files in:

```text
Guild Wars 2\addons\arcdps\
```

한국어:

1. [ArcDPS](https://www.deltaconnected.com/arcdps/)를 먼저 설치합니다.
2. `Healing_Stats.dll`은 arcdps Healing Stats를 설치하는 방식대로 넣습니다.
3. `Healing_Stats.locale.ini`와 언어 INI 파일들은 아래 위치에 넣습니다.

```text
길드워2 설치 폴더\addons\arcdps\
```

## Language Setting / 언어 설정

The default language is Korean:

기본 언어는 한국어입니다.

```ini
[localization]
language=ko
```

To change the language, edit:

언어를 바꾸려면 아래 파일을 수정합니다.

```text
Guild Wars 2\addons\arcdps\Healing_Stats.locale.ini
```

Set `language=` to one of these codes:

`language=` 값을 아래 코드 중 하나로 바꿉니다.

```text
ko  Korean / 한국어
de  German / 독일어
es  Spanish / 스페인어
fil Filipino / 필리핀어
fr  French / 프랑스어
id  Indonesian / 인도네시아어
ja  Japanese / 일본어
ms  Malay / 말레이어
pl  Polish / 폴란드어
pt  Portuguese / 포르투갈어
ru  Russian / 러시아어
th  Thai / 태국어
tr  Turkish / 터키어
vi  Vietnamese / 베트남어
```

Use `language=en` to use the addon's original built-in English UI. No
`Healing_Stats.en.ini` file is needed.

`language=en`으로 설정하면 애드온에 내장된 원문 영어 UI를 사용합니다.
`Healing_Stats.en.ini` 파일은 필요 없습니다.

If `Healing_Stats.locale.ini` is missing, the addon tries `Healing_Stats.ko.ini`
for compatibility with the earlier Korean build. If no localization file is
found, it falls back to English.

`Healing_Stats.locale.ini`가 없으면 기존 한국어판과의 호환을 위해
`Healing_Stats.ko.ini`를 먼저 찾습니다. 로컬라이징 파일이 없으면 영어 UI로 표시됩니다.

## Translation Policy / 번역 기준

- Skill, profession, and elite specialization names are not translated.
- The translations stay close to the original English meaning.
- UI text is localized only enough to avoid target-language misunderstanding.
- `Peers outgoing` means outgoing stats from other squad members through live
  stats sharing. It is not a Guild Wars 2 shared-healing mechanic.
- `Hits` means healing/barrier event ticks in this addon context.
- `From Damage Dealt` is an aggregate/pseudo entry, not a skill name.

한국어:

- 스킬명, 직업명, 전문화명은 번역하지 않습니다.
- 번역은 원문 의미를 최대한 유지하는 방향으로 작업했습니다.
- 대상 언어 사용자에게 오해가 생기는 부분만 필요한 만큼 로컬라이징했습니다.
- `Peers outgoing`은 실시간 통계 공유를 통해 받은 스쿼드원의 outgoing 통계입니다.
  길드워2의 공유 치유 같은 전투 메커니즘이 아닙니다.
- `Hits`는 이 애드온 맥락에서 치유/배리어 이벤트 틱을 뜻합니다.
- `From Damage Dealt`는 집계용 가상 항목이며 스킬명이 아닙니다.

## Review Status / 검토 상태

The multilingual files were checked with public Guild Wars 2/MMORPG terminology
sources and strict structural verification. They are conservative reviewed
drafts, not official translations.

다국어 파일은 공개 길드워2/MMORPG 용어 자료와 구조 검증을 기준으로 보수적으로 검토했습니다.
공식 번역은 아닙니다.

## Original Project and License / 원본 및 라이선스

Original project:

[Krappa322/arcdps_healing_stats](https://github.com/Krappa322/arcdps_healing_stats)

This project follows the original MIT License. See [LICENSE](./LICENSE).

원본 프로젝트와 동일하게 MIT License를 따릅니다. 자세한 내용은 [LICENSE](./LICENSE)를 확인해 주세요.
