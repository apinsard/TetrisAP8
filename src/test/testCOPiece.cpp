#include "COPiece.h"
#include "testCOPiece/CProjetTetrisPiece.h"
#include "CGuiGlut.h"
#include "test.h"

int main(int argc, char* argv[]) {
  bool gui = true;
  for (int i=0; i<argc; i++) {
    if (string(argv[i]) == "--no-gui")
      gui = false;
  }

  string pieceT = " 1 1\n";
         pieceT+= " 1 1\n";

  string pieceR = " 1 1\n";
         pieceR+= " 1 1\n";

  string pieceB = " 1 1\n";
         pieceB+= " 1 1\n";

  string pieceL = " 1 1\n";
         pieceL+= " 1 1\n";

  cout << fillLine("Test de la classe COPiece") << endl;
  cout << fillLine("  COPiece(int, int, const CVector3&)") << endl;

  COPiece piece = COPiece(0, 0, CVector3(0, 0, 0));

  testPieceCli(pieceT, pieceR, pieceB, pieceL, piece);

  if (gui) {
    CProjetTetrisPiece* tetris = new CProjetTetrisPiece();
    CGuiGlut::InitializeGraphics(argc, argv, tetris);
    CGuiGlut::RunGraphics();
    delete tetris;
  }

  return 0;
}
