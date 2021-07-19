#pragma once

#include <SDL.h>

#include "IView.h"
#include "ChessPiece.h"

class ChessPieceView : public IView
{
public:
	ChessPieceView(const ChessPiece& piece,
				   SDL_Renderer& renderer);

	void render() const override;

private:
	const ChessPiece& m_piece;
	SDL_Renderer& m_renderer;
};