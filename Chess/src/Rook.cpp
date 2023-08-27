#include "Rook.h"

Rook::Rook(bool color): Piece(color,'r') {}

bool Rook::isLegal(int srcRow, int srcCol, int destRow, int destCol, Piece* const (&board)[8][8]) const
{
    int rowDiff = abs(destRow - srcRow);
    int colDiff = abs(destCol - srcCol);

    // Check if the move is along a straight line
    if (rowDiff != 0 && colDiff != 0) {
        return false; // Rook can only move along rows or columns
    }

    // Check for obstacles along the path
    int rowStep = (destRow - srcRow) / (rowDiff == 0 ? 1 : rowDiff);
    int colStep = (destCol - srcCol) / (colDiff == 0 ? 1 : colDiff);

    int currentRow = srcRow + rowStep;
    int currentCol = srcCol + colStep;

    while (currentRow != destRow || currentCol != destCol) {
        if (board[currentRow][currentCol]!=nullptr) {
            return false; // Obstacle found along the path
        }
        currentRow += rowStep;
        currentCol += colStep;
    }

    return true; // Valid move for a rook
}