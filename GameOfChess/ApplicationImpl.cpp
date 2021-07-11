#include "ApplicationImpl.h"
#include "TextureCreator.h"
#include "ImageLoader.h"

#include <SDL_image.h>
#include <iostream>
#include <cassert>

ApplicationImpl::ApplicationImpl()
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

	mainLoop();
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

	m_renderer.reset(SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED));
	if(m_renderer == nullptr)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return;
	}
	SDL_SetRenderDrawColor(m_renderer.get(), 0x0, 0x00ff, 0x0, 0xff);

	int imgFlags = IMG_INIT_PNG;
	if(not (IMG_Init(imgFlags) & imgFlags))
	{
		std::cerr << "Failed to initialize SDL_image! Reason: " << IMG_GetError() << std::endl;
		return;
	}

	m_isStartUpSuccessful = true;
}

void ApplicationImpl::shutDown()
{
	IMG_Quit();
	SDL_Quit();
}

void ApplicationImpl::mainLoop()
{
	auto texture = textureCreator::createTexture(common::ImageType::PNG,
												 "Assets/b_king.png",
												 m_renderer.get());

	while(m_shouldRun)
	{
		handleEvents();
		
		SDL_RenderClear(m_renderer.get());

		// magic numbers from actual image dimesions
		SDL_Rect dstrect = { 5, 5, 440, 443 };
		SDL_RenderCopy(m_renderer.get(), texture.value.get(), nullptr, &dstrect);

		SDL_RenderPresent(m_renderer.get());
	}
}

void ApplicationImpl::handleEvents()
{
	while(SDL_PollEvent(&m_event) != 0)
	{
		if(m_event.type == SDL_QUIT)
		{
			m_shouldRun = false;
		}
	}
}
