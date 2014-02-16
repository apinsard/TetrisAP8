#include "CLPiece.h"
#include "test.h"

int main(int argc, char* argv[]) {

  cout << "Création d'une pièce en L :" << endl;
  CLPiece piece = CLPiece(0, 0, CVector3(0, 0, 0));
  cout << piece << endl;

  for (int i=0; i<4; i++) {
    cout << "Rotation de la pièce vers la droite :" << endl;
    piece.TurnRight();
    cout << piece << endl;
  }
  for (int i=0; i<4; i++) {
    cout << "Rotation de la pièce vers la gauche :" << endl;
    piece.TurnLeft();
    cout << piece << endl;
  }

  return 0;
}
