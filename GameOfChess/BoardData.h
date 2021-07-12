#pragma once

#include <array>

struct BoardData
{
	using board = std::array<std::array<std::int16_t, 8>, 8>;

	board m_board{};
};