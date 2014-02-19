#include "CL1Piece.h"
#include "testCL1Piece/CProjetTetrisPiece.h"
#include "CGuiGlut.h"
#include "test.h"

int main(int argc, char* argv[]) {
  bool gui = true;
  for (int i=0; i<argc; i++) {
    if (string(argv[i]) == "--no-gui")
      gui = false;
  }

  string pieceT = " 0 1 0\n";
         pieceT+= " 0 1 0\n";
         pieceT+= " 0 1 1\n";

  string pieceR = " 0 0 0\n";
         pieceR+= " 1 1 1\n";
         pieceR+= " 1 0 0\n";

  string pieceB = " 1 1 0\n";
         pieceB+= " 0 1 0\n";
         pieceB+= " 0 1 0\n";

  string pieceL = " 0 0 1\n";
         pieceL+= " 1 1 1\n";
         pieceL+= " 0 0 0\n";

  cout << fillLine("Test de la classe CL1Piece") << endl;

  cout << fillLine("  CL1Piece(int, int, const CVector3&)") << endl;

  CL1Piece piece = CL1Piece(0, 0, CVector3(0, 0, 0));

  testPieceCli(pieceT, pieceR, pieceB, pieceL, piece);

  if (gui) {
    CProjetTetrisPiece* tetris = new CProjetTetrisPiece();
    CGuiGlut::InitializeGraphics(argc, argv, tetris);
    CGuiGlut::RunGraphics();
    delete tetris;
  }

  return 0;
}


