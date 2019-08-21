# Capteur de pulsation cardiaque sur arduino nano
Je débute dans la création d'objets connectés et j'aimerai partager ma création avec tout les bugs qu'il comporte :) !

Capteur de pulsation cardiaque sur arduino nano ou tout autres arduino
 ```
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


je vous invite a venir regarder mon tuto sur youtube en français sur ce projet...

### Requis Logiciel
* [Arduino IDE](https://www.arduino.cc) - arduino IDE
* [pulseSensor](https://pulsesensor.com) - pulseSensor

### Requis Hardware: Sur aliexpress !
Arduino Nano (at328/AT328P)->  http://bit.ly/2WKxqZE

Capteur Cardiaque -> http://bit.ly/2HhhdRS

Resistance 1kΩ -> pack resistances http://bit.ly/2zdPHR0

Led 1206 : pack couleur -> http://bit.ly/31Sas0T


### Schéma électronique et cablages


![Schema ](Schematic_HeartRate.png?raw=true "schema normalisé")


## Tests


en cas d'erreur la led Pin 13 clignotera rapidement et le programme stopera.


## Contribution

Toutes contribution est la bienvenue sur ce projet.


## Auteur

* **Djamal Guellati** - *Initial work* - [Defdjamel](https://github.com/Defdjamel)

 list of [contributors](https://github.com/your/project/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
