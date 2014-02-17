#ifndef __CZ2PIECE_H__
#define __CZ2PIECE_H__

#include "CPieceAbstract.h"

class CZ2Piece : public CPieceAbstract {

  public:
    CZ2Piece(int iX, int iY, const CVector3& color);
    void Turn();
};

#endif
