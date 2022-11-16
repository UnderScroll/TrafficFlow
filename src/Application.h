#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Intersection.h"
#include "Math.h"
#include "Mouse.h"
#include "Arrow.h"

namespace tf
{

	class Application
	{
	public:
		static Application& getInstance()
		{
			return s_Instance;
		}

		static void run()
		{
			getInstance().IRun();
		}
	private:
		Application() {};
		//Deletes unnecessary constructors
		Application(Application& other) = delete;
		void operator=(const Application&) = delete;

		//Static Instance
		static Application s_Instance;

		//Members
		sf::RenderWindow window;
		Mouse mouse;

		std::vector<std::shared_ptr<Intersection>> intersections;
		std::vector<std::shared_ptr<Intersection>> selectedIntersections;

		//Methods
		void IRun();
		void setup();
		void input();
		void update();
		void draw();

		void addIntersection();
		void addIntersection(sf::Vector2f position);
		void removeSelected(std::vector<std::shared_ptr<Intersection>>& selectedIntersection_ptrs);
		void select(std::vector<std::shared_ptr<Intersection>>& intersection_ptrs, std::vector<std::shared_ptr<Intersection>>& selectedIntersection_ptrs);
		void deselect(std::vector<std::shared_ptr<Intersection>>& selectedIntersection_ptrs);
		void moveSelected(std::vector<std::shared_ptr<Intersection>>& selectedIntersection_ptrs, sf::Vector2f pos);

		void onKeyboardPressed();
		void onMouseDragged();
		void onMousePressed();
		void onMouseMoved();
	};

}