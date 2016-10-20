# muzzel_flash
Mündungsfeuer-Simulator für NERF und/oder Softair 

Beim durchfliegen der IR-Lichtschranke wird ein Lichtblitz auf den Neopixel ausgelöst.

Wird die Lichtschranke beim Starte unterbrochen, blitzen die Neopixel im Demomodus auf.

Wird der Zählerstand an abgegebenen Geschossen erreicht, leuchtet eine Warn-LED.

Die Farbe ist im Programm einstellbar.

Bei Problemen mit dem CH340 treibern ggf. hier schauen:
https://www.jens-bretschneider.de/aktuelle-treiber-fur-seriell-zu-usb-adapter/

Zum Re-Programmieren bitte die ino-Datei mit der Arduino-IDE auf den Chip schreiben.
https://www.arduino.cc/en/Main/Software

Kleiner hinweis: Anstelle der gekauften 9V-Batterie-Clips am besten die DIY-Variante verwenden,
da die gekauften nicht so stabil sind.
https://www.youtube.com/watch?v=dzps5vHUmY0

Zur verkabelung eigenen sich sehr gut alte USB-Kabel.

#Der Schaltplan (skizzenhaft)
![Der Schaltplan (skizzenhaft)](https://github.com/BKTRIE/muzzel_flash/blob/master/muzzleflash001.png)

#Die Verkabelung
![Die Verkabelung](https://github.com/BKTRIE/muzzel_flash/blob/master/muzzleflash002.png)

#Beispielaufbau
![Beispielaufbau](https://github.com/BKTRIE/muzzel_flash/blob/master/muzzleflash003.png)

#Bauteile
![Bauteile](https://github.com/BKTRIE/muzzel_flash/blob/master/Bauteile.jpg)
