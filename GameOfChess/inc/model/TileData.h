#pragma once

#include "ChessPiece.h"

#include <SDL.h>

struct TileData
{
	TileData(const SDL_Point& position)
		: m_position(position)
	{}

	const SDL_Point m_position;
	chessPieceUPtr_t m_containedPiece{ nullptr };
	static constexpr int TILE_SIZE_IN_PIXELS = 60; // 60x60
};