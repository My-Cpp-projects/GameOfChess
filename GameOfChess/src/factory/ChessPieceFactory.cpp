#include "factory/ChessPieceFactory.h"

#include <map>
#include <functional>

chessPieceUPtr_t createKing(const common::ChessPieceColor& color)
{
	return std::make_unique<ChessPiece>(color, common::ChessPieceType::KING);
}

chessPieceUPtr_t createQueen(const common::ChessPieceColor& color)
{
	return std::make_unique<ChessPiece>(color, common::ChessPieceType::QUEEN);
}

chessPieceUPtr_t createBishop(const common::ChessPieceColor& color)
{
	return std::make_unique<ChessPiece>(color, common::ChessPieceType::BISHOP);
}

chessPieceUPtr_t createKnight(const common::ChessPieceColor& color)
{
	return std::make_unique<ChessPiece>(color, common::ChessPieceType::KNIGHT);
}

chessPieceUPtr_t createRook(const common::ChessPieceColor& color)
{
	return std::make_unique<ChessPiece>(color, common::ChessPieceType::ROOK);
}

chessPieceUPtr_t createPawn(const common::ChessPieceColor& color)
{
	return std::make_unique<ChessPiece>(color, common::ChessPieceType::PAWN);
}

using creator = std::function<chessPieceUPtr_t(const common::ChessPieceColor&)>;
const std::map<common::ChessPieceType, creator> PIECE_CREATION_FUNCTION_MAP =
{
	{common::ChessPieceType::KING, &createKing},
	{common::ChessPieceType::QUEEN, &createQueen},
	{common::ChessPieceType::BISHOP, &createBishop},
	{common::ChessPieceType::KNIGHT, &createKnight},
	{common::ChessPieceType::ROOK, &createRook},
	{common::ChessPieceType::PAWN, &createPawn},
};

chessPieceUPtr_t chessPieceFactory::createPiece(const common::ChessPieceType& type,
												const common::ChessPieceColor& color)
{
	return PIECE_CREATION_FUNCTION_MAP.at(type)(color);
}