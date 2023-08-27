#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const bool WHITE = 0;
const bool BLACK = 1;
const int SIZE = 8;

class Piece {
	bool color;
public:
	Piece(bool color);
	virtual bool isLegal(int srcRow, int srcCol, int destRow, int destCol, Piece** Board)const = 0;
	Piece* getPiece() { return NULL; }	
	bool getColor() { return color; }
};

