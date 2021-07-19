#include "BoardView.h"
#include "Texture.h"

BoardView::BoardView(BoardData& boardData,
					 SDL_Renderer& renderer)
	: m_boardData(boardData)
	, m_renderer(renderer)
{
	m_boardTexture = std::make_unique<Texture>(common::ImageType::PNG, "Assets/Chessboard.png", renderer);

	for(const auto& row : boardData.m_board)
	{
		for(const auto& tile : row)
		{
			//TODO
			if(tile)
			{
				m_tileViews.emplace_back(std::make_unique<TileView>(tile->getData(), renderer));
			}
		}
	}
}

BoardView::~BoardView()
{
}

void BoardView::render() const
{
	SDL_RenderClear(&m_renderer);

	m_boardTexture->render({ 0, 0 });
	for(auto& tileView : m_tileViews)
	{
		tileView->render();
	}

	SDL_RenderPresent(&m_renderer);
}
