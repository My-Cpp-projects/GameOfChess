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
			m_data->m_board[boardWidth][boardHeight] = std::make_unique<Tile>(SDL_Point{ boardWidth, boardHeight });
		}
	}

	// set pawns
	for(auto pawnLine : { std::pair<common::ChessPieceColor, int>(m_opponentSide, 1),
						  std::pair<common::ChessPieceColor, int>(m_playerSide, 6) })
	{
		for(int boardWidth = 0; boardWidth < m_data->m_board[pawnLine.second].size(); ++boardWidth)
		{
			m_data->m_board[boardWidth][pawnLine.second]->setPiece(chessPieceFactory::createPiece(common::ChessPieceType::PAWN,
																								  pawnLine.first));
		}
	}

	// set rooks
	for(auto rooks : { std::pair<common::ChessPieceColor, SDL_Point>(m_opponentSide, {0, 0}),
					   std::pair<common::ChessPieceColor, SDL_Point>(m_opponentSide, {7, 0}),
					   std::pair<common::ChessPieceColor, SDL_Point>(m_playerSide, {0, 7}),
					   std::pair<common::ChessPieceColor, SDL_Point>(m_playerSide, {7, 7}) })
	{
		m_data->m_board[rooks.second.x][rooks.second.y]->setPiece(chessPieceFactory::createPiece(common::ChessPieceType::ROOK,
																								 rooks.first));
	}

	// set knights
	for(auto rooks : { std::pair<common::ChessPieceColor, SDL_Point>(m_opponentSide, {1, 0}),
					   std::pair<common::ChessPieceColor, SDL_Point>(m_opponentSide, {6, 0}),
					   std::pair<common::ChessPieceColor, SDL_Point>(m_playerSide, {1, 7}),
					   std::pair<common::ChessPieceColor, SDL_Point>(m_playerSide, {6, 7}) })
	{
		m_data->m_board[rooks.second.x][rooks.second.y]->setPiece(chessPieceFactory::createPiece(common::ChessPieceType::KNIGHT,
																								 rooks.first));
	}

	// set bishops
	for(auto rooks : { std::pair<common::ChessPieceColor, SDL_Point>(m_opponentSide, {2, 0}),
					   std::pair<common::ChessPieceColor, SDL_Point>(m_opponentSide, {5, 0}),
					   std::pair<common::ChessPieceColor, SDL_Point>(m_playerSide, {2, 7}),
					   std::pair<common::ChessPieceColor, SDL_Point>(m_playerSide, {5, 7}) })
	{
		m_data->m_board[rooks.second.x][rooks.second.y]->setPiece(chessPieceFactory::createPiece(common::ChessPieceType::BISHOP,
																								 rooks.first));
	}

	// set queens
	for(auto rooks : { std::pair<common::ChessPieceColor, SDL_Point>(m_opponentSide, {3, 0}),
					   std::pair<common::ChessPieceColor, SDL_Point>(m_playerSide, {3, 7}) })
	{
		m_data->m_board[rooks.second.x][rooks.second.y]->setPiece(chessPieceFactory::createPiece(common::ChessPieceType::QUEEN,
																								 rooks.first));
	}

	// set kings
	for(auto rooks : { std::pair<common::ChessPieceColor, SDL_Point>(m_opponentSide, {4, 0}),
					   std::pair<common::ChessPieceColor, SDL_Point>(m_playerSide, {4, 7}) })
	{
		m_data->m_board[rooks.second.x][rooks.second.y]->setPiece(chessPieceFactory::createPiece(common::ChessPieceType::KING,
																								 rooks.first));
	}
}

BoardData& Board::getData()
{
	return *m_data;
}
