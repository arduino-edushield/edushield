#	Hodiny reálného času

## Kód
[Clock.ino](../../../../examples/Clock/Clock.ino)
[RealTimeClock.ino](../../../../examples/RealTimeClock/RealTimeClock.ino)

## Motivace a cíle

  Ukázka praktické aplikace. Práce s RTC. Práce s knihovnami. Nahrazení knihovních funkcí low-level přístupem k zařízení. Výpis hodnot do počítače přes UART.

## Teorie
  - Instalace knihovny pomocí správce knihoven
  - Práce s katalogovým listem http://datasheets.maximintegrated.com/en/ds/DS1307.pdf 
  - BCD kódování https://cs.wikipedia.org/wiki/BCD
  - Rozhraní I2C na aplikační úrovni http://www.nxp.com/documents/user_manual/UM10204.pdf

![Registry DS1307](img/ds1307.png)

##	Použité funkce
  - knihovna Wire
  
## Cvičení
  - Zobrazit minuty a sekundy
  - Zobrazit kompletní datum a čas na sériovou konzoli.

## Pro lektora
  - Referenční napětí je 5 V, převodník je 10-bit, tedy 0-1023.
  - Díky napěťovému děliči určité hranice nemusejí mít vliv. Citlivost obecně závisí na použitém rezistoru připojeného na zem.
  - Je třeba najít mez citlivosti.

  ## Prerekvizity

  1. [Sériová komunikace](serial.md)
  1. [Displej](displej.md)
