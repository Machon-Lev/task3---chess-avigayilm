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
	OPPONENT_LOCATION = 12,
	DEST_FULL = 13,
	ILLEGAL_MOVE = 21,
	SELF_CHECK = 31,
	LEGAL_CHECK = 41,
	LEGAL_MOVE = 42,
};

class Board
{
	Piece* board[SIZE_B][SIZE_B];
	bool turn;
	
public:

	Board(string boardstr);
	Piece* InitializePiece(char c, bool color);
	bool getColor(char &c);
	Piece* getPiece(string position);
	int movePiece(string place);
	int validateBefore(int curr_row, int curr_col, int dest_row, int dest_col);
	int validateAfter(int curr_row, int curr_col, int dest_row, int dest_col);
	bool isCheck(bool turn)const;
	~Board();
};
