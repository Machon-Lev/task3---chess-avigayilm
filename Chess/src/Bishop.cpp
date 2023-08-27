#include "Bishop.h"

bool Bishop::isLegal(int srcRow, int srcCol, int destRow, int destCol, const Piece** board) const
{
    int rowDiff = abs(destRow - srcRow);
    int colDiff = abs(destCol - srcCol);

    // Check if the move is along a diagonal
    if (rowDiff != colDiff) {
        return false; // Bishop can only move along diagonals
    }

    // Check for obstacles along the diagonal path
    int rowStep = (destRow - srcRow) / rowDiff;
    int colStep = (destCol - srcCol) / colDiff;

    int currentRow = srcRow + rowStep;
    int currentCol = srcCol + colStep;

    while (currentRow != destRow || currentCol != destCol) {
        if (board[currentRow][currentCol]!=nullptr) {
            return false; // Obstacle found along the path
        }
        currentRow += rowStep;
        currentCol += colStep;
    }

    return true; // Valid move for a bishop
}