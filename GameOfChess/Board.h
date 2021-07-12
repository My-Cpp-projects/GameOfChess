#pragma once

#include "BoardData.h"

#include <array>
#include <memory>

class Board
{
public:
	Board();
	~Board();

	void resetBoard();

	BoardData& getData();
private:
	std::unique_ptr<BoardData> m_data;

	static constexpr BoardData::board STARTING_BOARD =
	{
		{
			{-1,-2,-3,-4,-5,-3,-2,-1},
			{-6,-6,-6,-6,-6,-6,-6,-6},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0},
			{6, 6, 6, 6, 6, 6, 6, 6},
			{1, 2, 3, 4, 5, 3, 2, 1}
		}
	};
};

using boardUPtr_t = std::unique_ptr<Board>;