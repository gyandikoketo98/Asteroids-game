#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
class aboutUs
{
private:
	sf::RenderWindow aboutWindow;
	sf::Text text;
	sf::Font font;
public:
	aboutUs()
	{
		aboutWindow.create(sf::VideoMode(400, 400), "About Us", sf::Style::Default);
		
		if (!font.loadFromFile("arial.ttf"))	std::cout << "Error loadng Title font";
		text.setString("About US:\n Pravin Thapa Magar(073BCT526) \n Rebati Raman Gaire(073bct533) \n Shishir Subedi(073BCT541)");
		text.setPosition(10.0, 10.0);
		text.setCharacterSize(20);
		text.setFillColor(sf::Color::Red);
		text.setFont(font);
	}
	friend void aboutUsWindow();
};
void aboutUsWindow()
{
	aboutUs a;
	while (a.aboutWindow.isOpen())
	{
		sf::Event event;
		while (a.aboutWindow.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::EventType::Closed:
				a.aboutWindow.close();
				break;

			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					a.aboutWindow.close();
					break;
				}
			}
		}
		a.aboutWindow.clear(sf::Color::Black);
		a.aboutWindow.draw(a.text);
		a.aboutWindow.display();
	}

}