#pragma once
#include <SFML\Graphics.hpp>

namespace tf
{
	float distance(sf::Vector2f a, sf::Vector2f b);
	sf::Vector2f lerp(sf::Vector2f a, sf::Vector2f b, float t);
	void normalize(sf::Vector2f &v);
	float mag(sf::Vector2f v);
	double radToDeg(double angleInRad);
	sf::Vector2f operator*(sf::Vector2f v, float factor);
}