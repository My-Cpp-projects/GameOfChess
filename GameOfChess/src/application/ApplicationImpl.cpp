#include "application/ApplicationImpl.h"

#include <SDL_image.h>
#include <iostream>
#include <cassert>

ApplicationImpl::ApplicationImpl()
{
	startUp();
}

ApplicationImpl::~ApplicationImpl()
{
	printf("Destructor called for Application\n");
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

	m_window.reset(SDL_CreateWindow("The Game Of Chess",
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

	m_renderer.reset(SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC));
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

	m_board = std::make_unique<Board>();
	m_boardView = std::make_unique<BoardView>(m_board->getData(), *m_renderer);
	m_gameController = std::make_unique<GameController>(m_board->getData());

	m_isStartUpSuccessful = true;
}

void ApplicationImpl::shutDown()
{
	IMG_Quit();
	SDL_Quit();
}

void ApplicationImpl::mainLoop()
{
	while(m_gameController->isRunning())
	{
		m_gameController->handleEvents();

		m_boardView->render();
	}
}