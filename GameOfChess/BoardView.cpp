#include "BoardView.h"
#include "Texture.h"

BoardView::BoardView(BoardData& boardData,
					 SDL_Renderer& renderer)
	: m_boardData(boardData)
	, m_renderer(renderer)
{
	m_boardTexture = std::make_unique<Texture>(common::ImageType::PNG, "Assets/Chessboard.png", renderer);
	m_chessPieceView = std::make_unique<ChessPieceView>(renderer);

	for(int boardHeight = 0; boardHeight < m_boardData.m_board.size(); ++boardHeight)
	{
		for(int boardWidth = 0; boardWidth < m_boardData.m_board[boardHeight].size(); ++boardWidth)
		{
			m_tileViewMatrix[boardWidth][boardHeight] = std::make_unique<TileView>(m_boardData.m_board[boardWidth][boardHeight]->getData(),
																				   renderer,
																				   *m_chessPieceView);
		}
	}
}

BoardView::~BoardView()
{
}

void BoardView::render(const SDL_Point& renderStartLocation) const
{
	SDL_RenderClear(&m_renderer);

	m_boardTexture->render({ 0, 0 });
	for(auto& tileViewRow : m_tileViewMatrix)
	{
		for(auto& tileView : tileViewRow)
		{
			tileView->render();
		}
	}

	SDL_RenderPresent(&m_renderer);
}
