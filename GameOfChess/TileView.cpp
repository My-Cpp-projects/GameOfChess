#include "TileView.h"
#include "Texture.h"

#include <iostream>

TileView::TileView(const TileData& tileData,
				   SDL_Renderer& renderer,
				   ChessPieceView& chessPieceView)
	: m_tileData(tileData)
	, m_renderer(renderer)
	, m_chessPieceView(chessPieceView)
{

}

void TileView::render(const SDL_Point& renderStartLocation) const
{
	//TODO all of the below needs to go into pieceView in the end
	if(m_tileData.m_containedPiece)
	{
		const auto piece = *(m_tileData.m_containedPiece.get());
		m_chessPieceView.setRenderingPiece(piece);

		double mid = (TileData::TILE_SIZE_IN_PIXELS - m_chessPieceView.getSinglePieceWidth()) / 2;
		double renderStartPosX = m_tileData.m_position.x * TileData::TILE_SIZE_IN_PIXELS + mid;
		double renderStartPosY = m_tileData.m_position.y * TileData::TILE_SIZE_IN_PIXELS + mid;
		SDL_Point renderPosition{ renderStartPosX, renderStartPosY };

		m_chessPieceView.render(renderPosition);
	}
}