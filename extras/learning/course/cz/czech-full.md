# Obsah

## [Úvod](uvod.md)

## Lekce

1. [Arduino IDE a hardware](arduino-sw-hw.md)
1. [Blikání LED](blink.md)
1. [Semafor](semafor.md)
1. [RGB LED](rgb.md)
1. [Sériová komunikace](serial.md)
1. [Displej](displej.md)
1. [Měření světla](lightscale.md)
1. [Teploměr](temperature.md)
1. [Hodiny reálného času](rtc.md)
1. [Práce s přerušením](interrupt.md)

## Pro pokročilé
1. [Sledování teploty v lednici](fridge.md)
1. [Generátor náhodných čísel](random.md)
1. [Připojení k internetu](ethernet.md)
1. [Měření a zaznamenávání dat](datalogger.md)

## Dokumentace EduShield

[Cheat sheet](cheatsheet.md)
## Úvod

EduShield byl vytvořen pro výuku základů práce s elektronikou a Internetem věcí. Jeho primárním cílem je přinést jednoduchý a cenově dostupný způsob, jakým mohou zájemci z věkové skupiny 12+ získat základní i rozšířenou sadu kompetencí v oblasti mikroelektroniky, programování elektronických zařízení a propojování věcí z reálného světa s digitální technologií.

EduShield je otevřená technologie, navržená tak, že spolupracuje s nejrozšířenější elektronickou platformou dneška, s vývojovým kitem Arduino. Výhodou tohoto kitu je nízká cena, příznivá křivka učení a obrovská dostupnost rozšiřujících zařízení, díky nimž je možné použít Arduino jako platformu pro sběr dat, pro řízení strojů, pro vývoj elektronických zařízení i pro výuku nejrůznějších technik a technologií.

EduShield byl navržen na základě zkušeností s kurzy základů elektroniky, kterými prošlo přes 400 lidí. Zohledňuje potřeby a cíle výuky jak pro základní seznámení, tak i pro pokročilejší techniky. Rozvíjí kompetence v oblastech práce s elektronickými zařízeními, od programování po jejich reálný návrh. Učí frekventanty, jak spojit reálný svět s digitálním, ukazuje způsoby měření fyzikálních veličin a techniky pro interakci s lidmi. Předpokladem pro úspěšné absolvování kurzu jsou znalosti základů elektroniky. Tyto znalosti jsou v průběhu kurzu upevněny a jsou posíleny o kompetence tzv. extrémního programování. Účastníci zároveň získávají důležité kompetence v oblasti inteligentních systémů řízení, Internetu věcí, automatizace a regulace, a v oblasti návrhu a testování elektronických obvodů.


## Prerekvizity
  - Znalost základů programování v jazyce, který vychází z jazyka C (C, Java, C++, C#, JavaScript, PHP a další). Požadovaná úroveň: znalost konceptu proměnných, konstant, funkcí a základních konstrukcí programovacího jazyka (smyčky, podmínky)
  - Fakultativní: znalost fyzikálních principů elektřiny (napětí, proud, funkce el. obvodů)
3	Příprava pro studenty
  - Instalace IDE. Arduino IDE je dostupné pro Linux, Mac a Windows [http://www.arduino.cc/en/Main/Software]. 
  - [Zdrojové kódy ukázkových aplikací](https://github.com/maly/edushield/releases) Stačí vybrat Download ZIP. Součástí balíku jsou i knihovny pro použité rozšíření.
  - Schéma shieldu a datasheet pro použité obvody

## Příprava pro lektora

  Vše si nejdříve vyzkoušejte, než začnete školit, nebo se sami tohoto školení zúčastněte!

  Pro každého studenta je potřeba mít připraveno: 

###	Než začne seminář
  - Poslat studentům odkaz, co si mají stáhnout a nainstalovat
    -  https://www.arduino.cc/en/Main/Software 
    -  https://github.com/maly/edushield/releases
  - Připravený hardware
    -  Arduino Uno nebo klon. U klonů pozor na nutnost instalace ovladačů!
    -  EduShield
  -	Připravený USB flash disk ke každému hardware, a na něm:
    -  Arduino IDE pro všechny platformy, kdyby někdo zapomněl.
    -  Zdrojové kódy z https://bitbucket.org/maly/edushield/src
    -  Všechny potřebné knihovny.
    - Ovladače
  -  Vytisknout pro každého účastníka:
    -  Arduino Cheat Sheet https://github.com/liffiton/Arduino-Cheat-Sheet 
    -  EduShield Cheat Sheet.docx

### Příprava knihovny

  Ve Správci knihoven najít "EduShield" a nainstalovat.

  *Alternativně: Obsah ZIPu nahrát do podadresáře Libraries. Tím se příklady objeví v "Příkladech z knihoven"*

###	Instalace ovladačů
  Podle operačního systému a použité desky se může instalace ovladačů lišit. Systém musí desku Arduino rozpoznat jako sériový port. Pro převod USB na sériový port se používají dva typy čipů.

  - FTDI (http://www.ftdichip.com) – nejčastěji u dražších Arduino. Některé klony Arduino mohou obsahovat čip, který je kopií čipu od společnosti FTDI. S těmito čipy mohou mít oficiální ovladače problémy.
  - CH340 – levná alternativa čipů FTDI. Většinou najdete ve velmi levných klonech Arduino. Viz https://iotta.cz/ovladace-pro-ch340g/

#### Mac OS
  
  Pokud není zařízení rozpoznáno, je třeba nainstalovat ovladač z https://iotta.cz/ovladace-pro-ch340g/ 

  Další alternativy: 
  -  http://www.wch.cn/download/CH341SER_MAC_ZIP.html 
  -  http://0xcf.com/2015/03/13/chinese-arduinos-with-ch340-ch341-serial-usb-chip-on-os-x-yosemite/ 

#### Linux
  
  Arduino by mělo být rozpoznáno automaticky s čipem FTDI i CH340. Uživatel musí být ve skupině dialup, aby měl přístup k sériovému portu a nemusel Arduino IDE spouštět přes sudo. 
  
  Testované distribuce
  - Ubuntu 14.04 LTS
  - Ubuntu 15.04
  - Ubuntu 16.04

#### Windows 10

Instalace ovladačů proběhne automaticky. Vyžaduje připojení k internetu.

#### Windows 8.1, 8, 7

Pokud se ovladače nenainstalují automaticky, tak je třeba ovladač nainstalovat ručně. Umístění ovladačů:
  - Ovladače pro FTDI čip jsou součástí Arduino IDE.
  - Ovladač pro CH340 čip: https://iotta.cz/ovladace-pro-ch340g/  

####	Instalace nepodepsaných ovladačů
Při instalaci ovladačů na 64-bit verze Windows může výjimečně dojít k problému s digitálním podpisem ovladače. Nové verze ovladačů pro čip FTDI jsou podepsané. Může být problém s ovladačem pro CH340, ale neměl by být. Pokud systém odmítne instalaci ovladače kvůli digitálnímu podpisu, tak postupujte podle tohoto návodu http://robodoupe.cz/wp-content/uploads/2013/04/Arduino-a-PICAXE-na-Windows-8-64.pdf 

# S čím budeme učit
##	Hardware
###	Arduino UNO
  Arduino je jednoduchá vývojová deska s mikrořadičem AVR společnosti ATMEL. Na této desce najdete vše potřebné pro vytváření jednoduchého hardware pro domácí automatizaci, robotiku, interaktivní instalace a mnoho dalšího.
### EduShield
  EduShield je deska pro Arduino, vyvinutá speciálně pro potřeby výuky základů mikroelektroniky a práce s ní. Desku vyrání sdružení [CZ.NIC](https://nic.cz)

![EduShield](../../../docs/edushield.jpg)
 
##	Software
###	Arduino IDE
  Arduino IDE je vývojové prostředí, pomocí kterého budete psát aplikace pro vývojové desky Arduino a zároveň umožňuje aplikaci na vývojovou desku Arduino nahrát.
# Arduino IDE a práce s HW Arduino
## Probraná teorie
  - Instalace IDE
  - Instalace ovladače
  - Výběr desky v nastavení
  - Nastavení sériového portu
  - Nahrání aplikace do desky
  - Připojení desky k PC, spojení se shieldem
## Praktické ukázky
  - Step-by-step demonstrace probíraných témat na učitelském PC a projektoru
#	Hello World!

## Kód
[Blink.ino](../../../examples/blink/blink.ino)

## Motivace a cíle

  Blikání LED. Vysvětlit, že to je ekvivalent známého "Hello world", tedy první příklad v daném jazyce.

  Doporučujeme nejprve ukázat kód, nechat účastníky, aby jej našli v příkladech, zkompilovali, nahráli a viděli, co se děje. Teprve pak vysvětlit strukturu kódu a účel.



## Teorie
  - Logické úrovně
  - Fungování LED
  - Předřazený rezistor
  - Práce s IDE: otevřít soubor, přeložit, nahrát
  - Proměnné
  - Funkce setup() a loop()

##	Použité funkce
  - pinMode
  - digitalWrite
  - delay
  
## Zapojení

![Blink.ino](../../../docs/Blink_bb.png)
 
## Cvičení
  - Změna rychlosti blikání
  - Použití dalších LED (piny 16 a 17)
  - [Morseovka](https://cs.wikipedia.org/wiki/Morseova_abeceda)

## Pro lektora
  - Vysvětlit studentům, že delay blokuje vykonávání kódu.
#	Semafor

## Kód
[Semafor.ino](../../../examples/semafor/semafor.ino)

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
#	RGB

## Kód
[rgb.ino](../../../examples/rgb/rgb.ino)
[rgb_pwm.ino](../../../examples/rgb_pwm/rgb_pwm.ino)

## Motivace a cíle

  - Ukázat, jak se pracuje s RGB LED.
  - Vysvětlit míchání barev
  - PWM


## Teorie
  - Rozsvěcení nikoli přes HIGH proti zemi, ale přes LOW proti Vcc
  - RGB – míchání barevných světel. Každá barva se skládá ze tří základních světel
  - Pro pokročilejší: zmínit rozdíl mezi „mícháním světel“ a „mícháním barevných pigmentů“
  - [PWM](https://cs.wikipedia.org/wiki/Pulzn%C4%9B_%C5%A1%C3%AD%C5%99kov%C3%A1_modulace)

![PWM](https://www.arduino.cc/en/uploads/Tutorial/pwm.gif)

##	Použité funkce
  - analogWrite
  
## Zapojení

![RGB](../../../docs/RGB_bb.png)
 
## Cvičení
  - Ukázka plynulých změn barvy světla
  - Změnit přírůstky/úbytky pro PWM. (Student by si měl všimnout, že od určité hranice svítí LED plně. Vysvětlit důvod: minimální napětí nutné pro rozsvícení)


## Pro lektora
  - Volitelně: vysvětlit důvody spínání proti Vcc
#	Sériová komunikace

## Kód
[SerialCommunication.ino](../../../examples/SerialCommunication/SerialCommunication.ino)

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
#	Displej ze sedmisegmentovek

## Kód
[hello.ino](../../../examples/hello/hello.ino)

## Motivace a cíle

  Ukázka práce s I2C zařízením pomocí knihovny



## Teorie
  - Nalezení správného postupu v knihovně
  - Implementace vlastního postupu
  - Ovládání hardware napřímo, pokud knihovna nenabízí požadované

![7segment](img/7segment.png)

##	Použité funkce
- Wire
- knihovna Edushield.h
  
## Zapojení

## Cvičení
  - Přidat tabulku nejčastějších znaků
  - Vytvoření vlastní knihovny (pro pokročilé)

## Pro lektora
  - Je třeba prozkoumat knihovnu a nalézt místo, kde se posílají data do displeje. 
  - Experimentálně zjistěte rozložení segmentů 
#	Měření intenzity světla

## Kód
[LightScale.ino](../../../examples/LightScale/LightScale.ino)

## Motivace a cíle

  Intenzita světla se převede na LED, které se budou chovat jako škála. Hodnota načtená z analogového senzoru se vypíše na sériovou konzoli.

  Ukázka čtení analogových hodnot, princip ADC

## Teorie
  - Analogový senzor
  - ADC https://cs.wikipedia.org/wiki/A/D_p%C5%99evodn%C3%ADk 
  - Vzorkovací frekvence https://cs.wikipedia.org/wiki/Vzorkov%C3%A1n%C3%AD
  - Dělič napětí https://cs.wikipedia.org/wiki/D%C4%9Bli%C4%8D_nap%C4%9Bt%C3%AD 

![ADC](http://m.eet.com/media/1075629/0503feat2fig1.gif)

##	Použité funkce
  - analogRead
  - map

  
## Zapojení

![LightScale.ino](../../../docs/LightScale_bb.png)
 
## Cvičení
  - Výpočet napětí na senzoru.
  - Změna citlivosti posunem rozsahu ve funkci map.


## Pro lektora
  - Referenční napětí je 5 V, převodník je 10-bit, tedy 0-1023.
  - Díky napěťovému děliči určité hranice nemusejí mít vliv. Citlivost obecně závisí na použitém rezistoru připojeného na zem.
  - Je třeba najít mez citlivosti.

  ## Prerekvizity

  1. [Sériová komunikace](serial.md)
  1. [Displej](displej.md)
  1. [Blikání LED](blink.md)
#	Měření teploty

## Kód
[MeasureTemperature.ino](../../../examples/MeasureTemperature/MeasureTemperature.ino)

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
#	Hodiny reálného času

## Kód
[Clock.ino](../../../examples/Clock/Clock.ino)
[RealTimeClock.ino](../../../examples/RealTimeClock/RealTimeClock.ino)

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
# Námět: Sledování teploty v lednici

  -	Aplikace uchovává maximální a minimální teplotu.
  - Typ zobrazené teploty je indikován LED.
  - Pokud je lednice otevřená déle než 10 sekund, tak začne vše blikat
# Námět: Generátor náhodných čísel

  - https://cs.wikipedia.org/wiki/Gener%C3%A1tor_n%C3%A1hodn%C3%BDch_%C4%8D%C3%ADsel
  - http://www.root.cz/clanky/hardwarovy-generator-nahodnych-cisel-aneb-nahoda-z-atomu/

1.	Čteme nejnižší bit A/D převodníku, ke kterému je připojený zdroj šumu (dioda, nebo fotorezistor / termistor). 
2.	Sebrat vzorek 1000 / 10000 / 100 000 náhodných čísel, podívat se, jak náhodná jsou (rovnoměrné rozdělení atd.)
3.	Cvičení z pilnosti: zakreslit např. průběh šumu do grafu; podívat se, jestli šum roste s teplem (u diody ano, stačilo cvaknout zapalovačem) ;)
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
