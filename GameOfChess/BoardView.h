#pragma once

#include "BoardData.h"
#include "IView.h"
#include "Texture.h"
#include "TileView.h"

#include <memory>
#include <vector>

class BoardView : public IView
{
public:
	BoardView(BoardData& boardData,
			  SDL_Renderer& renderer);
	~BoardView();

	void render() const override;

private:
	BoardData& m_boardData;

	textureUPtr_t m_boardTexture;
	SDL_Renderer& m_renderer;

	std::vector<tileViewUPtr_t> m_tileViews;
};

using boardViewUPtr_t = std::unique_ptr<BoardView>;