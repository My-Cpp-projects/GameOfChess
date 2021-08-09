#pragma once

#include <array>
#include "Tile.h"

struct BoardData
{
	using board = std::array<std::array<tileUPtr_t, 8>, 8>;

	board m_board{};
	Tile* selectedTileWithPiece = nullptr;
};