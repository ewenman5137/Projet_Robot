# Robot Télécommandé via ESP32 et Manette Xbox Series X

## Présentation du Projet

L'objectif de ce projet est de construire un robot télécommandé en utilisant un ESP32 et une manette Xbox Series X. Le robot est alimenté par deux packs de batteries, chacun contenant 8 piles AA (1.5V, 2.4mA). Ce fichier README vous guidera à travers la configuration, les composants, et les étapes pour faire fonctionner votre robot.

## Composants

- Arduino Mega
- ESP32
- Manette Xbox Series X
- Drivers de moteur L298N (2 unités)
- Moteurs DC (4 unités)
- Packs de batteries (2 unités, chacun avec 8 piles AA)
- Fils de connexion

## Schéma de Câblage

![Schéma de câblage](https://github.com/ewenman5137/Projet_Robot/blob/main/images/schema.png)

## Instructions de Câblage

1. **Arduino Mega aux Drivers de Moteur L298N**
   - Connectez les broches IN1, IN2, IN3, IN4 du premier L298N aux broches 22, 23, 24, 25 de l'Arduino.
   - Connectez les broches IN1, IN2, IN3, IN4 du deuxième L298N aux broches 26, 27, 28, 29 de l'Arduino.
   - Connectez les broches ENA et ENB des deux L298N à 5V et GND sur l'Arduino.

2. **Moteurs DC aux Drivers de Moteur L298N**
   - Connectez les moteurs aux broches OUT1, OUT2, OUT3, OUT4 des deux drivers de moteur L298N.

3. **Packs de Batteries aux Drivers de Moteur L298N**
   - Connectez le terminal positif du premier pack de batteries à la broche 12V du premier L298N.
   - Connectez le terminal négatif du premier pack de batteries à la broche GND du premier L298N.
   - Répétez la même opération pour le deuxième pack de batteries et le deuxième driver de moteur L298N.

4. **ESP32 à Arduino Mega**
   - Connectez la broche RX de l'ESP32 à TX1 (18) de l'Arduino Mega.
   - Connectez la broche TX de l'ESP32 à RX1 (19) de l'Arduino Mega.
   - Connectez les broches VCC et GND de l'ESP32 à 3.3V et GND sur l'Arduino Mega.

## Configuration Logicielle

### Arduino

1. Installez l'IDE Arduino depuis [ici](https://www.arduino.cc/en/Main/Software).
2. Ouvrez l'IDE Arduino et installez les bibliothèques nécessaires pour la communication avec l'ESP32 et la manette Xbox.
3. Téléversez le sketch Arduino sur l'Arduino Mega. Assurez-vous que la logique de contrôle des moteurs et la configuration de la communication série sont correctement implémentées dans le code.

### ESP32

1. Installez le gestionnaire de carte ESP32 sur l'IDE Arduino.
2. Téléversez le firmware ESP32 pour gérer les entrées de la manette Xbox et envoyer des commandes à l'Arduino Mega.

### Manette Xbox Series X

1. Associez la manette Xbox Series X avec l'ESP32 via Bluetooth.
2. Assurez-vous que les entrées de la manette sont correctement mappées aux commandes de contrôle des moteurs.

## Test et Calibration

1. Allumez le robot en utilisant les packs de batteries.
2. Vérifiez que l'ESP32 et l'Arduino communiquent correctement.
3. Testez les commandes de la manette Xbox pour s'assurer que le robot répond comme prévu.

## Fonctionnalités Actuelles

- **Boutons A, B, Y et X** : Permettent de faire demi-tour sur place.
- **Gâchette de droite** : Permet d'avancer.
- **Gâchette de gauche** : Permet de reculer.
- **Joystick gauche** : Permet de tourner à droite ou à gauche.


## Conclusion

Vous avez maintenant toutes les informations nécessaires pour assembler et configurer votre robot télécommandé. Amusez-vous bien avec votre projet de robotique !

---

Si vous avez des questions ou des problèmes, n'hésitez pas à ouvrir une issue sur ce dépôt GitHub. Bon bricolage !

# Résultat 
![Schéma de câblage](images\présentation1.png)
![Schéma de câblage](images\présentation2.png)
![Schéma de câblage](images\présentation3.png)
![Schéma de câblage](images\présentation4.png)
