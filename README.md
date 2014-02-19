# Tetris - Projet AP8

Sujet de TP de C++ de deuxième année Informatique à l'IUT de Vannes.

Par Julien Cadic et Antoine Pinsard

## Avancement

Les pièces T, I, O, Z1, Z2, L1 et L2 ont été implémentées et testées.

## Tests

Les tests se compilent et s'exécutent en mode console avec la commande `make`.
Chaque test élémentaire comporte une courte description et son statut ([PASS] en
vert si le test s'est bien déroulé, [FAIL] en rouge si le test a échoué). Pour
plus de lisibilité le statut est toujours affiché en fin de ligne (une ligne
faisant 80 caractères).

Voici la liste des tests disponibles :

### `make testC?Piece`

Lance le test de la pièce "?". Par exemple, pour tester la pièce T, lancer la
commande `make testCTPiece`. Pour tester la pièce L2, lancer la commande `make
testCL2Piece`.

Cette commande compile le fichier de test et le lance avec l'argument `--no-gui`
pour n'afficher que le résultat des tests en mode console. Pour tester
l'affichage en mode GUI, il suffit ensuite de lancer le fichier de test sans
arguments (`../bin/testC?Piece.bin` en remplaçant évidemment le ? par la pièce à
tester).

### `make testPiece`
Lance tous les tests des pièces (testCTPiece, testCIPiece, testCOPiece, ...)

### `make test`
Lance l'intégralité des tests en console
