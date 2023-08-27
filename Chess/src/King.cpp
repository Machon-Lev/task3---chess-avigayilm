#include "King.h"

King::King(bool color) :Piece(color,'k') {}
bool King::isLegal(int srcRow, int srcCol, int destRow, int destCol, Piece* const (&board)[8][8])const
{
	int rowDiff = abs(destRow - srcRow);
	int colDiff = abs(destCol - srcCol);
	return (rowDiff <= 1 && colDiff <= 1);

}