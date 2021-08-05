#include "GameController.h"
#include <iostream>

GameController::GameController(BoardData& boardData)
	: m_isRunning(true)
	, m_boardData(boardData)
{

}

GameController::~GameController()
{
}

bool GameController::isRunning() const
{
	return m_isRunning;
}

void GameController::mousePress(SDL_MouseButtonEvent& event)
{
	if(SDL_BUTTON_LEFT == event.button)
	{
		int mouseX;
		int mouseY;
		SDL_GetMouseState(&mouseX, &mouseY);
		const auto tilePosition = getTilePositionByMouseCoordinates(mouseX, mouseY);
		const auto& pieceInClickedTile = m_boardData.m_board[tilePosition.x][tilePosition.y]->getData().m_containedPiece;
		if(pieceInClickedTile)
		{
			m_boardData.selectedTileWithPiece = m_boardData.m_board[tilePosition.x][tilePosition.y].get();
		}
		if(m_boardData.selectedTileWithPiece)
		{
			std::cout << "Selected Tile X:" << m_boardData.selectedTileWithPiece->getData().m_position.x << std::endl;
			std::cout << "Selected Tile Y:" << m_boardData.selectedTileWithPiece->getData().m_position.y << std::endl;
		}
	}
}

void GameController::handleEvents()
{
	SDL_Event event;
	while(SDL_PollEvent(&event) != 0)
	{
		switch(event.type)
		{
			case SDL_QUIT:
			{
				m_isRunning = false;
				break;
			}
			case SDL_KEYDOWN:
			{
				switch(event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					{
						m_isRunning = false;
						break;
					}
				}
			}
			case SDL_MOUSEBUTTONUP:
			{
				mousePress(event.button);
				break;
			}
		}
	}
}

SDL_Point GameController::getTilePositionByMouseCoordinates(const int& mouseX,
															const int& mouseY)
{
	const auto& TILE_SIZE = m_boardData.m_board[0][0]->getData().TILE_SIZE_IN_PIXELS;
	int x = mouseX / TILE_SIZE;
	int y = mouseY / TILE_SIZE;
	return SDL_Point{ x, y };
}


