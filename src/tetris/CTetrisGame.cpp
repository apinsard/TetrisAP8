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

  m_xPos     = gamePosX;
  m_yPos     = gamePosY;
  m_caseDim  = dimCase;
  m_score    = 0;
  m_pPiece   = NULL;
  m_gameOver = false;
}

/****************************************/

CTetrisGame::~CTetrisGame(){
  if(m_pPiece)
    delete m_pPiece;
}


/****************************************/
void CTetrisGame::AddPiece() {
  srand(time(NULL));

  float red   = (rand()%256)/255.0f;
  float green = (rand()%256)/255.0f;
  float blue  = (rand()%256)/255.0f;
  CVector3 color = CVector3(red, green, blue);

  unsigned int posX = 3;
  unsigned int posY = 19;

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
  for (unsigned int i=0; i < m_board.GetGameTable().size(); i++) {
    bool isFull = true;
    for (unsigned int j=0; j < m_board.GetGameTable()[i].size(); j++) {
      if (!m_board.GetGameTable()[i][j].m_used) {
        isFull = false;
        break;
      }
    }
    if (isFull)
      return i;
  }

  return -1;
}

void CTetrisGame::DeleteRow(unsigned int rowIndex) {
  vector<TGameRow> &gameTable = this->m_board.GetGameTable();
  if (0 <= rowIndex && rowIndex < gameTable.size()) {
    // On descend toutes les lignes au dessus
    for (unsigned int i=rowIndex; i+1 < gameTable.size(); i++)
      gameTable[i] = gameTable[i+1];

    // Et on vide la ligne du haut
    for (unsigned int i=0; i<gameTable[gameTable.size()-1].size(); i++)
      gameTable[gameTable.size()-1][i].m_used = false;

    m_score += 42;
  }
}

bool CTetrisGame::IsGameOver() {
  unsigned int topIndex =
    this->m_pPiece->GetRowIndex()+this->m_pPiece->GetDim()-1;
    m_gameOver = (topIndex >= this->m_board.GetGameTable().size());
  return m_gameOver;
}

ActionResult CTetrisGame::MovePiece(PieceAction action) {
  if(m_gameOver)
    return AR_Ok;

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
    case PA_MoveBottom2:
      while (MovePiece(PA_MoveBottom) == AR_Ok);
      return MovePiece(PA_MoveBottom);
    case PA_MoveBottom:
      this->m_pPiece->SetIncDecRowIndex(-1);
      break;
  }

  this->CheckBorderCollision();

  if (this->CheckCollision()) {
    switch(action) {
      case PA_RotateRight:
        this->m_pPiece->TurnLeft();
        break;
      case PA_RotateLeft:
        this->m_pPiece->TurnRight();
        break;
      case PA_MoveRight:
        this->m_pPiece->SetIncDecColIndex(-1);
        break;
      case PA_MoveLeft:
        this->m_pPiece->SetIncDecColIndex(1);
        break;
      case PA_MoveBottom:
        this->m_pPiece->SetIncDecRowIndex(1);

        if (this->IsGameOver()) {
          return AR_GameOver;
        }
        return AR_Collision;
    }
  }

  return AR_Ok;
}

ActionResult CTetrisGame::Update(unsigned int step) {
  if (step != 0)
    return AR_Ok;

  if(m_gameOver)
    return AR_GameOver;

  if (!this->m_pPiece) {
    this->AddPiece();
    return AR_Ok;
  }

  ActionResult ar = this->MovePiece(PA_MoveBottom);
  if (ar == AR_Collision) {
    this->InsertPiece();
    while (this->GetFullRow() != -1 ) {
      this->DeleteRow(this->GetFullRow());
    }
    this->AddPiece();
  }

  return ar;
}

void CTetrisGame::InsertPiece() {
  for(unsigned int i=0; i<this->m_pPiece->GetDim(); i++) {
    for(unsigned int j=0; j<this->m_pPiece->GetDim(); j++) {
      if (this->m_pPiece->GetTable()[i][j] == 1) {
        Case pieceCase    = Case();
        pieceCase.m_used  = true;
        pieceCase.m_color = this->m_pPiece->GetColor();

        this->m_board.setCase(this->m_pPiece->GetRowIndex()+i, this->m_pPiece->GetColIndex()+j, pieceCase);
      }
    }
  }
  delete this->m_pPiece;
  this->m_pPiece = NULL;
}

bool CTetrisGame::CheckBorderCollision() {
  int leftIndex = 0;
  for (unsigned int col=0; col<m_pPiece->GetDim(); col++) {
    for (unsigned int row=0; row<m_pPiece->GetDim(); row++) {
      if (m_pPiece->GetTable()[row][col] == 1) {
        // L'index est la colonne la plus à gauche comportant au moins un 1.
        leftIndex = col;
        // Et on quitte les boucles
        col = m_pPiece->GetDim();
        break;
      }
    }
  }
  leftIndex += m_pPiece->GetColIndex();

  if (leftIndex < 0) {
    // Débordement par la gauche
    this->m_pPiece->SetIncDecColIndex(-1*leftIndex);
    return true;
  }

  unsigned int width = this->m_board.GetGameTable()[0].size();
  unsigned int rightIndex = this->m_pPiece->GetDim() - 1;

  for (unsigned int col=m_pPiece->GetDim(); col>0; col--) {
    for (unsigned int row=0; row<m_pPiece->GetDim(); row++) {
      if (m_pPiece->GetTable()[row][col-1] == 1) {
        // L'index est la colonne la plus à droite comportant au moins un 1.
        rightIndex = col-1;
        // Et on quitte les boucles
        col = 1;
        break;
      }
    }
  }
  rightIndex += m_pPiece->GetColIndex();

  if (rightIndex >= width) {
    // Débordement par la droite
    this->m_pPiece->SetIncDecColIndex(width-rightIndex-1);
    return true;
  }

  return false;
}

bool CTetrisGame::CheckCollision() {
  // On vérifie la collision avec le bord inférieur
  int bottomIndex = 0;
  for (unsigned int row=0; row<m_pPiece->GetDim(); row++) {
    for (unsigned int col=0; col<m_pPiece->GetDim(); col++) {
      if (m_pPiece->GetTable()[row][col] == 1) {
        // L'index est la ligne la plus basse comportant au moins un 1.
        bottomIndex = row;
        // Et on quitte les boucles
        row = m_pPiece->GetDim();
        break;
      }
    }
  }
  bottomIndex += m_pPiece->GetRowIndex();
  if (bottomIndex < 0)
    return true; // La pièce a atteint le bord inférieur

  // On vérifie la collision avec les autres pièces.
  for (unsigned int i=0; i<m_pPiece->GetDim(); i++) {
    for (unsigned int j=0; j<m_pPiece->GetDim(); j++) {
      if (m_pPiece->GetTable()[i][j] == 1) {
        unsigned int x = m_pPiece->GetColIndex()+j;
        unsigned int y = m_pPiece->GetRowIndex()+i;

        if (y < m_board.GetGameTable().size()
            && x < m_board.GetGameTable()[0].size()
            && m_board.GetGameTable()[y][x].m_used)
        {
          return true;
        }
      }
    }
  }

  return false;
}

/****************************************/
CTGameTable&    CTetrisGame::GetBoard()    { return m_board; }
unsigned int    CTetrisGame::GetXPos()     { return m_xPos; }
unsigned int    CTetrisGame::GetYPos()     { return m_yPos; }
float&          CTetrisGame::GetCaseDim()  { return m_caseDim; }
unsigned int    CTetrisGame::GetScore()    { return m_score; }
CPieceAbstract* CTetrisGame::GetPiece()    { return m_pPiece; }

