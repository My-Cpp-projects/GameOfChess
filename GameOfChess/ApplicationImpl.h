#pragma once

#include "IApplication.h"
#include "CommonTypes.h"
#include "Board.h"
#include "BoardView.h"
#include "GameController.h"

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
	void handleEvents();

private:
	constexpr static std::uint32_t SCREEN_WIDTH{ 480 };
	constexpr static std::uint32_t SCREEN_HEIGHT{ 480 };
	bool m_isStartUpSuccessful{ false };
	common::sdlWindowUPtr_t m_window{ nullptr, SDL_DestroyWindow };
	common::sdlRendererUPtr_t m_renderer{ nullptr, SDL_DestroyRenderer };
	boardUPtr_t m_board{ nullptr };
	boardViewUPtr_t m_boardView{ nullptr };
	gameControllerUPtr_t m_gameController{ nullptr };
};