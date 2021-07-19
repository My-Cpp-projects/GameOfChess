#include "Board.h"
#include "ChessPieceFactory.h"

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
	//TODO
	//for(int boardHeight = 0; boardHeight < m_data->m_board.size(); ++boardHeight)
	//{
	//	for(int boardWidth = 0; boardWidth < m_data->m_board[boardHeight].size(); ++boardWidth)
	//	{
	//		m_data->m_board[boardHeight][boardWidth] = std::make_unique<Tile>(SDL_Point{boardHeight, boardWidth});

	//		m_data->m_board[boardHeight][boardWidth]->setPiece(chessPieceFactory::createPiece(common::ChessPieceType::PAWN,
	//																						  common::ChessPieceColor::BLACK));
	//	}
	//}

	m_data->m_board[0][0] = std::make_unique<Tile>(SDL_Point{ 0, 0 });

	m_data->m_board[0][0]->setPiece(chessPieceFactory::createPiece(common::ChessPieceType::PAWN,
																						common::ChessPieceColor::BLACK));
}

BoardData& Board::getData()
{
	return *m_data;
}
