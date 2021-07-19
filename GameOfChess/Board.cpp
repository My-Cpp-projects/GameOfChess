#include "Board.h"
#include "ChessPieceFactory.h"

Board::Board()
	: m_data(std::make_unique<BoardData>())
{
	switch(m_playerSide)
	{
		case common::ChessPieceColor::NO_COLOR:
			break;
		case common::ChessPieceColor::BLACK:
		{
			m_opponentSide = common::ChessPieceColor::WHITE;
			break;
		}
		case common::ChessPieceColor::WHITE:
		{
			m_opponentSide = common::ChessPieceColor::BLACK;
			break;
		}
		case common::ChessPieceColor::COUNT:
			break;
	}

	resetBoard();
}

Board::~Board()
{
}

void Board::resetBoard()
{
	for(int boardHeight = 0; boardHeight < m_data->m_board.size(); ++boardHeight)
	{
		for(int boardWidth = 0; boardWidth < m_data->m_board[boardHeight].size(); ++boardWidth)
		{
			m_data->m_board[boardHeight][boardWidth] = std::make_unique<Tile>(SDL_Point{ boardWidth, boardHeight});
		}
	}

	// set pawns
	for(auto pawnLine : { std::pair<common::ChessPieceColor, int>(m_opponentSide, 1),
						  std::pair<common::ChessPieceColor, int>(m_playerSide, 6) })
	{
		for(int boardWidth = 0; boardWidth < m_data->m_board[pawnLine.second].size(); ++boardWidth)
		{
			m_data->m_board[pawnLine.second][boardWidth]->setPiece(chessPieceFactory::createPiece(common::ChessPieceType::PAWN,
																								  pawnLine.first));
		}
	}
	//TODO setup the rest of the board
}

BoardData& Board::getData()
{
	return *m_data;
}
