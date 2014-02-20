//========================================================================
// Projet C/C++
//
//------------------------------------------------------------------------
// Copyright (c) 2013-2014 Equipe SEASIDE (T. LE NAOUR, J.F KAMP)
// IRISA - UBS  / IUT Informatique Vannes
//========================================================================

#include "CTetrisGame.h"

/****************************************/
CTetrisGame::CTetrisGame(unsigned int gamePosX, unsigned int gamePosY,
  unsigned int boardWidth, unsigned int boardHeight, float dimCase)
{
  m_board = CTGameTable(boardWidth, boardHeight);  //appel de CTGameTable(int width, int height)

  m_xPos    = gamePosX;
  m_yPos    = gamePosY;
  m_caseDim = dimCase;

  AddPiece();
  InsertPiece();
}

/****************************************/

CTetrisGame::~CTetrisGame(){

}


/****************************************/
void CTetrisGame::AddPiece() {
  srand(time(NULL));

  switch (rand() % 7) {
    case 0:
      this->m_pPiece = new CTPiece(0, 0, CVector3(0, 0, 0));
      break;
    case 1:
      this->m_pPiece = new CIPiece(0, 0, CVector3(0, 0, 0));
      break;
    case 2:
      this->m_pPiece = new COPiece(0, 0, CVector3(0, 0, 0));
      break;
    case 3:
      this->m_pPiece = new CZ1Piece(0, 0, CVector3(0, 0, 0));
      break;
    case 4:
      this->m_pPiece = new CZ2Piece(0, 0, CVector3(0, 0, 0));
      break;
    case 5:
      this->m_pPiece = new CL1Piece(0, 0, CVector3(0, 0, 0));
      break;
    case 6:
      this->m_pPiece = new CL2Piece(0, 0, CVector3(0, 0, 0));
      break;
  }

}

void CTetrisGame::InsertPiece() {
  for(unsigned int i=0; i<this->m_pPiece->GetDim(); i++) {
    for(unsigned int j=0; j<this->m_pPiece->GetDim(); j++) {
      Case pieceCase    = Case();
      pieceCase.m_used  = (this->m_pPiece->GetTable()[i][j] == 1);
      pieceCase.m_color = this->m_pPiece->GetColor();

      this->m_board.setCase(this->m_pPiece->GetRowIndex()+i, this->m_pPiece->GetColIndex()+j, pieceCase);
    }
  }
}

/****************************************/
CTGameTable& CTetrisGame::GetBoard()    { return m_board; }
unsigned int CTetrisGame::GetXPos()     { return m_xPos; }
unsigned int CTetrisGame::GetYPos()     { return m_yPos; }
float&       CTetrisGame::GetCaseDim()  { return m_caseDim; }


