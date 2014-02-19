# Tetris - Projet AP8

Sujet de TP de C++ de deuxième année Informatique à l'IUT de Vannes.

Par Julien Cadic et Antoine Pinsard

## Avancement

Les pièces T, I, O, Z1, Z2, L1 et L2 ont été implémentées et testées.

## Choix techniques

Nous avons fait le choix de ne pas implémenter la méthode
`CPieceAbstract::Turn()` dans les classes filles et d'effectuer la rotation de
la pièce directement dans les méthodes `CPieceAbstract::TurnRight()` et
`CPieceAbstract::TurnLeft()`. En effet, pour la rotation nous ne nous basons pas
sur un disjonction de cas en fonction de l'état de la pièce, mais sur un calcul
dépendant de la matrice actuelle de la pièce et du sens de rotation définit.
Pour faire tourner une pièce vers la droite, il suffit, pour chaque élément de
la matrice, de modifier son ordonnée en son abscisse actuelle, et son abscisse
en la taille de la matrice moins 1 moins son ordonnée. Et pour la rotation vers
la gauche, c'est l'inverse. Ce qui nous donne simplement :

* Rotation vers droite :
  * newRow = oldCol
  * newCol = size-1 - oldRow
* Rotation vers la gauche :
  * newRow = size-1 - oldCol
  * newCol = oldRow

L'intérêt est d'avoir une méthode générique à toutes les pièces, plutôt que de
faire une disjonction de cas pour chaque sens (Top, Right, Bottom, Left) de
chaque pièce (T, I, O, L1, L2, Z1, Z2). Nous avons ainsi deux cas à gérer au
lieu de 21 (`4×6 - 3`, la pièce O étant "insensible" à la rotation).

## Tests

Les tests se compilent et s'exécutent en mode console avec la commande `make`.
Chaque test élémentaire comporte une courte description et son statut
(**[PASS]** en vert si le test s'est bien déroulé, **[FAIL]** en rouge si le
test a échoué). Pour plus de lisibilité le statut est toujours affiché en fin de
ligne (une ligne faisant 80 caractères).

Voici la liste des tests disponibles :

### `make testC?Piece`

Lance le test de la pièce "?". Par exemple, pour tester la pièce T, lancer la
commande `make testCTPiece`. Pour tester la pièce L2, lancer la commande `make
testCL2Piece`.

Cette commande compile le fichier de test et le lance avec l'argument `--no-gui`
pour n'afficher que le résultat des tests en *mode console*. Pour tester
l'affichage en *mode GUI*, il suffit ensuite de lancer le fichier de test sans
arguments (`../bin/testC?Piece.bin` en remplaçant évidemment le `?` par la pièce
à tester).

### `make testPiece`
Lance tous les tests des pièces (testCTPiece, testCIPiece, testCOPiece, ...)

### `make test`
Lance l'intégralité des tests en mode console

