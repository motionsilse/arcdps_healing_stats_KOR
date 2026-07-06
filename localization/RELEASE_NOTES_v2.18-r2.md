# Healing Stats Multilingual Pack v2.18-r2

Unofficial multilingual localization build for Guild Wars 2 arcdps Healing Stats.

길드워2 arcdps Healing Stats용 비공식 다국어 로컬라이징 빌드입니다.

## Download / 다운로드

Download the ZIP file from this release.

이 릴리즈의 ZIP 파일을 받으세요.

```text
Healing_Stats_multilingual_v2.18-r2.zip
```

## Included / 포함 파일

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

## Language Setting / 언어 설정

Default language is Korean.

기본 언어는 한국어입니다.

```ini
[localization]
language=ko
```

To change the language, edit:

언어를 바꾸려면 아래 파일을 수정하세요.

```text
Guild Wars 2\addons\arcdps\Healing_Stats.locale.ini
```

Supported codes:

지원 코드:

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

Use `language=en` to use the original built-in English UI. No English INI file is needed.

`language=en`으로 설정하면 애드온에 내장된 영어 원문 UI를 사용합니다. 영어 INI 파일은 필요 없습니다.

## Notes / 참고

- Skill, profession, and elite specialization names are kept in English.
- Translations are conservative and stay close to the original English meaning.
- `Peers outgoing` means outgoing stats from other squad members through live stats sharing. It is not a shared-healing combat mechanic.
- This is an unofficial localization build and not an official build from the original author.

한국어:

- 스킬명, 직업명, 전문화명은 영어 원문을 유지합니다.
- 번역은 원문 의미를 최대한 유지하는 방향으로 작업했습니다.
- `Peers outgoing`은 실시간 통계 공유를 통해 받은 스쿼드원의 outgoing 통계입니다. 공유 치유 같은 전투 메커니즘이 아닙니다.
- 원작자의 공식 빌드가 아닌 비공식 로컬라이징 빌드입니다.

## Verification / 검증

- All non-Korean multilingual INI files passed strict key, placeholder, and escaped-newline verification.
- Korean plus all multilingual INI files passed key and placeholder verification.

한국어:

- 한국어 외 다국어 INI 파일은 key, placeholder, escaped newline strict 검증을 통과했습니다.
- 한국어와 모든 다국어 INI 파일은 key와 placeholder 검증을 통과했습니다.
