#include "Arrow.h"

namespace tf
{
	Arrow::Arrow(sf::Vector2f pointA, sf::Vector2f pointB)
	{
		thickness = 3;

		line = sf::ConvexShape(4);	
		triangle = sf::ConvexShape(3);

		line.setFillColor(sf::Color(120, 120, 120, 255));
		triangle.setFillColor(sf::Color(120, 120, 120, 255));

		setPoints(pointA, pointB);
	}

	void Arrow::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(line, sf::RenderStates::Default);
		target.draw(triangle, sf::RenderStates::Default);
	}

	void Arrow::setPoints(sf::Vector2f pointA, sf::Vector2f pointB)
	{
		float dist = distance(pointA, pointB);
		float angle = radToDeg(atan2(pointB.y - pointA.y, pointB.x - pointA.x));

		line.setPoint(0, { 0, 0 });
		line.setPoint(1, { dist - thickness * 2, 0 });
		line.setPoint(2, { dist - thickness * 2, -thickness });
		line.setPoint(3, { 0, -thickness });
		

		line.setOrigin({ 0, -thickness / 2 });
		line.setRotation(angle);
		line.setPosition(pointA);

		triangle.setPoint(0, { 0.0, 0.0 });
		triangle.setPoint(1, { -0.8660254037844, 0.5 });
		triangle.setPoint(2, { -0.8660254037844,-0.5 });
		

		triangle.setScale({ thickness * 4, thickness * 4 });
		triangle.setPosition(pointB.x, pointB.y);
		triangle.setRotation(angle);
	}

	std::size_t Arrow::getPointCount() const
	{
		return std::size_t();
	}

	sf::Vector2f Arrow::getPoint(std::size_t index) const
	{
		return sf::Vector2f();
	}
}
