#pragma once

#include "CommonTypes.h"

#include <SDL.h>
#include <memory.h>

struct ChessPiece
{
public:
	ChessPiece(const common::ChessPieceColor& color,
			   const common::ChessPieceType& type);

	common::ChessPieceColor m_color;
	common::ChessPieceType m_type;
};

using chessPieceUPtr_t = std::unique_ptr<ChessPiece>;