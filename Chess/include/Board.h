#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <cctype>

#include "King.h"
#include "Bishop.h"
#include "Rook.h"
#include "Queen.h"
#include "Piece.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;

enum Code
{
	EMPTY_LOCATION = 11,
	ENEMY………_MOVE = 12,
	DEST_IS_FULL = 13,
	ILLEGAL_MOVE = 21,
	SELF_CHECK = 31,
	LEGAL_MOVE = 42,
	LEGAL_CHECK = 41
};

class Board
{
	Piece* board[SIZE][SIZE];
	bool turn;
	
public:

	Board(string boardstr);
	Piece* InitializePiece(char c, bool color);
	bool getColor(char &c);
	Piece* getPiece(string position);
	int movePiece(string place);
	int validate_before(int curr_row, int curr_col, int dest_row, int dest_col);
	int validate_after();
	bool IsCheck()const;
	~Board();
};

Board::Board(string boardstr)
{
	for (int row = 0; row < SIZE; row++)
	{
		for (int col = 0; col < SIZE; col++)
		{
			char pieceChar = boardstr[row * SIZE + col];
			bool color = getColor(pieceChar);
			if (pieceChar=='#')
			{
				board[row][col] = nullptr;
			}
			else
			{
				board[row][col] = InitializePiece(pieceChar,color);
			}

		}
		
	}
}

Board::~Board()
{
	for (size_t i = 0; i < SIZE; i++)
		for (size_t j = 0; j < SIZE; j++)
			if (board[i][j])
				delete board[i][j];
}

/*
* 	EMPTY_LOCATION = 11,
	ENEMY………_MOVE = 12,
	DEST_IS_FULL = 13,
	ILLEGAL_MOVE = 21,
	SELF_CHECK = 31,
	LEGAL_MOVE = 42,
	LEGAL_CHECK = 41
*/




bool Board::getColor(char &c)
{
	if (isupper(c))
	{
		c = tolower(c);
		return WHITE;
	}
	else
		return BLACK;
}

Piece* Board::InitializePiece(char c, bool color)
{
	Piece* piece = nullptr;
	switch (c)
	{
	case 'b':
		piece = new Bishop(color);
		break;
	case 'k':
		piece = new King(color);
		break;
	case 'q':
		piece = new Queen(color);
		break;
	case 'r':
		piece = new Rook(color);
		break;
	}
	return piece;
}

Piece* Board::getPiece(string userInput)
{
	char srcFile = userInput[0];
	int srcRank = userInput[1] - '0';
	int srcCol = srcFile - 'a';
	int srcRow = srcRank - 1;
	Piece* piece = board[srcRow][srcCol];
	return piece;


}

