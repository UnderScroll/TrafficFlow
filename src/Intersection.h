#pragma once
#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Math.h"
#include "Node.h"
#include "Arrow.h"

namespace tf
{
	class Intersection : public Node
	{
	public:
		Intersection();
		Intersection(sf::Vector2f position);
		~Intersection();

		void link(std::shared_ptr<Intersection> intersection);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const;
		void drawLinks(sf::RenderTarget& target, sf::RenderStates states) const;

		std::vector<std::shared_ptr<Intersection>> connectedIntersections;
	private:
		
	};
}