#include "Piece.h"


class Queen : public Piece
{
public:
	Queen(bool color);
    virtual bool isLegal(int srcRow, int srcCol, int destRow, int destCol, Piece** Board)const;
};
