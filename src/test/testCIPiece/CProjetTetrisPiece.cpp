//========================================================================
// Projet C/C++
//
//------------------------------------------------------------------------
// Copyright (c) 2013-2014 Equipe SEASIDE (T. LE NAOUR, J.F KAMP)
// IRISA - UBS  / IUT Informatique Vannes
//========================================================================

#include "CProjetTetrisPiece.h"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Projet Tetris
/////////////////////////////////////////////////////////////////////////////////////////////////////////////

CProjetTetrisPiece::CProjetTetrisPiece() {

  this->m_game = CTetrisGame(
      POSX_BOARD, POSY_BOARD, WIDTH_BOARD, HEIGHT_BOARD, DIM_CASE);

  this->m_pPiece = new CIPiece(0, 0, CVector3(255.0f/255.0f,153.0f/255.0f,153.0f/255.0f));

}

/****************************************/

CProjetTetrisPiece::~CProjetTetrisPiece() {

  cout << "Destruction objet CProjetTetrisPiece" << endl;
  delete[] this->m_pPiece;
}

//----------------------------------------------------------
// initilisation de notre appli (rien car dessiner un cube à l'écran ne nécéssite aucune initialisation)
// !! Méthode appelée dans la méthode Init de la classe CApplication
//----------------------------------------------------------
bool CProjetTetrisPiece::OnInit() {

  return true;
}

//----------------------------------------------------------
// notre scène à dessiner
// !! Méthode appelée dans la méthode Run de la classe CApplication
//----------------------------------------------------------
void CProjetTetrisPiece::OnRender() {

  //-------------------------------------------------------
  // commande utilisateur
  //-------------------------------------------------------
  if(m_UserEvents->m_keyBoardEvents[Key_a])cout << "la touche 'a' a bien été utilisée" << endl;
  if(m_UserEvents->m_keyBoardEvents[Key_z])cout << "la touche 'z' a bien été utilisée" << endl;
  if(m_UserEvents->m_keyBoardEvents[Key_DOWN])cout << "la touche flèche bas a bien été utilisée" << endl;
  if(m_UserEvents->m_keyBoardEvents[Key_RIGHT])cout << "la touche flèche droite a bien été utilisée" << endl;
  if(m_UserEvents->m_keyBoardEvents[Key_LEFT])cout << "la touche flèche gauche a bien été utilisée" << endl;
  if(m_UserEvents->m_keyBoardEvents[Key_SPACE])cout << "la touche espace a bien été utilisée" << endl;

  //-------------------------------------------------------
  // affichage
  //-------------------------------------------------------
  // on passe en rendu 2d
  m_renderer.Start2DRender();

  // affichage du score
  DrawInfo();

  // affichage du tetris
  DrawTetris();

  // fin du rendu 2d
  m_renderer.End2DRender();

}

//----------------------------------------------------------
// destructuion de notre appli (rien car dessiner un cube à l'écran ne nécéssite aucune destruction)
// !! Méthode appelée dans la méthode Release de la classe CApplication
//----------------------------------------------------------
void CProjetTetrisPiece::OnRelease() {

  // Rien a liberer
}	

//----------------------------------------------------------
//
//----------------------------------------------------------
void CProjetTetrisPiece::DrawInfo() 
{
  std::string title = Helpers::ToString("Mon Tetris");
  std::string scoreStr = "Score : " + Helpers::ToString(200000);

  m_renderer.DrawText(title, 300, 500, CRenderer::TS_18, CVector3(1.0f, 1.0f, 1.0f));
  m_renderer.DrawText(scoreStr, 500, 160, CRenderer::TS_12, CVector3(0.0f, 1.0f, 0.0f));	
}

/****************************************/

void CProjetTetrisPiece::DrawTetris() {

  vector<TGameRow> gameTable = m_game.GetBoard().GetGameTable();
  float	tetrisWidth = gameTable[0].size()* m_game.GetCaseDim();
  float	tetrisHeight = gameTable.size() * m_game.GetCaseDim();

  // fond du tetris
  DrawFillRect ( m_game.GetXPos(), m_game.GetYPos(), tetrisWidth, tetrisHeight, CVector3(153.0f/255.0f,153.0f/255.0f,153.0f/255.0f) );
  //DrawFillRect ( m_game.GetXPos(), m_game.GetYPos(), tetrisWidth, tetrisHeight, CVector3(17.0f/255.0f,218.0f/255.0f,84.0f/255.0f) );

  // affichage du "cadre" tetris
  DrawRect ( m_game.GetXPos()-0.1f, m_game.GetYPos()-0.1f, (tetrisWidth+0.2f), (tetrisHeight+0.2f), CVector3(213.0f/255.0f,213.0f/255.0f,213.0f/255.0f) );



  // affichage du tableau tetris


  // affichage de la pîece en cours

  int   x   = this->m_game.GetXPos() + this->m_pPiece->GetColIndex();
  int   y   = this->m_game.GetYPos() + this->m_pPiece->GetRowIndex();
  float dim = this->m_game.GetCaseDim();
  const CVector3 color = this->m_pPiece->GetColor();

  for (unsigned int i=0; i<this->m_pPiece->GetDim(); i++) {
    for (unsigned int j=0; j<this->m_pPiece->GetDim(); j++) {
      if (this->m_pPiece->GetTable()[i][j] == 1)
        DrawFillRect(x+(j*dim), y+(i*dim), dim, dim, color);
    }
  }

}

//----------------------------------------------------------
// quelques outils pour afficher des carré et des rectangles
//----------------------------------------------------------
void CProjetTetrisPiece::DrawFillRect(int x, int y, float w, float h, const CVector3 &color) {

  glColor3f(color.x,color.y,color.z);
  glBegin(GL_QUADS);
  glVertex2i(x, y);
  glVertex2i(x,  y+h);
  glVertex2i(x+w,  y+h);
  glVertex2i(x+w, y);
  glEnd();
}

/****************************************/

void CProjetTetrisPiece::DrawRect(int x, int y, float w, float h, const CVector3 &color, float lineWidth)  {

  glColor3f(color.x,color.y,color.z);
  glLineWidth(lineWidth);
  glBegin(GL_LINES);
  glVertex2f(x, y);
  glVertex2f(x,  y+h);
  glVertex2f(x,  y+h);
  glVertex2f(x+w,  y+h);
  glVertex2f(x+w,  y+h);
  glVertex2f(x+w, y);
  glVertex2f(x+w, y);
  glVertex2f(x, y);
  glEnd();
}

/****************************************/

void CProjetTetrisPiece::DrawFillSquare(int x, int y, float dim, const CVector3 &color)  {

  glColor3f(color.x,color.y,color.z);
  glBegin(GL_QUADS);
  glVertex2f(x, y);
  glVertex2f(x,  y+dim);
  glVertex2f(x+dim,  y+dim);
  glVertex2f(x+dim, y);
  glEnd();
}
