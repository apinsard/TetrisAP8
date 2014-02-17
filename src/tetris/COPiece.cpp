
#include "COPiece.h"

COPiece::COPiece(int iX, int iY, const CVector3& color) :
    CPieceAbstract(2, iX, iY, color)
{

  TPieceRow row = TPieceRow(2, 0);

  row[0] = 1; row[1] = 1;
  this->m_table[1] = row;
  row[0] = 1; row[1] = 1;
  this->m_table[0] = row;

}

void COPiece::Turn() {
  this->TurnRight();
}
