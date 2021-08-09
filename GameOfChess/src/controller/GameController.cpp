#include "controller/GameController.h"
#include <iostream>

GameController::GameController(BoardData& boardData)
	: m_isRunning(true)
	, m_boardData(boardData)
{
}

GameController::~GameController()
{
	printf("Destructor called for Game Controller\n");
}

bool GameController::isRunning() const
{
	return m_isRunning;
}

void GameController::mousePress(SDL_MouseButtonEvent& event)
{
	//TODO this looks ugly!
	if(SDL_BUTTON_LEFT == event.button)
	{
		int mouseX;
		int mouseY;
		SDL_GetMouseState(&mouseX, &mouseY);
		const auto tilePosition = getTilePositionByMouseCoordinates(mouseX, mouseY);
		// If nothing selected
		if(not m_boardData.selectedTileWithPiece)
		{
			const auto& pieceInClickedTile = m_boardData.m_board[tilePosition.x][tilePosition.y]->getData().m_containedPiece;
			if(pieceInClickedTile)
			{
				m_boardData.selectedTileWithPiece = m_boardData.m_board[tilePosition.x][tilePosition.y].get();
			}
		}
		else // if selected
		{
			m_boardData.m_board[tilePosition.x][tilePosition.y]->setPiece(std::move(m_boardData.selectedTileWithPiece->getData().m_containedPiece));
			m_boardData.selectedTileWithPiece = nullptr;
		}
	}
	if(SDL_BUTTON_RIGHT == event.button)
	{
		m_boardData.selectedTileWithPiece = nullptr;
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