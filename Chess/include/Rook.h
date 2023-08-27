#pragma once
#include "Piece.h"

class Board;
class Rook : public Piece
{
public:
	Rook(bool color);

	virtual bool isLegal(int srcRow, int srcCol, int destRow, int destCol, Piece** Board)const;

};


