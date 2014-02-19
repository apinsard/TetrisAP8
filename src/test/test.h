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
 *
 */
string fillLine(string begin, string end);

/**
 *
 */
string fillLine(string begin);

/**
 *
 */
string formatResult(int depth, string label, bool success);

/**
 *
 */
void printTestResult(string label, bool success);

void testPieceCli(string pieceT, string pieceR, string pieceB, string pieceL,
    CPieceAbstract piece);

#endif
