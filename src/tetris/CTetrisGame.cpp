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

  //AddPiece();
  this->m_pPiece = new COPiece(0, 0, CVector3(0, 0, 0));
  InsertPiece();
  this->m_pPiece = new COPiece(2, 0, CVector3(0, 0, 0));
  InsertPiece();
  this->m_pPiece = new COPiece(4, 0, CVector3(0, 0, 0));
  InsertPiece();
  this->m_pPiece = new COPiece(6, 0, CVector3(0, 0, 0));
  InsertPiece();
  this->m_pPiece = new COPiece(8, 0, CVector3(0, 0, 0));
  InsertPiece();

  cout << GetFullRow() << endl;
  cout << m_board << endl;
  DeleteRow(GetFullRow());
  cout << m_board << endl;
}

/****************************************/

CTetrisGame::~CTetrisGame(){

}


/****************************************/
void CTetrisGame::AddPiece() {
  this->m_pPiece = new CIPiece(0, 0, CVector3(0, 0, 0));
}

int CTetrisGame::GetFullRow() {
  int i = -1, size = m_board.GetGameTable().size();
  bool isFull = true;

  do {
      i++;
      for(unsigned int j=0; j < m_board.GetGameTable()[i].size() && isFull; j++)
        isFull &= m_board.GetGameTable()[i][j].m_used;

  } while(i < size && !isFull);

  return (isFull) ? i : -1;
}

void CTetrisGame::DeleteRow(unsigned int rowIndex) {
  unsigned int i, size = m_board.GetGameTable().size();

  if(size < rowIndex && 0 <= rowIndex)
    for(i=rowIndex; (i < size && i+1 < size); i++)
      m_board.GetGameTable()[i] = m_board.GetGameTable()[i+1];
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


