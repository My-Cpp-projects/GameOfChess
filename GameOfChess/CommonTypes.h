#pragma once

#include <SDL.h>
#include <memory>

namespace common
{
	using SDLSurfaceUPtr_t = std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)>;
	using SDLWindowUPtr_t = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;

	enum class ImageType
	{
		BMP = 0,
		PNG = 1,
	};

	enum class Result
	{
		FAILURE = 0,
		SUCCESS = 1,
	};

    template <typename T>
    struct ResultValue
    {
        ResultValue(Result r, T& v)
            : result(r)
            , value(v)
        {}

        ResultValue(Result r, T&& v)
            : result(r)
            , value(std::move(v))
        {}

        Result result;
        T value;
    };
}