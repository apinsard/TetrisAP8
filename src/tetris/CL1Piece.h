#ifndef __CL1PIECE_H__
#define __CL1PIECE_H__

#include "CPieceAbstract.h"

class CL1Piece : public CPieceAbstract {

  public:
    CL1Piece(int iX, int iY, const CVector3& color);
    void Turn();
};

#endif
