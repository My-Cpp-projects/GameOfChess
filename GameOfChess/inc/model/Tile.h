#pragma once

#include "TileData.h"

#include <SDL.h>
#include <memory>

class Tile
{
public:
	Tile(const SDL_Point& position);
	~Tile();

	void setPiece(chessPieceUPtr_t piece);

	TileData& getData();

private:
	std::unique_ptr<TileData> m_tileData;
};

using tileUPtr_t = std::unique_ptr<Tile>;