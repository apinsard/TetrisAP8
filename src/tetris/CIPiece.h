
#ifndef __CIPIECE_H__
#define __CIPIECE_H__

#include "CPieceAbstract.h"

class CIPiece : public CPieceAbstract {

  public:
    CIPiece(int iX, int iY, const CVector3& color);
    void Turn();
};

#endif
