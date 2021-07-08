#pragma once

#include "IApplication.h"
#include "CommonTypes.h"
#include "SDLSurfaceFactory.h"

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
	constexpr static std::uint32_t SCREEN_HEIGHT{ 1080 };
	constexpr static std::uint32_t SCREEN_WIDTH{ 1920 };
	bool m_isStartUpSuccessful{ false };
	common::SDLWindowUPtr_t m_window{ nullptr, SDL_DestroyWindow };
	SDL_Surface* m_screenSurface{ nullptr }; // lifetime is managed by m_window
	const std::unique_ptr<SDLSurfaceFactory> m_surfaceFactory{ nullptr };
};