#include "Intersection.h"
#include <iostream>

namespace tf
{
	Intersection::Intersection()
	{
		std::cout << "Called Intersection() Constructor : " << this << std::endl;
	}

	Intersection::Intersection(sf::Vector2f position)
		: Node(position)
	{
		std::cout << "Called Intersection(sf::Vector2f position) Constructor : " << this << std::endl;
	}

	Intersection::~Intersection()
	{
		std::cout << "Called ~Intersection() Destructor : " << this << std::endl;
	}

	void Intersection::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(shape, getTransform());
	}

	void Intersection::drawLinks(sf::RenderTarget& target, sf::RenderStates states) const
	{
		for (unsigned int i = 0; i < connectedIntersections.size(); i++)
		{
			sf::Vector2f dir = { connectedIntersections[i]->getPosition().x - getPosition().x, connectedIntersections[i]->getPosition().y - getPosition().y };
			normalize(dir);
			Arrow a = Arrow(getPosition() + (dir*14), connectedIntersections[i]->getPosition()-(dir*14));
			target.draw(a);
		}
	}

	void Intersection::link(std::shared_ptr<Intersection> intersection)
	{
		connectedIntersections.push_back(intersection);
	}
}