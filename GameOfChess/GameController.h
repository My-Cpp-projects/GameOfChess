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
	void mousePress(SDL_MouseButtonEvent& b);
	void handleEvents();

private:
	SDL_Point getTilePositionByMouseCoordinates(const int& mouseX,
												const int& mouseY);

private:
	bool m_isRunning{ false };
	BoardData& m_boardData;
};

using gameControllerUPtr_t = std::unique_ptr<GameController>;