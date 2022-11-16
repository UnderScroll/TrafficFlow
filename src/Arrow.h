#pragma once
#include <SFML/Graphics.hpp>
#include "Math.h"

namespace tf
{
	class Arrow : public sf::Shape
	{
	public:
		float thickness;

		Arrow(sf::Vector2f pointA, sf::Vector2f pointB);

		void draw(sf::RenderTarget& window, sf::RenderStates states) const;
		void setPoints(sf::Vector2f pointA, sf::Vector2f pointB);

		virtual std::size_t getPointCount() const override;
		virtual sf::Vector2f getPoint(std::size_t index) const override;
	private:
		sf::ConvexShape line;
		sf::ConvexShape triangle;
	};
}