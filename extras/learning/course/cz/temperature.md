#	Měření teploty

## Kód
[MeasureTemperature.ino](../../../../examples/MeasureTemperature/MeasureTemperature.ino)

## Motivace a cíle

  Nahradit teploměr za fotorezistor z předchozího příkladu a vypisovat hodnoty na sériové lince

  Teplota se zobrazí na displeji

## Teorie
  - Instalace knihovny v IDE a ručně.
  - Elektrotechnické schéma a značky.


##	Použité funkce
  - pinMode
  - digitalWrite
  - delay
  
## Zapojení

![MeasureTemperature](../../../docs/Temperature.png)
 
## Cvičení
  - Při dosažení zvolené teploty rozsvítit LED.
  - Teplotu zobrazit v °F https://cs.wikipedia.org/wiki/Stupe%C5%88_Fahrenheita. 
  - Vytvořit počítadlo průchodů lidí nebo předmětů pomocí světelného senzoru.


## Pro lektora
  - Není třeba přepočítávat na reálnou teplotu. Stačí surová hodnota ze senzoru, ušetří se výpočetní výkon, paměť, …
  - Účastníci si musí najít, jak zobrazit F. Je třeba je nasměrovat na zdrojové soubory knihovny Edushield.
  - Nastavením citlivosti senzoru na světlo vytvořit hranici, kdy zastínění bude odpovídat průchodu člověka nebo předmětu.

## Prerekvizity

1. [Displej](displej.md)
1. [Měření světla](lightscale.md)
1. [Blikání LED](blink.md)