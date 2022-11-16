#include "Node.h"
#include <iostream>

namespace tf
{
	Node::Node()
	{
		std::cout << "Called Node() Constructor" << std::endl;
		shape.setFillColor(sf::Color::White);
		shape.setOrigin({ shape.getRadius(),shape.getRadius() });
		shape.setOutlineColor(sf::Color::Green);
	}

	Node::Node(sf::Vector2f position) 
	{
		std::cout << "Called Node(sf::Vector2f position) Constructor" << std::endl;
		setPosition(position);
		shape.setFillColor(sf::Color::White);
		shape.setOrigin({ shape.getRadius(),shape.getRadius() });
		shape.setOutlineColor(sf::Color::Green);
	}
	Node::Node(sf::Vector2f position, float radius, sf::Color color) 
	{
		std::cout << "Called Node(sf::Vector2f position, float radius, sf::Color color) Constructor" << std::endl;
		setPosition(position);
		shape.setFillColor(color);
		shape.setOrigin({ radius,radius });
		shape.setOutlineColor(sf::Color::Green);
	}

	Node::~Node()
	{
		std::cout << "Called ~Node() Destructor" << std::endl;
	}

	void Node::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(shape, getTransform());
	}

	void Node::select()
	{
		shape.setOutlineThickness(2);
		selected = true;
	}

	void Node::deselect()
	{
		shape.setOutlineThickness(0);
		selected = false;
	}
}