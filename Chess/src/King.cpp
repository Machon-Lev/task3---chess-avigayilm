#include "King.h"

King::King(bool color) :Piece(color) {}
bool King::isLegal(int srcRow, int srcCol, int destRow, int destCol, const Piece** board)const
{
	int rowDiff = abs(destRow - srcRow);
	int colDiff = abs(destCol - srcCol);
	return (rowDiff <= 1 && colDiff <= 1);

}