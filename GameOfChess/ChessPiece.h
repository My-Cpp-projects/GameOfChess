#pragma once

#include "CommonTypes.h"

#include <SDL.h>
#include <memory.h>
#include <iostream>

struct ChessPiece
{
public:
	ChessPiece(const common::ChessPieceColor& color,
			   const common::ChessPieceType& type);

	~ChessPiece();

	common::ChessPieceColor m_color;
	common::ChessPieceType m_type;
};

using chessPieceUPtr_t = std::unique_ptr<ChessPiece>;