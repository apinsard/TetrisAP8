
#ifndef __CLPIECE_H__
#define __CLPIECE_H__

#include "CPieceAbstract.h"

class CLPiece : public CPieceAbstract {

  public:
    CLPiece(int iX, int iY, const CVector3& color);
};

#endif
