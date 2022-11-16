#pragma once
#include <SFML/Graphics.hpp>

namespace tf
{
	struct Mouse
	{
		bool isDragged = false;
		sf::Vector2i pos, previousPos;
	};
}
