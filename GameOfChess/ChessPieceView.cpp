#include "ChessPieceView.h"

ChessPieceView::ChessPieceView(const ChessPiece& piece,
							   SDL_Renderer& renderer)
	: m_piece(piece)
	, m_renderer(renderer)
{
}

void ChessPieceView::render() const
{
	//TODO
}
