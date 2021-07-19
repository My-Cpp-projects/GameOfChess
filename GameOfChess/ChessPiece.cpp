#include "ChessPiece.h"

ChessPiece::ChessPiece(const common::ChessPieceColor& color,
					   const common::ChessPieceType& type)
	: m_color(color)
	, m_type(type)
{
}