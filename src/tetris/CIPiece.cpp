
#include "CIPiece.h"

CIPiece::CIPiece(int iX, int iY, const CVector3& color) :
    CPieceAbstract(4, iX, iY, color)
{

  TPieceRow row = TPieceRow(4, 0);

  row[0] = 0; row[1] = 1; row[2] = 0; row[3] = 0;
  this->m_table[3] = row;
  row[0] = 0; row[1] = 1; row[2] = 0; row[3] = 0;
  this->m_table[2] = row;
  row[0] = 0; row[1] = 1; row[2] = 0; row[3] = 0;
  this->m_table[1] = row;
  row[0] = 0; row[1] = 1; row[2] = 0; row[3] = 0;
  this->m_table[0] = row;

}

void CIPiece::Turn() {
  this->TurnRight();
}
