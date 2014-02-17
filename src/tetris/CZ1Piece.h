#ifndef __CZ1PIECE_H__
#define __CZ1PIECE_H__

#include "CPieceAbstract.h"

class CZ1Piece : public CPieceAbstract {

  public:
    CZ1Piece(int iX, int iY, const CVector3& color);
    void Turn();
};

#endif
