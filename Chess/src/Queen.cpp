#include "Queen.h"


Queen::Queen(bool color) :Piece(color) {}

bool Queen::isLegal(int srcRow, int srcCol, int destRow, int destCol, const Piece** board)const
{
    int rowDiff = abs(destRow - srcRow);
    int colDiff = abs(destCol - srcCol);

    // Check if the move is along a straight line
    if (rowDiff != 0 && colDiff != 0 && rowDiff != colDiff) {
        return false;
    }

    // Check for obstacles along the path
    int rowStep = (destRow - srcRow) / rowDiff;
    int colStep = (destCol - srcCol) / colDiff;

    int currentRow = srcRow + rowStep;
    int currentCol = srcCol + colStep;

    while (currentRow != destRow || currentCol != destCol) {
        if (board[currentRow][currentCol] != nullptr) {
            return false; // Obstacle found along the path
        }
        currentRow += rowStep;
        currentCol += colStep;
    }

    return true; // Valid move for a queen
}
