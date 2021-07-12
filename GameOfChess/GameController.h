#pragma once

#include <memory>
#include <SDL.h>

#include "BoardData.h"

class GameController
{
public:
	GameController(BoardData& boardData);
	~GameController();

	bool isRunning() const;
	void handleEvents();

private:
	bool m_isRunning{ false };
	SDL_Event m_event;
};

using gameControllerUPtr_t = std::unique_ptr<GameController>;