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
  m_pPiece  = NULL;
}

/****************************************/

CTetrisGame::~CTetrisGame(){

}


/****************************************/
void CTetrisGame::AddPiece() {
  srand(time(NULL));

  float red   = (rand()%256)/255.0f;
  float green = (rand()%256)/255.0f;
  float blue  = (rand()%256)/255.0f;
  CVector3 color = CVector3(red, green, blue);

  unsigned int posX = 3;
  unsigned int posY = 16;

  switch (rand() % 7) {
    case 0:
      this->m_pPiece = new CTPiece(posX, posY, color);
      break;
    case 1:
      this->m_pPiece = new CIPiece(posX, posY, color);
      break;
    case 2:
      this->m_pPiece = new COPiece(posX, posY, color);
      break;
    case 3:
      this->m_pPiece = new CZ1Piece(posX, posY, color);
      break;
    case 4:
      this->m_pPiece = new CZ2Piece(posX, posY, color);
      break;
    case 5:
      this->m_pPiece = new CL1Piece(posX, posY, color);
      break;
    case 6:
      this->m_pPiece = new CL2Piece(posX, posY, color);
      break;
  }

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
  vector<TGameRow> &gameTable = this->m_board.GetGameTable();
  if (0 <= rowIndex && rowIndex < gameTable.size()) {
    // On descend toutes les lignes au dessus
    for (unsigned int i=rowIndex; i+1 < gameTable.size(); i++)
      gameTable[i] = gameTable[i+1];

    // Et on vide la ligne du haut
    for (unsigned int i=0; i<gameTable[gameTable.size()-1].size(); i++)
      gameTable[gameTable.size()-1][i].m_used = 0;
  }
}

bool CTetrisGame::IsGameOver() {
  unsigned int topIndex =
    this->m_pPiece->GetRowIndex()+this->m_pPiece->GetDim()-1;
  return (topIndex >= this->m_board.GetGameTable().size());
}

ActionResult CTetrisGame::MovePiece(PieceAction action) {
  if (this->IsGameOver())
    return AR_GameOver;
  
  switch (action) {
    case PA_RotateRight:
      this->m_pPiece->TurnRight();
      break;
    case PA_RotateLeft:
      this->m_pPiece->TurnLeft();
      break;
    case PA_MoveRight:
      this->m_pPiece->SetIncDecColIndex(1);
      break;
    case PA_MoveLeft:
      this->m_pPiece->SetIncDecColIndex(-1);
      break;
    case PA_MoveBottom:
      this->m_pPiece->SetIncDecRowIndex(-1);
      break;
    case PA_MoveBottom2:
      this->m_pPiece->SetIncDecRowIndex(-3);
      break;
  }

  return AR_Ok;
}

ActionResult CTetrisGame::Update(unsigned int step) {
  if (step != 0)
    return AR_Ok;

  cout << this->m_pPiece << " ";
  if (!this->m_pPiece) {
    this->AddPiece();
    return AR_Ok;
  }

  return this->MovePiece(PA_MoveBottom);
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
CTGameTable&    CTetrisGame::GetBoard()    { return m_board; }
unsigned int    CTetrisGame::GetXPos()     { return m_xPos; }
unsigned int    CTetrisGame::GetYPos()     { return m_yPos; }
float&          CTetrisGame::GetCaseDim()  { return m_caseDim; }
CPieceAbstract* CTetrisGame::GetPiece()    { return m_pPiece; }


