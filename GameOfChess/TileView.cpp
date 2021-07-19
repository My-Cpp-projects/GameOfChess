#include "TileView.h"
#include "Texture.h"

TileView::TileView(const TileData& tileData,
				   SDL_Renderer& renderer)
	: m_tileData(tileData)
	, m_renderer(renderer)
{}

void TileView::render() const
{
	//TODO
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
				double singlePieceWidth = blackPawn.getWidth() / NO_OF_PIECES;
				double singlePieceHeight = blackPawn.getHeight() / NO_OF_COLORS;
				double blackPawnStartX = singlePieceWidth * 5;
				double blackPawnStartY = singlePieceHeight * 1;
				SDL_Rect rect{ blackPawnStartX, blackPawnStartY, singlePieceWidth, singlePieceHeight };
				blackPawn.render(m_tileData.m_position, &rect);
			}
		}
	}
}
