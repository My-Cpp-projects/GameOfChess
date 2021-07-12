#include "Board.h"

Board::Board()
	: m_data(std::make_unique<BoardData>())
{
	resetBoard();
}

Board::~Board()
{

}

void Board::resetBoard()
{
	m_data->m_board = STARTING_BOARD;
}

BoardData& Board::getData()
{
	return *m_data;
}
