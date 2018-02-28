#include<SFML\Graphics.hpp>
#include<iostream>
#include "menu.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1366, 768), "Asteroids");
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(30);
	menu Menu(window);
	Menu.menuWindowIsOpen(window);
	return 0;

}


