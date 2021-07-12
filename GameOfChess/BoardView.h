#pragma once

#include "BoardData.h"
#include "CommonTypes.h"

#include <memory>

class BoardView
{
public:
	BoardView(BoardData& boardData,
			  SDL_Renderer& renderer);
	~BoardView();

	void render() const;

private:
	BoardData& m_boardData;

	common::sdlTextureUPtr_t m_boardTexture{nullptr, SDL_DestroyTexture};
	SDL_Renderer& m_renderer;
};

using boardViewUPtr_t = std::unique_ptr<BoardView>;