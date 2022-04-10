# Bomberman

Il s'agit de notre projet d'INFO0402 dans lequel nous avons du développer le jeu du **Bomberman**.

<i>Version 0.1</i>

## Auteurs

- CHEMIN Pierre
- HADID Hocine

----

## Architecture du projet

En ce qui concerne l'architecture de notre projet, elle est assez simpliste.  
A la racine vous disposerez des dossiers et fichiers suivants :

- Code [Dossier] => Le code du Bomberman
- Rapport [PDF] => Le rapport du projet
- Doc [PDF] => La documentation généré à l'aide de Doxygen
- Ce ReadMe

### Le dossier "Code"

Dans ce dossier, nous retrouverons les dossiers et fichiers suivats :
- doc [Dossier] => Le dossier contient la documentation sous format html, latex et pdf
- src [Dossier] => Le dossier contenant tous les "packages"
- resources [Dossier] => Les ressources nécessaires, c'est-à-dire les maps au format .txt
- ProgBomberman.cpp => Le fichier contenant le main du jeu Bomberman et permettant de lancer une partie
- makefile => Le fichier permettant la création de l'exécutable intitulé "Bomberman"
- Doxyfile => Le fichier aidant à générer la documentation

### L'organisation du dossier src

Le dossier "src" contenant tout le code du projet est subdivisé en 2 dossiers, le dossier "include" contenant tous les '.h' et le dossier "src" contenant tous les '.cpp'.  
Ces dossiers sont également divisés en sous-dossier correspondant à nos "packages" expliqués dans le rapport.

---

## Création d'un exécutable

Pour créer un exécutable du jeu Bomberman, il vous suffit d'utiliser le makefile disponible avec la commande suivante :

    make

Une fois l'exécutable intitulé *Bomberman* créé il vous suffit de le lancer à l'aide de la commande suivante :

    ./Bomberman

Une fois tout cela effectué, il n'y a plus qu'ç jouer une partie !