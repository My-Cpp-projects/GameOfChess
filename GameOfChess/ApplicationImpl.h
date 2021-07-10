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
	constexpr static std::uint32_t SCREEN_HEIGHT{ 1080 };
	constexpr static std::uint32_t SCREEN_WIDTH{ 1920 };
	bool m_isStartUpSuccessful{ false };
	bool m_shouldRun{ true };
	common::sdlWindowUPtr_t m_window{ nullptr, SDL_DestroyWindow };
	SDL_Surface* m_screenSurface{ nullptr }; // lifetime is managed by m_window
	SDL_Event m_event;
	SDL_Renderer* m_renderer{ nullptr };
	SDL_Texture* m_texture{ nullptr };
};