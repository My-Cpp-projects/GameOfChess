#pragma once

#include <SDL.h>
#include <map>
#include <memory>

#include "IView.h"
#include "ChessPiece.h"
#include "Texture.h"
#include "CommonTypes.h"

class ChessPieceView : public IView
{
public:
	ChessPieceView(SDL_Renderer& renderer);
	~ChessPieceView();

	void setRenderingPiece(const ChessPiece& pieceToRender);

	void render(const SDL_Point& renderStartLocation) const override;

	int getSinglePieceWidth() const;
	int getSinglePieceHeight() const;

private:
	void initClipRects();

private:
	static constexpr int NO_OF_PIECES = 6;
	static constexpr int NO_OF_COLORS = 2;

	const ChessPiece* m_piece{nullptr};
	SDL_Renderer& m_renderer;
	std::unique_ptr<Texture> m_sprite;
	using clipRectByColorAndType = std::map<std::pair<common::ChessPieceColor, common::ChessPieceType>, SDL_Rect>;
	clipRectByColorAndType m_clipRects;
	int m_singlePieceWidth;
	int m_singlePieceHeight;
};

using chessPieceViewUPtr_t = std::unique_ptr<ChessPieceView>;