#pragma once

#include "about.h"
#include "player.h"
#include "menu.h"
#include "exitwindow.h"
#include "mainGame.h"
#include "lastexitmenu.h"
#include "highScore.h"


menu::~menu()
{
}

menu::menu(sf::RenderWindow &window)
{


	if (!menuMusic.openFromFile("res/audio/menuMusic.ogg")) std::cout << "Menu music not loaded";
	menuMusic.setLoop(true);
	menuMusic.setVolume(50.0f);

	//TexturesLoad
	if (!backgroundTexture.loadFromFile("res/images/bg.jpg")) std::cout << "Unable to load background";
	background.setTexture(backgroundTexture);
	background.setScale((float)window.getSize().x / background.getTextureRect().width, (float)window.getSize().y / background.getTextureRect().height);

	//selectmenutexture load

	if (!selectMenuTexture.loadFromFile("spaceship1.png")) std::cout << "Unable to load select menu";
	selectMenu.setTexture(selectMenuTexture);
	selectMenu.setScale(0.1f, 0.1f);
	selectMenu.setPosition(menuItemsX - 30, menuItemsY);
	selectMenu.setRotation(90.0f);

	//if (!soundTexture.loadFromFile("res/images/soundOn.png")) std::cout << "Unable to load sound Texture";
	//sound.setTexture(soundTexture);
	//sound.setPosition(1260, 40);




	//FontsLoad
	if (!titleFont.loadFromFile("res/fonts/3Dumb.ttf"))	std::cout << "Error loadng Title font";
	if (!menuItemsFont.loadFromFile("res/fonts/SOLO5.ttf")) std::cout << "Error loading Menu Item Font";

	//Title
	title.setString("ASTEROIDS");
	title.setPosition(titleX, titleY);
	title.setCharacterSize(55);
	title.setFillColor(sf::Color::Yellow);
	title.setFont(titleFont);


	//Play
	menuItem[0].setString("PLAY");
	menuItem[0].setPosition(menuItemsX, menuItemsY);
	menuItem[0].setCharacterSize(38);
	menuItem[0].setFont(menuItemsFont);
	menuItem[0].setFillColor(sf::Color::Red);

	//Options
	menuItem[1].setString("HIGH SCORE");
	menuItem[1].setPosition(menuItemsX, menuItemsY + 40);
	menuItem[1].setCharacterSize(30);
	menuItem[1].setFont(menuItemsFont);

	//About
	menuItem[2].setString("ABOUT");
	menuItem[2].setPosition(menuItemsX, menuItemsY + 80);
	menuItem[2].setCharacterSize(30);
	menuItem[2].setFont(menuItemsFont);

	//Exit
	menuItem[3].setString("EXIT");
	menuItem[3].setString("EXIT");
	menuItem[3].setPosition(menuItemsX, menuItemsY + 120);
	menuItem[3].setCharacterSize(30);
	menuItem[3].setFont(menuItemsFont);
}

void menu::moveUp()
{
	if (selectedMenuItem > 0 && selectedMenuItem <= 3)
	{

		menuItem[selectedMenuItem].setFillColor(sf::Color::White);
		menuItem[selectedMenuItem].setCharacterSize(30);
		selectedMenuItem--;
		menuItem[selectedMenuItem].setFillColor(sf::Color::Red);
		menuItem[selectedMenuItem].setCharacterSize(38);
		selectMenu.setPosition(menuItemsX - 30, j -= 40);

	}
}

void menu::moveDown()
{

	if (selectedMenuItem >= 0 && selectedMenuItem < 3)
	{

		menuItem[selectedMenuItem].setFillColor(sf::Color::White);
		menuItem[selectedMenuItem].setCharacterSize(30);
		selectedMenuItem++;
		menuItem[selectedMenuItem].setFillColor(sf::Color::Red);
		menuItem[selectedMenuItem].setCharacterSize(38);
		selectMenu.setPosition(menuItemsX - 30, j += 40);
	}
}

void menu::drawMenu(sf::RenderWindow &window)
{
	window.draw(background);
	//window.draw(help);
	window.draw(title);
	//window.draw(sound);
	window.draw(menuItem[0]);
	window.draw(menuItem[1]);
	window.draw(menuItem[2]);
	window.draw(menuItem[3]);
	window.draw(selectMenu);

}

void menu::soundStateCheck()
{
	if (soundState == true)
	{
		menuMusic.play();
		//if (!soundTexture.loadFromFile("res/images/soundOn.png")) std::cout << "Unable to load sound Texture";
	}
	if (soundState == false)
	{
		menuMusic.stop();
		//if (!soundTexture.loadFromFile("res/images/soundOff.png")) std::cout << "Unable to load sound Texture";

	}
}

void menu::menuWindowIsOpen(sf::RenderWindow &window)
{



	menuMusic.play();
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::EventType::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Escape:
					window.close();
					break;

				case sf::Keyboard::Down:
					moveDown();
					break;

				case sf::Keyboard::Up:
					moveUp();
					break;

				case sf::Keyboard::Return:
					if (selectedMenuItem == 3) exitWinWindow();
					if (selectedMenuItem == 1) show();
					if (selectedMenuItem == 2) aboutUsWindow();
					if (selectedMenuItem == 0)
					{
						window.close();
						mainGame();
				

					}


				}
				
			}
			window.clear();
			drawMenu(window);
			window.display();

		}

	}

}
void exitWinWindow()

{
	exitWin a;

	while (a.Window.isOpen())
	{
		sf::Event eventX;
		while (a.Window.pollEvent(eventX))
		{
			switch (eventX.type)
			{
			case sf::Event::EventType::Closed:
				a.Window.close();
				break;

			case sf::Event::KeyPressed:
				switch (eventX.key.code)
				{
				case sf::Keyboard::Escape:
					a.Window.close();
					break;
				case sf::Keyboard::Right:
					a.moveRight();
					break;
				case sf::Keyboard::Left:
					a.moveLeft();
					break;
				case sf::Keyboard::Return:
					if (a.selectedOption == 0)  a.Window.close();
					if (a.selectedOption == 1) { exit(0); }
					break;
				}
				break;
			}

			a.Window.clear(sf::Color(sf::Color::Black));
			a.drawExitItems();
			a.Window.display();

		}


	}
}

void lastWindow(sf::RenderWindow &win)
{
	lastExitWindow a;
	while (a.Window.isOpen())
	{
		sf::Event eventX;
		while (a.Window.pollEvent(eventX))
		{
			switch (eventX.type)
			{
			case sf::Event::EventType::Closed:
				a.Window.close();
				break;

			case sf::Event::KeyPressed:
				switch (eventX.key.code)
				{
				case sf::Keyboard::Escape:
					a.Window.close();
					break;
				case sf::Keyboard::Right:
					a.moveRight();
					break;
				case sf::Keyboard::Left:
					a.moveLeft();
					break;
				case sf::Keyboard::Return:
					if (a.selectedOption == 0)
					{
						win.close(); 
						a.Window.close(); mainGame();
					}
					if (a.selectedOption == 1) 
					{
						a.Window.close();
						menu m1(win);
						m1.menuWindowIsOpen(win);
					}
					break;
				}
				break;
			}

			a.Window.clear(sf::Color(sf::Color::Black));
			a.drawExitItems();
			a.Window.display();

		}


	}
}




	




