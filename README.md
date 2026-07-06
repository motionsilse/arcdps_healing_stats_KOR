# arcdps Healing Stats Multilingual Pack

## English

This is an unofficial multilingual localization build of
[Krappa322/arcdps_healing_stats](https://github.com/Krappa322/arcdps_healing_stats)
for Guild Wars 2 arcdps.

It localizes the addon's UI, options, tooltips, and default window names. Skill
names, profession names, and elite specialization names are kept in English for
clarity and consistency with the game and logs.

This is not an official build from the original author.

### Download

Download the latest ZIP from [Releases](../../releases).

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

### Install

`Healing_Stats.dll` and the `.ini` files do not use the same placement rule.

- `Healing_Stats.dll`: install it using the same location or method you normally use for arcdps Healing Stats.
- `Healing_Stats.locale.ini` and `Healing_Stats.<language>.ini`: put only these localization `.ini` files in:

```text
Guild Wars 2\addons\arcdps\
```

### Language Setting

The default language is Korean:

```ini
[localization]
language=ko
```

To change the language, edit:

```text
Guild Wars 2\addons\arcdps\Healing_Stats.locale.ini
```

Supported language codes:

```text
ko  Korean
en  English, built-in original UI
de  German
es  Spanish
fil Filipino
fr  French
id  Indonesian
ja  Japanese
ms  Malay
pl  Polish
pt  Portuguese
ru  Russian
th  Thai
tr  Turkish
vi  Vietnamese
```

Use `language=en` to use the addon's original built-in English UI. No
`Healing_Stats.en.ini` file is needed.

If `Healing_Stats.locale.ini` is missing, the addon tries `Healing_Stats.ko.ini`
for compatibility with the earlier Korean build. If no localization file is
found, it falls back to English.

### Translation Policy

- Skill, profession, and elite specialization names are not translated.
- The translations stay close to the original English meaning.
- UI text is localized only where it helps target-language users understand the addon.
- Chinese are intentionally not included in this release because existing community translations are already available.

### Review Status

The multilingual files were checked with public Guild Wars 2/MMORPG terminology
sources and structural verification. They are conservative reviewed drafts, not
official translations.

### Original Project and License

Original project:

[Krappa322/arcdps_healing_stats](https://github.com/Krappa322/arcdps_healing_stats)

This project follows the original MIT License. See [LICENSE](./LICENSE).

### Related Project

[Arcdps-Translations](https://github.com/motionsilse/Arcdps-Translations) is a
multilingual pack for the main arcdps addon, including font files.

## 한국어

이 저장소는 Guild Wars 2 arcdps용
[Krappa322/arcdps_healing_stats](https://github.com/Krappa322/arcdps_healing_stats)를
기반으로 만든 비공식 다국어 현지화 빌드입니다.

애드온의 UI, 옵션, 툴팁, 기본 창 이름을 현지화합니다. 스킬명, 직업명,
엘리트 전문화명은 게임과 로그에서의 명확성과 일관성을 위해 영어로 유지합니다.

원 제작자의 공식 빌드가 아닙니다.

### 다운로드

최신 ZIP 파일은 [Releases](../../releases)에서 받을 수 있습니다.

ZIP 파일 구성:

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

### 설치

`Healing_Stats.dll`과 `.ini` 파일은 설치 규칙이 다릅니다.

- `Healing_Stats.dll`: 기존 arcdps Healing Stats DLL을 설치하던 위치나 방식대로 설치합니다.
- `Healing_Stats.locale.ini`와 `Healing_Stats.<language>.ini`: 이 현지화 `.ini` 파일들만 아래 폴더에 넣습니다.

```text
Guild Wars 2\addons\arcdps\
```

### 언어 설정

기본 언어는 한국어입니다.

```ini
[localization]
language=ko
```

언어를 바꾸려면 아래 파일을 수정합니다.

```text
Guild Wars 2\addons\arcdps\Healing_Stats.locale.ini
```

지원 언어 코드:

```text
ko  한국어
en  영어, 애드온 내장 원문 UI
de  독일어
es  스페인어
fil 필리핀어
fr  프랑스어
id  인도네시아어
ja  일본어
ms  말레이어
pl  폴란드어
pt  포르투갈어
ru  러시아어
th  태국어
tr  튀르키예어
vi  베트남어
```

`language=en`으로 설정하면 애드온에 내장된 영어 원문 UI를 사용합니다.
`Healing_Stats.en.ini` 파일은 필요하지 않습니다.

`Healing_Stats.locale.ini`가 없으면 기존 한국어판과의 호환성을 위해
`Healing_Stats.ko.ini`를 먼저 찾습니다. 현지화 파일을 찾지 못하면 영어로 표시됩니다.

### 번역 기준

- 스킬명, 직업명, 엘리트 전문화명은 번역하지 않습니다.
- 번역은 영어 원문의 의미를 최대한 해치지 않는 방향으로 유지합니다.
- 대상 언어 사용자가 애드온을 이해하는 데 필요한 UI 문구만 현지화합니다.
- 기존의 커뮤니티 번역이 이미 존재하므로, 이번 릴리스에는 중국어가 의도적으로 포함되지 않았습니다.

### 검수 상태

다국어 파일은 공개 Guild Wars 2/MMORPG 용어 자료와 구조 검증을 기준으로 확인했습니다.
공식 번역이 아니라 보수적으로 검수한 초안입니다.

### 원본 프로젝트와 라이선스

원본 프로젝트:

[Krappa322/arcdps_healing_stats](https://github.com/Krappa322/arcdps_healing_stats)

이 프로젝트는 원본과 같은 MIT License를 따릅니다. 자세한 내용은 [LICENSE](./LICENSE)를 확인하세요.

### 관련 프로젝트

[Arcdps-Translations](https://github.com/motionsilse/Arcdps-Translations)는
arcdps 다국어팩(폰트 포함)입니다.
