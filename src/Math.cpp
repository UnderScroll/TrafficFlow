#include "Math.h"

namespace tf
{
	float distance(sf::Vector2f a, sf::Vector2f b)
	{
		return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
	}

	sf::Vector2f lerp(sf::Vector2f a, sf::Vector2f b, float t)
	{
		return sf::Vector2f(a.x + t * (b.x - a.x), a.y + t * (b.y - a.y));
	}

	void normalize(sf::Vector2f &v)
	{
		float magv = mag(v);
		v /= magv;
	}

	float mag(sf::Vector2f v)
	{
		return sqrt(v.x * v.x + v.y * v.y);
	}

	double radToDeg(double angleInRad)
	{
		return angleInRad / 3.141592653 * 180;
	}

	sf::Vector2f operator*(sf::Vector2f v, float factor)
	{
		v.x *= factor;
		v.y *= factor;
		return v;
	}
}