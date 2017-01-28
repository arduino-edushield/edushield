#	Sériová komunikace

## Kód
[SerialCommunication.ino](../../../../examples/SerialCommunication/SerialCommunication.ino)

## Motivace a cíle

  - Využití sériové komunikace via UART pro ladění programu.
  - Vysvětlit princip sériové komunikace

## Teorie
  - RS232 https://cs.wikipedia.org/wiki/RS-232 
  - Arduino IDE Serial Monitor
  - Převodník USB-Serial
    - 5 V vs 3,3 V
  - AT příkazy
    - Bluetooth modul
  - HW serial port na Arduino
    - Arduino Mega
  - SW serial port na Arduino

##	Použité funkce
  - [Serial](https://www.arduino.cc/en/Reference/Serial)
  
## Zapojení

---
 
## Cvičení
  - Ovládejte LED pomocí příkazů poslaných přes sériovou linku.
  - Vyzkoušejte, co se stane, když nejsou na obou stranách nastaveny stejné rychlosti.



## Pro lektora
  - Místo readString() použijte jen read()
