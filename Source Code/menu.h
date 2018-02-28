#pragma once
#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML\Audio.hpp>
#include "exitwindow.h"


class menu
{

private:

	//Images
	sf::Sprite background;
	sf::Sprite help;
	sf::Sprite sound, selectMenu;

	//Texts
	sf::Text title;
	sf::Text menuItem[4];

	//Textures
	sf::Texture backgroundTexture, selectMenuTexture;
	sf::Texture helpTexture;
	sf::Texture soundTexture;

	//Fonts
	sf::Font titleFont;
	sf::Font menuItemsFont;

	//Points
	int  titleX = 550, titleY = 50, menuItemsX = 1000, menuItemsY = 300;

	//Music
	sf::Music menuMusic;

	//Misscelaneous
	int selectedMenuItem = 0;
	bool soundState = true;
	int i = 300;
	int &j = i;

public:
	~menu();
	menu(sf::RenderWindow &window);

	void moveUp();

	void moveDown();

	void drawMenu(sf::RenderWindow & window);

	void soundStateCheck();

	void menuWindowIsOpen(sf::RenderWindow & window);

};
void exitWinWindow();
void lastWindow(sf::RenderWindow &win);