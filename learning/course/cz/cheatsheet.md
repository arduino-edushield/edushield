# EduShield

## Digitální piny

| Pin | Funkce   |
| --- | --- |
| 2   | Tlačítko |
| 3   | RTC SQW out |
| 4   | --- |
| 5   | RGB LED: G |
| 6   | RGB LED: B |
| 7   | --- |
| 8   | --- |
| 9   | RGB LED: R |
| 10   | --- |
| 11   | --- |
| 12   | --- |
| 13 | Semafor: zelená |
| 14 | -- |
| 15 | -- |
| 16 | Semafor: červená |
| 17 | Semafor: oranžová |
| 18 | I2C SDA |
| 19 | I2C SCK |


## Analogové vstupy

| Pin | Funkce   |
| --- | --- |
| A1  | fotorezistor |
| A2  | termistor |

## Funkční bloky

### LED semafor
  Piny 13 (zelená), 16 (červená), 17 (oranžová)

### RGB LED  
  Piny 5 (G - zelená), 6 (B - modrá), 9 (R - červená)

  Možno pustit PWM

### Tlačítko
  Pin 2
  
  Nastavit jako INPUT PULLUP  

## Displej
  I2C slave 0x27
  
  Protokol: vždy se přenáší 2 byty, první udává pozici, druhý segmenty

## RTC
  I2C slave device 0x68


![EduShield](../../../docs/edushield.jpg)

![Schéma](../../../docs/ATtiny+display.jpg)
