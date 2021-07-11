#pragma once

#include "IApplication.h"
#include "CommonTypes.h"

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
	constexpr static std::uint32_t SCREEN_HEIGHT{ 500 };
	constexpr static std::uint32_t SCREEN_WIDTH{ 500 };
	bool m_isStartUpSuccessful{ false };
	bool m_shouldRun{ true };
	common::sdlWindowUPtr_t m_window{ nullptr, SDL_DestroyWindow };
	common::sdlRendererUPtr_t m_renderer{ nullptr, SDL_DestroyRenderer };
	SDL_Event m_event;
};