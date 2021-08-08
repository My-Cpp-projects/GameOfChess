#pragma once

#include "IView.h"
#include "TileData.h"
#include "ChessPieceView.h"

#include <memory>

class TileView : public IView
{
public:
	TileView(const TileData& tileData,
			 SDL_Renderer& renderer,
			 ChessPieceView& chessPieceView);
	~TileView();

	void render(const SDL_Point& renderStartLocation = {}) const override;

private:
	const TileData& m_tileData;
	SDL_Renderer& m_renderer;
	ChessPieceView& m_chessPieceView;
};

using tileViewUPtr_t = std::unique_ptr<TileView>;
