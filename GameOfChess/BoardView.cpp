#include "BoardView.h"
#include "TextureCreator.h"

BoardView::BoardView(BoardData& boardData,
					 SDL_Renderer& renderer)
	: m_boardData(boardData)
	, m_renderer(renderer)
{
	m_boardTexture = textureCreator::createTexture(common::ImageType::PNG,
												   "Assets/Chessboard.png",
												   renderer);

}

BoardView::~BoardView()
{
}

void BoardView::render() const
{
	SDL_RenderClear(&m_renderer);

	SDL_RenderCopy(&m_renderer, m_boardTexture.get(), nullptr, nullptr);

	SDL_RenderPresent(&m_renderer);
}
