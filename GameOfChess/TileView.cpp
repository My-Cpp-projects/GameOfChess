#include "TileView.h"
#include "Texture.h"

#include <iostream>

TileView::TileView(const TileData& tileData,
				   SDL_Renderer& renderer)
	: m_tileData(tileData)
	, m_renderer(renderer)
{}

void TileView::render() const
{
	//TODO all of the below needs to go into pieceView in the end
	if(m_tileData.m_containedPiece)
	{
		const auto piece = *(m_tileData.m_containedPiece.get());

		if(piece.m_color == common::ChessPieceColor::BLACK)
		{
			if(piece.m_type == common::ChessPieceType::PAWN)
			{
				constexpr int NO_OF_PIECES = 6;
				constexpr int NO_OF_COLORS = 2;
				Texture blackPawn(common::ImageType::PNG, "Assets/Chess_Pieces_Sprite.png", m_renderer);
				double singlePieceWidth = blackPawn.getWidth() / static_cast<double>(NO_OF_PIECES);
				double singlePieceHeight = blackPawn.getHeight() / static_cast<double>(NO_OF_COLORS);
				double blackPawnStartX = singlePieceWidth * 5;
				double blackPawnStartY = singlePieceHeight * 1;
				SDL_Rect rect{ blackPawnStartX, blackPawnStartY, singlePieceWidth, singlePieceHeight };

				double mid = (m_tileData.TILE_SIZE_IN_PIXELS - singlePieceWidth) / 2;
				double renderStartPosX = m_tileData.m_position.x * m_tileData.TILE_SIZE_IN_PIXELS + mid;
				double renderStartPosY = m_tileData.m_position.y * m_tileData.TILE_SIZE_IN_PIXELS + mid;
				SDL_Point renderPosition{ renderStartPosX, renderStartPosY };

				blackPawn.render(renderPosition, &rect);
			}
		}

		if(piece.m_color == common::ChessPieceColor::WHITE)
		{
			if(piece.m_type == common::ChessPieceType::PAWN)
			{
				constexpr int NO_OF_PIECES = 6;
				constexpr int NO_OF_COLORS = 2;
				Texture blackPawn(common::ImageType::PNG, "Assets/Chess_Pieces_Sprite.png", m_renderer);
				double singlePieceWidth = blackPawn.getWidth() / static_cast<double>(NO_OF_PIECES);
				double singlePieceHeight = blackPawn.getHeight() / static_cast<double>(NO_OF_COLORS);
				double whitePawnStartX = singlePieceWidth * 5;
				double whitePawnStartY = singlePieceHeight * 0;
				SDL_Rect rect{ whitePawnStartX, whitePawnStartY, singlePieceWidth, singlePieceHeight };

				double mid = (m_tileData.TILE_SIZE_IN_PIXELS - singlePieceWidth) / 2;
				double renderStartPosX = m_tileData.m_position.x * m_tileData.TILE_SIZE_IN_PIXELS + mid;
				double renderStartPosY = m_tileData.m_position.y * m_tileData.TILE_SIZE_IN_PIXELS + mid;
				SDL_Point renderPosition{ renderStartPosX, renderStartPosY };

				blackPawn.render(renderPosition, &rect);
			}
		}
	}
}