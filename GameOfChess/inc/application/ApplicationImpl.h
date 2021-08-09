#pragma once

#include "IApplication.h"
#include "util/CommonTypes.h"
#include "model/Board.h"
#include "view/BoardView.h"
#include "controller/GameController.h"

#include <SDL.h>
#include <memory>
#include <functional>

class ApplicationImpl : public IApplication
{
public:
	ApplicationImpl();
	~ApplicationImpl();
	void run() override;

private:
	void startUp();
	void shutDown();

	void mainLoop();

private:
	constexpr static unsigned int SCREEN_WIDTH{ 480 };
	constexpr static unsigned int SCREEN_HEIGHT{ 480 };
	bool m_isStartUpSuccessful{ false };
	common::sdlWindowUPtr_t m_window{ nullptr, SDL_DestroyWindow };
	common::sdlRendererUPtr_t m_renderer{ nullptr, SDL_DestroyRenderer };
	boardUPtr_t m_board{ nullptr };
	boardViewUPtr_t m_boardView{ nullptr };
	gameControllerUPtr_t m_gameController{ nullptr };
};