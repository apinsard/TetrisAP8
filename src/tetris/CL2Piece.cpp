
#include "CL2Piece.h"

CL2Piece::CL2Piece(int iX, int iY, const CVector3& color) :
    CPieceAbstract(3, iX, iY, color)
{

  TPieceRow row = TPieceRow(3, 0);

  row[0] = 0; row[1] = 1; row[2] = 0;
  this->m_table[2] = row;
  row[0] = 0; row[1] = 1; row[2] = 0;
  this->m_table[1] = row;
  row[0] = 1; row[1] = 1; row[2] = 0;
  this->m_table[0] = row;

}

void CL2Piece::Turn() {
  this->TurnRight();
}
