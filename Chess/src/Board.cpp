#include "Board.h"

/// <summary>
/// Initialize the board according to the string
/// </summary>
/// <param name="boardstr"></param>
Board::Board(string boardstr) :turn(false)
{
	for (int row = 0; row < SIZE_B; row++)
	{
		for (int col = 0; col < SIZE_B; col++)
		{
			char pieceChar = boardstr[row * SIZE_B + col];
			bool color = getColor(pieceChar);
			if (pieceChar == '#')
			{
				board[row][col] = nullptr;
			}
			else
			{
				board[row][col] = InitializePiece(pieceChar, color);
			}

		}

	}
}

/// <summary>
/// destructor to delete board
/// </summary>
Board::~Board()
{
	for (int i = 0; i < SIZE_B; i++)
		for (int j = 0; j < SIZE_B; j++)
			if (board[i][j])
				delete board[i][j];
}

/// <summary>
/// check if the move is legal before executing it
/// </summary>
/// <param name="curr_row"></param>
/// <param name="curr_col"></param>
/// <param name="dest_row"></param>
/// <param name="dest_col"></param>
/// <returns></returns>
/// 
int Board::validateBefore(int curr_row, int curr_col, int dest_row, int dest_col)
{
	if (board[curr_row][curr_col] == nullptr)
		return EMPTY_LOCATION;
	//check if it's your turn
	if (turn != board[curr_row][curr_col]->getColor())
		return OPPONENT_LOCATION;
	if (board[dest_row][dest_col] != nullptr && board[dest_row][dest_col]->getColor() == turn)
		return DEST_FULL;
	//check wiht polymorphism if the move is legal
	if (!board[curr_row][curr_col]->isLegal(curr_row, curr_col, dest_row, dest_col, board))
		return ILLEGAL_MOVE;
	// if its legal
	return 1;
}

/// <summary>
/// moving the piece to the corrected spot if possible
/// </summary>
/// <param name="place"></param>
/// <returns></returns>

int Board::movePiece(string place)
{
	//check if valid input
	if (place.size() != 4)
		return -1;
	int curr_row = place[0] - 'a';
	int curr_col = place[1] - '0' - 1;
	int dest_row = place[2] - 'a';
	int dest_col = place[3] - '0' - 1;


	int validationCode = validateBefore(curr_row, curr_col, dest_row, dest_col);
	// if the move is valid so far, keep checking
	if (validationCode == 1) {
		// we still need to check afetr, so we save the original place for now
		Piece* temp = board[dest_row][dest_col];
		//move the piece according tto thte string given
		board[dest_row][dest_col] = board[curr_row][curr_col];
		board[curr_row][curr_col] = nullptr;

		//check if everything is valid after the piece is moved

		validationCode = validateAfter(curr_row, curr_col, dest_row, dest_col);
		if (validationCode != LEGAL_CHECK && validationCode != LEGAL_MOVE) {
			// if the move wasn't legal we go back to how it was
			board[curr_row][curr_col] = board[dest_row][dest_col];
			board[dest_row][dest_col] = temp;
		}
		else {
			if (temp)
				delete temp;
			temp = nullptr;
			//change the turn
			turn = !turn;
		}
	}
	return validationCode;
}

/// <summary>
/// checks if there is check for the color given as parameter
/// </summary>
/// <param name="turn"></param>
/// <returns></returns>

bool Board::isCheck(bool turn)const
{
	int k_row = -1;
	int k_col = -1;
	// find the king of the color
	for (int i = 0; i < SIZE_B; i++)
		for (int j = 0; j < SIZE_B; j++)
			if (board[i][j] && ((board[i][j]->getKindPiece() == 'k' && board[i][j]->getColor() == turn))) {
				k_row = i;
				k_col = j;
			}
	if (k_col < 0 || k_row < 0)
		return false;
	for (int i = 0; i < SIZE_B; i++)
	{
		for (int j = 0; j < SIZE_B; j++)
		{
			//chec for very piece fo the other team, if they makecheckmate
			if (board[i][j] && board[i][j]->getColor() != turn)
				//if the ohter team can eat our king it is check.
				if (board[i][j]->isLegal(i, j, k_row, k_col, board))
					return true;
		}
	}
	// if it was never check than htere is no check
	return false;
}

/// <summary>
/// Validate the move was legal after it was done
/// </summary>
/// <param name="curr_row"></param>
/// <param name="curr_col"></param>
/// <param name="dest_row"></param>
/// <param name="dest_col"></param>
/// <returns></returns>
int Board::validateAfter(int curr_row, int curr_col, int dest_row, int dest_col)
{
	//check if after the move was made, any of the players has check
	if (isCheck(turn))
		return SELF_CHECK;
	if (isCheck(!turn))
		return LEGAL_CHECK;
	return LEGAL_MOVE;
}



/// <summary>
/// Gets the color of the piece according to if it's a capital letter or not
/// </summary>
/// <param name="c"></param>
/// <returns></returns>
bool Board::getColor(char& c)
{
	if (isupper(c))
	{
		c = tolower(c);
		return WHITE;
	}
	else
		return BLACK;
}

/// <summary>
/// initialize the piece according to the lettter
/// </summary>
/// <param name="c"></param>
/// <param name="color"></param>
/// <returns></returns>
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

