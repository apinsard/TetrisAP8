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
	m_board = CTGameTable(boardWidth, boardHeight);	//appel de CTGameTable(int width, int height)

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
	m_curPiece = CIPiece(0, 0, CVector3(0, 0, 0));
}

void CTetrisGame::InsertPiece() {
	for(unsigned int i=0; i<m_curPiece.GetDim()) {
		for(unsigned int j=0; j<m_curPiece.GetDim(); j++) {
			Case pieceCase    = Case();
			pieceCase.m_used  = (m_curPiece.GetTable()[i][j] == 1);
			pieceCase.m_color = m_curPiece.GetColor();

			m_board.setCase(i, j, pieceCase);
		}
	}

}

/****************************************/
CTGameTable& CTetrisGame::GetBoard()    { return m_board; }
unsigned int CTetrisGame::GetXPos()     { return m_xPos; }
unsigned int CTetrisGame::GetYPos()     {	return m_yPos; }
float&       CTetrisGame::GetCaseDim()  { return m_caseDim; }


