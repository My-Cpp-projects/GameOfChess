#pragma once

#include <SDL.h>
#include <memory>

namespace common
{
	using sdlSurfaceUPtr_t = std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)>;
	using sdlWindowUPtr_t = std::unique_ptr<SDL_Window, decltype(&SDL_DestroyWindow)>;
    using sdlTextureUPtr_t = std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)>;
    using sdlRendererUPtr_t = std::unique_ptr<SDL_Renderer, decltype(&SDL_DestroyRenderer)>;

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