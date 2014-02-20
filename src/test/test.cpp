#include "test.h"

string fillLine(string begin, string end) {
  int nbSupChars = COL_WIDTH - begin.length() - end.length();

  string result = begin;
  for (int i=0; i < nbSupChars; i++)
    result += FILL_CHAR;
  result += end;

  return result;
}

string fillLine(string begin) {
  return fillLine(begin, "");
}

string formatResult(int depth, string label, bool success) {
  string line;
  string result;
  string color;

  if (success) {
    color = string(COLOR_PASS);
    result = "PASS";
  }
  else {
    color = string(COLOR_FAIL);
    result = "FAIL";
  }

  for (int i=0; i<depth*2; i++)
    label = ' ' + label;
  
  line = fillLine(label, "["+result+"]").substr(0, COL_WIDTH-6);
  line += "["+ color + result + string(COLOR_RESET) +"]";

  return line;
}

void printTestResult(string label, bool success) {
  cout << formatResult(2, label, success) << endl;
}

void testPieceCli(string pieceT, string pieceR, string pieceB, string pieceL,
    CPieceAbstract piece)
{
  ostringstream pout;
  bool success;

  pout << piece;
  success = (pieceT == pout.str());

  printTestResult("(0, 0, CVector3(0, 0, 0))", success);

  cout << fillLine("  TurnRight()") << endl;

  pout.str("");
  pout.clear();
  piece.TurnRight();
  pout << piece;
  success = (pieceR == pout.str());

  printTestResult("from state Top", success);

  pout.str("");
  pout.clear();
  piece.TurnRight();
  pout << piece;
  success = (pieceB == pout.str());

  printTestResult("from state Right", success);

  pout.str("");
  pout.clear();
  piece.TurnRight();
  pout << piece;
  success = (pieceL == pout.str());

  printTestResult("from state Bottom", success);

  pout.str("");
  pout.clear();
  piece.TurnRight();
  pout << piece;
  success = (pieceT == pout.str());

  printTestResult("from state Left", success);

  cout << fillLine("  TurnLeft()") << endl;

  pout.str("");
  pout.clear();
  piece.TurnLeft();
  pout << piece;
  success = (pieceL == pout.str());

  printTestResult("from state Top", success);

  pout.str("");
  pout.clear();
  piece.TurnLeft();
  pout << piece;
  success = (pieceB == pout.str());

  printTestResult("from state Left", success);

  pout.str("");
  pout.clear();
  piece.TurnLeft();
  pout << piece;
  success = (pieceR == pout.str());

  printTestResult("from state Bottom", success);

  pout.str("");
  pout.clear();
  piece.TurnLeft();
  pout << piece;
  success = (pieceT == pout.str());

  printTestResult("from state Right", success);
}


