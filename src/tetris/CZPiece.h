
#ifndef __CZPIECE_H__
#define __CZPIECE_H__

#include "CPieceAbstract.h"

class CZPiece : public CPieceAbstract {

  public:
    CZPiece(int iX, int iY, const CVector3& color);
};

#endif
