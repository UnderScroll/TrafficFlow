#pragma once
#include <SFML/Graphics.hpp>

namespace tf
{

	class Node : public sf::Drawable, public sf::Transformable
	{
	public:
		//Constructors
		Node();
		Node(sf::Vector2f position);
		Node(sf::Vector2f position, float radius, sf::Color color);

		~Node();

		//Members
		bool selected = false;

		//Methods
		void draw(sf::RenderTarget& window, sf::RenderStates states) const;
		void select();
		void deselect();

	protected:
		sf::CircleShape shape = sf::CircleShape(10);
	};
}