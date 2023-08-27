#pragma once
#include "Piece.h"

class Board;
class Bishop : public Piece
{
public:
    Bishop(bool color);

    virtual bool isLegal(int srcRow, int srcCol, int destRow, int destCol, Piece** Board)const;

};

