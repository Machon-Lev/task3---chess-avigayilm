#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int SIZE_B = 8;
const bool WHITE = 0;
const bool BLACK = 1;


class Piece {
	bool color;
	char piece;
public:
	Piece(bool color, char piece);
	virtual bool isLegal(int srcRow, int srcCol, int destRow, int destCol, Piece* const (&board)[SIZE_B][SIZE_B])const = 0;
	Piece* getPiece() { return NULL; }	
	bool getColor() { return color; }
	char getKindPiece() { return piece; }
};

