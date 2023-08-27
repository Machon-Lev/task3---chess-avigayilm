#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include "Piece.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


class King : public Piece
{
public:
	King(bool color);
	bool isLegal(int srcRow, int srcCol, int destRow, int destCol, Piece** Board)const;
};



