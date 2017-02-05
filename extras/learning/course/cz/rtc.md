#	Hodiny reálného času

## Kód
[Clock.ino](../../../../examples/Clock/Clock.ino)
[RealTimeClock.ino](../../../../examples/RealTimeClock/RealTimeClock.ino)

## Motivace a cíle

  Ukázka praktické aplikace. Práce s RTC. Práce s knihovnami. Nahrazení knihovních funkcí low-level přístupem k zařízení. Výpis hodnot do počítače přes UART.

## Teorie
  - Instalace knihovny pomocí správce knihoven, otestovaná je *RTC by Makuna*
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
  - Knihovny hledáme podle typu (kódu) součástky ne podle výrobce
  - Zkontrolujte, zda hodiny běží ajsou nastaveny na správný čas. Pokud ne, použijte příklad z khihovny *RTC by Makuna*

## Prerekvizity

  1. [Sériová komunikace](serial.md)
  1. [Displej](displej.md)
