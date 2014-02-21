<!--
Si vous lisez ce README dans un éditeur de texte, nous vous conseillons plutôt
de le consulter à cette adresse : https://github.com/apinsard/TetrisAP8 pour
plus de clarté.
-->

# Tetris - Projet AP8

Sujet de TP de C++ de deuxième année Informatique à l'IUT de Vannes.

Par Julien Cadic et Antoine Pinsard

## Avancement

Les pièces I, L1, L2, O, T, Z1 et Z2 ont été implémentées et testées. Tous les
déplacements sont gérés, y compris la « chute nette » avec la barre d'espace. La
gestion du score est également implémentée, avec des niveaux plus rapides au fur
et à mesure que l'on détruit des lignes. Lorsque le jeu est terminé, on affiche
« Game Over », le score obtenu et le niveau atteint.

## Choix techniques

### Rotation des pièces

Nous avons fait le choix de ne pas implémenter la méthode
`CPieceAbstract::Turn()` dans les classes filles et d'effectuer la rotation de
la pièce directement dans les méthodes `CPieceAbstract::TurnRight()` et
`CPieceAbstract::TurnLeft()`. En effet, pour la rotation nous ne nous basons pas
sur le traitement séparé de chaque état de la pièce. Nous calculons simplement
la nouvelle position à partir de la matrice de la pièce et du sens de rotation.
Pour faire tourner une pièce vers la droite, il suffit, pour chaque élément de
la matrice, de modifier son ordonnée en son abscisse actuelle, et son abscisse
en la taille de la matrice moins 1 moins son ordonnée. Pour la rotation vers la
gauche, c'est l'inverse. Ce qui nous donne plus formellement :

* Rotation vers droite :
  * newRow = oldCol
  * newCol = size-1 - oldRow
* Rotation vers la gauche :
  * newRow = size-1 - oldCol
  * newCol = oldRow

L'intérêt est d'avoir une méthode générique à toutes les pièces, plutôt que de
faire une disjonction de cas pour chaque sens (Top, Right, Bottom, Left) de
chaque pièce (I, L1, L2, 0, T, Z1, Z2). Nous avons ainsi deux cas à gérer au
lieu de 21 (`4×6 - 3`, la pièce O étant "insensible" à la rotation).

### Génération aléatoire des pièces

Ayant du mal à cerner le but de la classe CRandomizer et comment l'utiliser,
nous avons fait le choix d'utiliser la fonction `rand()` de C++. Nous générons
un nombre entre 0 et 6 associé arbitrairement à une pièce.

Au niveau des couleurs nous avons aussi généré le taux de rouge, vert et bleu
aléatoirement. L'inconvénient est que le contraste entre la pièce et le fond
peut être un peu faible. Celà rajoute un peu de "difficulté" au jeu. Ce serait
intéressant d'évaluer ce contraste et regénérer la couleur s'il est jugé trop
faible par l'algorithme. Dans la grande majorité des cas, la pièce est tout de
même bien visible.

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
Lance l'intégralité des tests en mode console (seulement `make testPiece`
actuellement).

## Fonctionnalités à implémenter (Todo list)

* Afficher la prochaine pièce au dessus du score.
* Permettre de recommencer une partie après un Game Over.
* Ajouter du son.

## Bugs connus

### Gestion de l'aléatoire

Lorsque les pièces défilent très rapidement (niveau élevé ou lorsqu'on laisse
enfoncé la touche `↓`), la forme et la couleur des pièces ne change pas.

