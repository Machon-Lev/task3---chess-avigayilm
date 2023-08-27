#pragma once
#include "Piece.h"

class Board;
class Queen : public Piece
{
public:
	Queen(bool color);
    virtual bool isLegal(int srcRow, int srcCol, int destRow, int destCol, Piece* const (&board)[SIZE_B][SIZE_B])const;
};
