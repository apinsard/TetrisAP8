#ifndef __CL2PIECE_H__
#define __CL2PIECE_H__

#include "CPieceAbstract.h"

class CL2Piece : public CPieceAbstract {

  public:
    CL2Piece(int iX, int iY, const CVector3& color);
    void Turn();
};

#endif
