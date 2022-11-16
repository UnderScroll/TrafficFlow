#include "Application.h"

namespace tf
{

	//Initialize Instance
	Application Application::s_Instance;

	Arrow a = Arrow({ 0,0 }, {0, 0});

	void Application::IRun()
	{
		setup();
		while (window.isOpen())
		{
			input();
			update();
			draw();
		}
	}

	void Application::setup()
	{
		sf::ContextSettings settings = sf::ContextSettings(0,0,0,1,1,0,false);
		window.create(sf::VideoMode(800, 450), "TrafficFlow v0.2", sf::Style::Default, settings);
		window.setVerticalSyncEnabled(true);
		window.setPosition({ 500, 300 });

		addIntersection({100, 100});
		addIntersection({200, 200});

		intersections[0]->link(intersections[1]);

		a = Arrow(sf::Vector2f(10, 10), sf::Vector2f(100, 100));
	}

	void Application::input()
	{
		sf::Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				onKeyboardPressed();
				break;
			case sf::Event::MouseButtonPressed:
				onMousePressed();
				break;
			case sf::Event::MouseButtonReleased:
				break;
			case sf::Event::MouseMoved:
				onMouseMoved();
				break;
			}
		}
	}

	void Application::update()
	{

	}

	void Application::draw()
	{
		window.clear();
		for (std::shared_ptr<Intersection>& i : intersections)
		{
			i->draw(window, sf::RenderStates::Default);
		}

		for (std::shared_ptr<Intersection>& i : intersections)
		{
			i->drawLinks(window, sf::RenderStates::Default);
		}

		//a.setPoints({ 100, 100 }, (sf::Vector2f)sf::Mouse::getPosition(window));
		//a.draw(window, sf::RenderStates::Default);
		window.display();
	}

	void Application::addIntersection()
	{
		intersections.push_back(std::shared_ptr<Intersection>(new Intersection((sf::Vector2f)sf::Mouse::getPosition(window))));
	}

	void Application::addIntersection(sf::Vector2f position)
	{
		intersections.push_back(std::shared_ptr<Intersection>(new Intersection(position)));
	}

	void Application::select(std::vector<std::shared_ptr<Intersection>>& intersection_ptrs, std::vector<std::shared_ptr<Intersection>>& selectedIntersection_ptrs)
	{
		sf::Vector2f mousePos = (sf::Vector2f)sf::Mouse::getPosition(window);

		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			deselect(selectedIntersection_ptrs);

		for (std::shared_ptr<Intersection> i : intersection_ptrs)
		{
			if (distance(i->getPosition(), mousePos) < 10)
			{
				i->select();
				selectedIntersection_ptrs.push_back(i);
				break;
			}
		}
	}

	void Application::deselect(std::vector<std::shared_ptr<Intersection>>& selectedIntersection_ptrs)
	{
		for (std::shared_ptr<Intersection> i : selectedIntersection_ptrs)
		{
			i->deselect();
		}
		selectedIntersection_ptrs.clear();
	}

	void Application::removeSelected(std::vector<std::shared_ptr<Intersection>>& selectedIntersection_ptrs)
	{
		size_t size = intersections.size();
		for (unsigned int i = 0 ; i < size; i++)
		{
			for (std::shared_ptr<Intersection>& j : selectedIntersection_ptrs)
			{
				if (intersections[i] == j)
				{
					intersections.erase(intersections.begin() + i);
					size--;
					i--;
					break;
				}
			}
		}

		selectedIntersection_ptrs.clear();
	}

	void Application::moveSelected(std::vector<std::shared_ptr<Intersection>>& selectedIntersection_ptrs, sf::Vector2f move)
	{
		for (std::shared_ptr<Intersection>& i : selectedIntersection_ptrs)
		{
			i->move(move);
		}
	}

	void Application::onKeyboardPressed()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add))
			addIntersection();
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract))
			removeSelected(selectedIntersections);
	}

	void Application::onMousePressed()
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			select(intersections, selectedIntersections);
		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Middle))
		{

		}
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			deselect(selectedIntersections);
		}
	}

	void Application::onMouseMoved()
	{
		mouse.previousPos = mouse.pos;
		mouse.pos = sf::Mouse::getPosition(window);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle))
		{
			onMouseDragged();
		}
	}

	void Application::onMouseDragged()
	{
		moveSelected(selectedIntersections, (sf::Vector2f)(mouse.pos - mouse.previousPos));
	}
}