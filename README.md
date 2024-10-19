# KFS-1

KFS-1 est un projet visant à développer un système d'exploitation minimaliste pour l'architecture x86.

## Objectif

Dans cette étape du projet, nous mettons en place le support du multiboot via GRUB et affichons un message à l'écran.

## Prérequis

Pour exécuter ce projet sur une machine virtuelle Debian, les outils et bibliothèques suivants doivent être installés :

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
   Exécutez le script `install.sh` pour installer toutes les dépendances nécessaires :
   ```bash
   ./install.sh
   ```

2. **Compilation du projet** :  
   Utilisez `make` pour compiler le projet :
   ```bash
   make
   ```

3. **Lancer le système dans QEMU** :  
   Une fois la compilation terminée, démarrez le système d'exploitation généré en utilisant QEMU :
   ```bash
   qemu-system-i386 -cdrom KFS.iso
   ```

## Fonctionnalités

- **Support du multiboot via GRUB** : Le système d'exploitation est configuré pour être lancé via GRUB en utilisant le standard multiboot.
- **Affichage d'un message à l'écran** : Après le chargement du noyau, un message est affiché à l'écran pour confirmer le bon démarrage du système.

## License

Ce projet est sous licence MIT. Consultez le fichier `LICENSE` pour plus d'informations.
