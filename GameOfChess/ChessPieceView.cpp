#include "ChessPieceView.h"
#include <array>

ChessPieceView::ChessPieceView(SDL_Renderer& renderer)
	: m_renderer(renderer)
{
	m_sprite = std::make_unique<Texture>(common::ImageType::PNG, "Assets/Chess_Pieces_Sprite.png", m_renderer);

	m_singlePieceWidth = m_sprite->getWidth() / NO_OF_PIECES;
	m_singlePieceHeight = m_sprite->getHeight() / NO_OF_COLORS;

	initClipRects();
}

ChessPieceView::~ChessPieceView()
{
	printf("Destructor called for Chess Piece View\n");
}

void ChessPieceView::setRenderingPiece(const ChessPiece& pieceToRender)
{
	m_piece = &pieceToRender;
}

void ChessPieceView::render(const SDL_Point& renderStartLocation) const
{
	if(m_piece)
	{
		//TODO: same thing in initClipRects(). FIX!
		const double singlePieceWidth = m_sprite->getWidth() / static_cast<double>(6);

		m_sprite->render(renderStartLocation, &m_clipRects.at(std::make_pair(m_piece->m_color, m_piece->m_type)));
	}
}

int ChessPieceView::getSinglePieceWidth() const
{
	return m_singlePieceWidth;
}

int ChessPieceView::getSinglePieceHeight() const
{
	return m_singlePieceHeight;
}

void ChessPieceView::initClipRects()
{
	//Todo below rect creations can be potentially moved to some factory instead
	constexpr std::array<std::pair<common::ChessPieceType, int>, NO_OF_PIECES> PIECE_LOCATIONS_ON_SPRITE =
	{
		{
			{common::ChessPieceType::KING, 0},
			{common::ChessPieceType::QUEEN, 1},
			{common::ChessPieceType::BISHOP, 2},
			{common::ChessPieceType::KNIGHT, 3},
			{common::ChessPieceType::ROOK, 4},
			{common::ChessPieceType::PAWN, 5},
		}
	};

	constexpr std::array<std::pair<common::ChessPieceColor, int>, NO_OF_PIECES> COLOR_LOCATIONS_ON_SPRITE =
	{
		{
			{common::ChessPieceColor::WHITE, 0},
			{common::ChessPieceColor::BLACK, 1},
		}
	};

	for(const auto& colorAndLocation : COLOR_LOCATIONS_ON_SPRITE)
	{
		for(const auto& pieceAndLocation : PIECE_LOCATIONS_ON_SPRITE)
		{
			const auto& color = colorAndLocation.first;
			const auto& colorLocation = colorAndLocation.second;
			const auto& pieceType = pieceAndLocation.first;
			const auto& pieceLocation = pieceAndLocation.second;
			auto pieceStartX = m_singlePieceWidth * pieceLocation;
			auto pieceStartY = m_singlePieceHeight * colorLocation;
			SDL_Rect clipRect{ pieceStartX, pieceStartY, m_singlePieceWidth, m_singlePieceHeight };
			m_clipRects.emplace(std::make_pair(std::make_pair(color, pieceType), clipRect));
		}
	}
}