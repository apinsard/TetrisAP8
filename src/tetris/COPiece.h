
#ifndef __COPIECE_H__
#define __COPIECE_H__

#include "CPieceAbstract.h"

class COPiece : public CPieceAbstract {

  public:
    COPiece(int iX, int iY, const CVector3& color);
    void Turn();
};

#endif
