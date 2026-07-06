# arcdps Healing Stats KOR

길드워2 arcdps 치유 통계 애드온
[Krappa322/arcdps_healing_stats](https://github.com/Krappa322/arcdps_healing_stats)의
비공식 한국어 빌드입니다.

이 저장소는 한국어 사용자를 위한 배포용 fork입니다. 원본 제작자의 공식 한국어판은 아닙니다.

## 다운로드

최신 파일은 [Releases](../../releases)에서 받을 수 있습니다.

받을 파일:

```text
Healing_Stats.dll
Healing_Stats.ko.ini
```

## 설치

1. [ArcDPS](https://www.deltaconnected.com/arcdps/)를 먼저 설치합니다.
2. `Healing_Stats.dll`을 사용하는 설치 방식에 맞게 넣습니다.
3. `Healing_Stats.ko.ini`는 항상 아래 위치에 넣습니다.

```text
길드워2 설치 폴더\addons\arcdps\Healing_Stats.ko.ini
```

ini 파일이 없으면 애드온은 원본 영어 UI로 표시됩니다.

4. 길드워2를 실행한 뒤 arcdps 메뉴에서 `치유 통계` 창을 켭니다.

## 한국어화 범위

- UI 메뉴, 옵션, 도움말, 기본 창 이름을 `Healing_Stats.ko.ini`로 한국어화했습니다.
- 스킬명, 직업명, 전문화명 같은 길드워2 고유명사는 번역하지 않았습니다.
- `Peers outgoing` 기본 창은 실제 표시 내용에 맞춰 `스쿼드원별 치유량`으로 표기했습니다.
- 배리어 전용 기본 창은 `스쿼드원별 배리어량`으로 표기했습니다.
- 기존 설정 파일에 저장된 예전 기본 창 이름은 실행 시 새 이름으로 자동 보정합니다.

## 기본 창 이름

| 번호 | 이름 |
|---:|---|
| 0 | 합계 |
| 1 | 대상별 |
| 2 | 스킬별 |
| 3 | 대상별 (틱) |
| 4 | 스킬별 (틱) |
| 5 | 스쿼드원별 치유량 |
| 6 | 스쿼드원별 배리어량 |
| 7 | 사용자 창 |
| 8 | 사용자 창 |
| 9 | 통합 보기 |

## 주요 용어

| 원문 | 한국어 |
|---|---|
| Data source | 데이터 소스 |
| Peers outgoing | 스쿼드원별 |
| Outgoing healing | 치유량 |
| Barrier generation | 배리어량 |
| Hits | 틱 수 |
| Healing per hit | 치유/틱 |
| Barrier generation per hit | 배리어/틱 |
| Live stats sharing | 실시간 통계 공유 |
| Unmapped | 미확인 대상 |
| From Damage Dealt | 피해 기반 치유 |

## 기능 요약

이 애드온은 arcdps가 제공하는 로컬 치유 이벤트를 기반으로 자신의 치유량을 집계합니다.

볼 수 있는 정보:

- 대상별 치유량
- 스킬별 치유량
- 합계 치유량
- 배리어량
- 틱 수 기준 통계
- 실시간 통계 공유를 켠 스쿼드원의 치유 통계

실시간 통계 공유는 같은 스쿼드 안에서 이 애드온을 사용하고 공유 기능을 켠 플레이어끼리만 동작합니다.
길드워2 서버가 모든 플레이어의 치유량을 직접 알려주는 구조가 아니기 때문에, 애드온을 설치하지 않은
플레이어의 치유량을 자동으로 볼 수는 없습니다.

## 주의

- 이 빌드는 비공식 한국어 빌드입니다.
- 애드온 사용은 각자 책임하에 진행해야 합니다.
- 번역 문제나 한국어 UI 개선 요청은 이 저장소의 Issues에 남겨 주세요.
- 원본 애드온 자체의 기능 버그는 가능하면 원본 저장소도 함께 확인해 주세요.

## 원본 및 라이선스

원본 프로젝트:

[Krappa322/arcdps_healing_stats](https://github.com/Krappa322/arcdps_healing_stats)

이 프로젝트는 원본과 동일하게 MIT License를 따릅니다. 자세한 내용은 [LICENSE](./LICENSE)를 확인해 주세요.

원본 프로젝트에서 사용하는 주요 서드파티 라이브러리:

- arcdps-extension
- Dear ImGui
- GoogleTest
- gRPC
- JSON for Modern C++
- Prometheus Client Library for Modern C++
- Protocol Buffers
- simpleini
- spdlog

각 라이브러리의 자세한 라이선스 정보는 원본 저장소와 각 라이브러리 문서를 확인해 주세요.
