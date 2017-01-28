#	Semafor

## Kód
[Semafor.ino](../../../../examples/semafor/semafor.ino)

## Motivace a cíle

  Větší samostatná práce. Studenti vědí, jak funguje semafor, nechť tedy naprogramují samostatně jeho funkci, která cyklicky rozsvěcí jednotlivé barvy tak,
  jako na skutečném semaforu, tedy Č - Č+O - Z - O - Č...

  Další krok je využití tlačítka pro přesun do dalšího stavu



## Teorie
  - Stavový automat vs vodopád
  - Ukázka nejednoznačnosti tlačítka (zákmity atd.)
  - Prázdná smyčka (čekání na něco)
  - Tlačítka
  - Pull-up rezistor https://cs.wikipedia.org/wiki/Pull_up_rezistor 

##	Použité funkce
- digitalRead
- INPUT_PULLUP
  
## Zapojení

![Semafor.ino](../../../docs/Semafor_bb.png)
 
## Cvičení
  - Vyzkoušet chování bez pull-up rezistoru.
  - Upravte příklad tak, aby svítila červená, a na stisknutí tlačítka proběhl celý semaforový cyklus zpátky k červené (spouštěný automat)
  - co by bylo potřeba pro přidání funkce "semafor pro chodce" (třeba přes RGB LED)

## Pro lektora
  - Stavový automat
