#include "ApplicationImpl.h"

#include <SDL_image.h>
#include <iostream>
#include <cassert>

ApplicationImpl::ApplicationImpl()
	: m_surfaceFactory {std::make_unique<SDLSurfaceFactory>()}
{
	startUp();
}

ApplicationImpl::~ApplicationImpl()
{
	shutDown();
}

void ApplicationImpl::run()
{
	if(not m_isStartUpSuccessful)
	{
		std::cerr << "Failed to start up application!" << std::endl;
		return;
	}

	const auto bKing = m_surfaceFactory->createSurfaceFromImage(common::ImageType::PNG,
																"Assets/b_king.png",
																m_screenSurface->format);

	assert(bKing.result == common::Result::SUCCESS);

	SDL_FillRect(m_screenSurface, NULL, SDL_MapRGB(m_screenSurface->format, 0xFF, 0xFF, 0xFF));
	SDL_BlitSurface(bKing.value.get(), nullptr, m_screenSurface, nullptr);

	SDL_UpdateWindowSurface(m_window.get());
	SDL_Delay(1000);
}

void ApplicationImpl::startUp()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cerr << "Failed to initialize SDL! Reason: " << SDL_GetError() << std::endl;
		return;
	}

	m_window.reset(SDL_CreateWindow("SDL Window",
									SDL_WINDOWPOS_UNDEFINED,
									SDL_WINDOWPOS_UNDEFINED,
									SCREEN_WIDTH,
									SCREEN_HEIGHT,
									SDL_WINDOW_SHOWN));
														
	if(not m_window.get())
	{
		std::cerr << "Failed to create window! Reason: " << SDL_GetError() << std::endl;
		return;
	}

	int imgFlags = IMG_INIT_PNG;
	if(not (IMG_Init(imgFlags) & imgFlags))
	{
		std::cerr << "Failed to initialize SDL_image! Reason: " << IMG_GetError() << std::endl;
		return;
	}

	m_screenSurface = SDL_GetWindowSurface(m_window.get());
	if(not m_screenSurface)
	{
		std::cerr << "Failed to get surface from window! Reason: " << SDL_GetError() << std::endl;
		return;
	}

	m_isStartUpSuccessful = true;
}

void ApplicationImpl::shutDown()
{
	SDL_Quit();
}
