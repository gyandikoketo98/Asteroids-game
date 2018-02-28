#pragma once

#include<SFML/Graphics.hpp>
#include "menu.h"
class exitWin
{
protected:

	sf::Text sure;
	sf::Text option[2];

	sf::Font sureFont;
	sf::Font yesnoFont;
	sf::RenderWindow Window;
public:

	int selectedOption = 0;

	exitWin()
	{

		Window.create(sf::VideoMode(450, 150), "Exit", sf::Style::None);

		if (!sureFont.loadFromFile("res/fonts/PRICEDOW.ttf"))	std::cout << "Error loadng Title font";
		if (!yesnoFont.loadFromFile("res/fonts/SOLO5.ttf")) std::cout << "Error loading Menu Item Font";

		sure.setString("Are you Handsome?");
		sure.setFont(sureFont);
		sure.setPosition(50, 10);
		sure.setCharacterSize(50);

		option[0].setString("yes");
		option[0].setFont(yesnoFont);
		option[0].setPosition(50, 100);
		option[0].setCharacterSize(30);
		option[0].setFillColor(sf::Color::Red);

		option[1].setString("NO");
		option[1].setFont(yesnoFont);
		option[1].setPosition(230, 100);
		option[1].setCharacterSize(30);

	}

	void moveRight()
	{
		if (selectedOption == 0)
		{
			option[selectedOption].setFillColor(sf::Color::White);
			selectedOption = 1;
			option[selectedOption].setFillColor(sf::Color::Red);

		}
	}
	void moveLeft()
	{
		if (selectedOption == 1)
		{
			option[selectedOption].setFillColor(sf::Color::White);
			selectedOption = 0;
			option[selectedOption].setFillColor(sf::Color::Red);

		}
	}
	void drawExitItems()
	{
		Window.draw(sure);
		Window.draw(option[0]);
		Window.draw(option[1]);
	}
	friend void exitWinWindow();
};
