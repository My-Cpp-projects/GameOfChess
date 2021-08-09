#pragma once

#include "model/ChessPiece.h"
#include "util/CommonTypes.h"

namespace chessPieceFactory
{
	chessPieceUPtr_t createPiece(const common::ChessPieceType& type,
								 const common::ChessPieceColor& color);
}