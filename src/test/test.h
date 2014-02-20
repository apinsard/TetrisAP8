#ifndef __TEST_H__
#define __TEST_H__

#define COL_WIDTH   80
#define FILL_CHAR   '.'
#define COLOR_RESET "\033[0m"
#define COLOR_PASS  "\033[1;32m"
#define COLOR_FAIL  "\033[1;31m"

#include <iostream>
#include <string>
#include "CPieceAbstract.h"

using namespace std;

/**
 * \brief Remplit une ligne avec des points entre le début et la fin de manière
 * à ce qu'elle fasse exactement COL_WIDTH caractères.
 */
string fillLine(string begin, string end);

/**
 * \brief Remplit une ligne avec des points à la fin de manière à ce qu'elle
 * fasse exactement COL_WIDTH caractères.
 */
string fillLine(string begin);

/**
 * \brief Formate un résultat (échec ou succès) avec la méthode fillLine. Si le
 * résultat est un succès, on ajoute [PASS] en vert à la fin. Dans le cas
 * contraire, on ajoute [FAIL] en vert à la fin.
 *
 * \param depth le niveau d'indentation de la ligne
 * \param label le libellé du test
 */
string formatResult(int depth, string label, bool success);

/**
 * \brief Affiche à l'écran formatResult avec un niveau d'indentation de 2 (cas
 * le plus usuel).
 */
void printTestResult(string label, bool success);

/**
 * \brief Test une pièce du jeu en mode console.
 * \param pieceT la représentation sous forme de string de la pièce dans l'état
 * TOP.
 * \param pieceR la représentation de la pièce dans l'état RIGHT
 * \param pieceB la représentation de la pièce dans l'état BOTTOM
 * \param pieceL la représentation de la pièce dans l'état LEFT
 * \param piece la pièce a tester
 */
void testPieceCli(string pieceT, string pieceR, string pieceB, string pieceL,
    CPieceAbstract piece);

#endif
