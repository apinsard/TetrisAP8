#include "CTPiece.h"
#include "test.h"

int main(int argc, char* argv[]) {

  cout << "Création d'une pièce en T :" << endl;
  CTPiece piece = CTPiece(1, 1, CVector3(1, 1, 1));
  cout << piece << endl;

  cout << "Rotation de la pièce vers la droite :" << endl;
  piece.TurnRight();
  cout << piece << endl;

  cout << "Rotation de la pièce vers la droite :" << endl;
  piece.TurnRight();
  cout << piece << endl;

  cout << "Rotation de la pièce vers la gauche :" << endl;
  piece.TurnLeft();
  cout << piece << endl;

  return 0;
}
