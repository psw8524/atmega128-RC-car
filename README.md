# ATmega128_RC_Car
Atmega128을 이용하여 (면허인증시스템 + 음주 측정) 기능을 추가한 rc카 프로젝트입니다.

Microchip Studio와 AVR 명령어를 사용하여 레지스터 레벨의 제어과정을 가져보았습니다.

## STEP 1
RFID 모듈(MFRC522) 인증

1. 1번 스위치를 누르면 Card Key를 Rfid 모듈에 접근하여 인식 시도
2. 인증 성공 시, LCD에 PASS 문자열 출력 + Buzzer 경고음 1회 출력(== 성공 출력)후 다음 STEP으로 통과
3. 인증 실패 시, LCD에 FAIL 문자열 출력 및 다음 STEP으로 넘어가지 못함

## STEP 2
알콜 센서(MQ-3) 인증

1. 1번 스위치를 누르면 알콜 센서가 실시간으로 Alcohol Value 측정하여 LCD에 출력
2. 5초 동안 기준치 이상일 시, 1번 스위치를 다음 STEP 불가 + Buzzer 경고음(알콜 감지)
3. 5초 동안 기준치 미만일 시, 다음 STEP으로 통과 + Buzzer 경고음(성공 알림)

## STEP 3
주행 모드

1. 1번 스위치를 누르면 수동 주행 시작(블루투스를 이용한 수동 조작)
2. 2번 스위치를 누르면 자율 주행 시작(좌, 우, 앞 거리 LCD에 실시간 출력)
3. 자율 주행 중 블루투스로 정지 요청 시, 주행 정지 후 수동 모드로 전환

+ 조도센서(CDS)와 차량속도를 활용하여 LED 자동제어



사용한 언어 : ![js](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

(동작 영상) ![js](https://img.shields.io/badge/YouTube-FF0000?style=for-the-badge&logo=youtube&logoColor=white) : 

https://youtube.com/shorts/O6VX6wx52OQ?feature=share

https://youtube.com/shorts/kGUxyn3i6-o?feature=share

https://youtube.com/shorts/azf6NibLsJs?feature=share
