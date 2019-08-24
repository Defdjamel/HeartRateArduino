# Capteur de pulsations cardiaques sur arduino nano
Je débute dans la création d'objets connectés et j'aimerai partager ma création avec tout les bugs qu'il comporte :) !

Capteur de pulsations cardiaques sur arduino nano ou tout autres arduino compatibles.
 ```
 Tutoriel en français sur https://youtu.be/JonCgBIgUcw
```

⚠️ la protection de données personnelles vous impose de ne pas recupérer et reutiliser les données d'autrui sans autorisation ⚠️
![Schema Simplifié ](schemaSimple.png?raw=true "schema simplifié")

## Bien commencer

Ce programme a été codé sous l'arduino IDE utilisant des libraries open sources.
je prepare une vidéo youtube pour expliquer certain details du code, hardware mais aussi du boitier imprimer en 3D.
Voici un schéma simple de fonctionnement:


* 1 initialisation du CPU
* 2 Recuperation du rythme cardiaque
* 3 affichage du rythme sur les leds.
* 4 boucle -> 1


je vous invite a venir regarder mon tuto sur youtube en français sur ce projet : https://youtu.be/JonCgBIgUcw

### Requis Logiciel
* [Arduino IDE](https://www.arduino.cc) - arduino IDE
* [pulseSensor](https://pulsesensor.com) - pulseSensor
* [le code ](HeartRate.ino) - Le code

### Requis Hardware: Sur aliexpress !
Arduino Nano (at328/AT328P)->  http://bit.ly/2WKxqZE

Capteur Cardiaque -> http://bit.ly/2HhhdRS

Resistance 1kΩ -> pack resistances http://bit.ly/2zdPHR0

Led 1206 smd : pack 5 couleurs -> http://bit.ly/31Sas0T ⚠️ attention au sens des Led ⚠️ 

Résistances 1206 smd : pack 1Ω-1MΩ :  http://bit.ly/2L0hNVh

la taille 1206 reste soudable à la main et permet un gain de place.

### Schéma électronique et cablages


![Schema ](Schematic_HeartRate.png?raw=true "schema normalisé")


## Preparation
* cablage et soudure des composant 
* Installation de l'IDE Arduino
* Ajout de la library pulsensor depuis l'IDE arduino
* Ouverture de l'exemple "GettingStartedProject"  afin de calibrer le capteur et de verifier que l'arduino recoit correctement les pulsations cardiaques.
* Ouverture de HeartRate.ino afin d'afficher le rythme cardiaque sur les Leds.

Je vous invite a venir voir les étapes plus en details sur mon tuto -> http://bit.ly/2KJLYBo

## Impression 3D
les fichiers STL sont  ici :

 [3D/case.STL](3D/case.stl) - boitier 

 [3D/cver.STL](3D/cover.stl) - couvercle 
 
 [3D/finger.STL](3D/finger.stl) - repose doigt 

![impression 3D ](3D/case3D.png?raw=true "impression 3D")

## Test

en cas d'erreur la led Pin 13 clignotera rapidement et le programme stopera.


## Contribution

Toutes contribution est la bienvenue sur ce projet.


## Auteur

* **Djamal Guellati** - *Initial work* - [Defdjamel](https://github.com/Defdjamel)


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
