#pragma once

#include "ChessPiece.h"
#include "CommonTypes.h"

namespace chessPieceFactory
{
	chessPieceUPtr_t createPiece(const common::ChessPieceType& type,
								 const common::ChessPieceColor& color);
}