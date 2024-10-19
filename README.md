# KFS-1

KFS-1 est un projet visant à développer un système d'exploitation minimaliste pour l'architecture x86 (32 bits).

## Objectif

Cette étape du projet consiste à mettre en place le support du multiboot via GRUB et à afficher un message simple à l'écran après le démarrage.

## Prérequis

Ce projet doit être exécuté dans une machine virtuelle Debian avec un environnement graphique GNOME. Les outils et bibliothèques suivants sont requis pour compiler et exécuter le système d'exploitation :

- `gcc`
- `nasm`
- `qemu-system-x86`
- `grub-pc-bin`
- `grub-common`
- `libvirt-daemon-system`
- `libsdl2`
- `xorriso`

## Installation

1. **Mise à jour du système et installation des dépendances** :  
   Pour installer toutes les dépendances nécessaires, exécutez le script `install.sh` fourni :
   ```bash
   ./install.sh
   ```

2. **Compilation du projet** :  
   Une fois les dépendances installées, compilez le projet à l'aide de la commande `make` :
   ```bash
   make
   ```

3. **Exécution du système via QEMU** :  
   Après la compilation, lancez le système d'exploitation dans l'émulateur QEMU avec la commande suivante :
   ```bash
   qemu-system-i386 -cdrom KFS.iso
   ```

## Fonctionnalités

- **Support du multiboot via GRUB** : Le système d'exploitation est conçu pour être compatible avec le standard multiboot, permettant un démarrage via GRUB.
- **Affichage d'un message à l'écran** : Une fois le noyau chargé, un message s'affiche à l'écran pour indiquer le bon déroulement du démarrage.

## Licence

Ce projet est distribué sous la licence MIT. Veuillez consulter le fichier `LICENSE` pour plus de détails.