
#ifndef __CTPIECE_H__
#define __CTPIECE_H__

#include "CPieceAbstract.h"

class CTPiece : public CPieceAbstract {

  public:
    CTPiece(int iX, int iY, const CVector3& color);
    void Turn();
};

#endif
