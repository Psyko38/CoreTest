# CoreTest

English version: [README.en.md](README.en.md)

CoreTest est un projet de preuve de concept pour tester l'idée d'un mini OS nommé Core, conçu pour tourner sur une M5 Cardputer ADV équipée d'un ESP32-S3.

Ce dépôt n'est pas un projet “fini” ni une build fournie. Il sert à vérifier si la théorie de conception fonctionne avant de passer à un vrai système plus structuré : gestion des drivers, gestion d'écran, puis éventuellement ajout d'un environnement plus complet.

## Objectif du projet

L'objectif principal est de valider la base architecturelle d'un mini OS embarqué, en commençant par les éléments fondamentaux :

- pilotes clavier
- pilotes écran
- organisation du code par modules
- étude de la faisabilité sur hardware réel

La logique est simple : tester les briques de base avant de construire un système plus grand.

## État actuel

### ✅ Fait

- Initialisation du driver clavier
- Lecture de l'état du clavier
- Détection des changements et des touches pressées
- Gestion de base de Backspace, Enter et saisie texte
- Affichage du texte saisi à l'écran

### 🔜 Prochaine étape

- Initialisation du driver écran
- Encapsulation des primitives d'affichage
- Gestion des fenêtres / zones de texte / UI basique

### ❌ Pas prévu pour le moment

- Wi-Fi
- Bluetooth
- gestion réseau
- services système avancés

## Pourquoi ce projet existe

Ce projet sert de laboratoire de test pour valider si l'architecture “Core” est viable avant de poursuivre vers un mini OS complet.

Autrement dit :

- ce n'est pas encore le vrai OS
- ce n'est pas une build finale
- c'est le terrain d'expérimentation avant la vraie base système

## Stack technique

- PlatformIO
- Arduino Framework
- M5Cardputer library
- ESP32-S3
- M5 Cardputer ADV

## Prérequis

- PlatformIO installé
- VS Code avec l'extension PlatformIO
- M5 Cardputer ADV connectée
- Drivers USB pour ESP32-S3 selon ton système

## Démarrage rapide

1. Ouvre le projet dans VS Code.
2. Vérifie la configuration de `platformio.ini`.
3. Compile et télécharge le binaire :

```bash
pio run -t upload
```

4. Si besoin, ouvre le moniteur série :

```bash
pio device monitor
```

## Structure du projet

```text
CoreTest/
├── include/
├── lib/
├── src/
│   ├── main.cpp
│   └── driver/
│       └── keyboard/
│           ├── KeyboardDriver.h
│           └── KeyboardDriver.cpp
├── compile_commands.json
├── platformio.ini
├── README.md
└── test/
```

## Fichiers importants

- `src/main.cpp` : boucle principale, initialisation des composants et logique d'affichage
- `src/driver/keyboard/KeyboardDriver.h` : interface du driver clavier
- `src/driver/keyboard/KeyboardDriver.cpp` : implémentation du driver clavier
- `platformio.ini` : configuration de compilation pour la carte cible

## Roadmap

### Étape 1 — base système

- [x] init clavier
- [ ] init écran
- [ ] abstraction des drivers
- [ ] gestion du rendu texte / UI basique

### Étape 2 — extensions

- [ ] Wi-Fi
- [ ] Bluetooth
- [ ] services système
- [ ] premiers modules applicatifs

## Note de conception

Le projet suit une logique de progression incrémentale :

1. tester un driver seul
2. vérifier le comportement réel sur le matériel
3. structurer le code proprement
4. passer à la couche supérieure suivante

Cela permet de valider les hypothèses sans partir directement sur un mini OS complet et sans perdre de temps sur des fonctionnalités qui ne sont pas encore nécessaires.

## Licence

Projet de test et de recherche de conception, sans objectif de publication ou de build finale pour le moment.