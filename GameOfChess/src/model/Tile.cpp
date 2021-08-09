#include "model/Tile.h"

Tile::Tile(const SDL_Point& position)
	: m_tileData(std::make_unique<TileData>(position))
{}

Tile::~Tile()
{
	printf("Destructor called for Tile\n");
}

void Tile::setPiece(chessPieceUPtr_t piece)
{
	m_tileData->m_containedPiece = std::move(piece);
}

TileData& Tile::getData()
{
	return *m_tileData;
}