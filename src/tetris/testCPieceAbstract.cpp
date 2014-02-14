/**
 * Projet TetrisAP8
 *
 * Classe de test de CPieceAbstract.
 */

#include "test.h"
#include "CPieceAbstract.h"

int main(int argc, char* argv[]) {

  int nbErrors = 0;
  bool testPass;

  CPieceAbstract cpa_1;
  unsigned int dim_1;
  int iX_1;
  int iY_1;

  cout << "Test CPieceAbstract:" << endl;
  cout << "CPieceAbstract(unsigned int, int, int)" << endl;

  dim_1 = 4;
  iX_1  = 7;
  iY_1  = 10;
  cpa_1 = CPieceAbstract(dim_1, iX_1, iY_1);

  testPass = cpa_1->GetTable().size() == dim_1;
  testPass &= cpa_1->GetColIndex() == iX_1;
  testPass &= cpa_1->GetRowIndex() == iY_1;

  if (!testPass) nbErrors++;

  printTestResult("("+ dim_1 +", "+ iX_1 +", "+ iY_1 +")", testPass);

  return nbErrors;
}
