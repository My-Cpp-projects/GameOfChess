#include "GameController.h"

GameController::GameController(BoardData& boardData)
	: m_isRunning(true)
{

}

GameController::~GameController()
{
}

bool GameController::isRunning() const
{
	return m_isRunning;
}

void GameController::handleEvents()
{
	while(SDL_PollEvent(&m_event) != 0)
	{
		switch(m_event.type)
		{
			case SDL_QUIT:
			{
				m_isRunning = false;
				break;
			}
			case SDL_KEYDOWN:
			{
				switch(m_event.key.keysym.sym)
				{
					case SDLK_ESCAPE:
					{
						m_isRunning = false;
						break;
					}
				}
			}
		}
	}
}


