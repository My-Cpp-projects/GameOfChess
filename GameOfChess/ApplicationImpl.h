#pragma once

#include "IApplication.h"

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

private:
	constexpr static std::uint32_t SCREEN_HEIGHT{ 1920 };
	constexpr static std::uint32_t SCREEN_WIDTH{ 1080 };
	bool m_isStartUpSuccessful{ false };
	std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)> m_window{ nullptr, SDL_DestroyWindow };
	std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> m_screenSurface{ nullptr, SDL_FreeSurface };
};