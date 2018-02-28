#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>
#include <list>
#include<cmath>
#include "player.h"
#include "Bullet.h"
#include "asteriod.h"
#include "collision.h"
#include "exitwindow.h"
#include "menu.h"
#include<fstream>
#include<sstream> // for changing char to int eg "55" to 55


bool HighScoreCheck(int score)
{
	char HighScore;
	std::ifstream fin("HighScore.txt");
	fin >> HighScore;
	fin.close();
	std::stringstream abc(HighScore);
	int x = 0;
	abc >> x;
	//std::cout << x << std::endl;
	if (score > x)
		return true;
	else
		return false;
}
void writeTofile(int score)
{
	
	std::ofstream fout("HighScore.txt");
		fout << score;
		fout.close();
	
}

void deadmessage(sf::RenderWindow &wn,int score)
{
	plife = 3;
	sf::Text text;
	sf::Font font;
	if (!font.loadFromFile("res/fonts/3Dumb.ttf"))	std::cout << "Error loadng Title font";
	text.setString("YOU Are DEAD");
	text.setPosition(300.0, 150.0);
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::Red);
	text.setFont(font);
	wn.clear();
	wn.draw(text);
	wn.display();

	if (HighScoreCheck(score))
		writeTofile(score);
	score = 0;

	lastWindow(wn);
	//wn.close();
	

}




void mainGame()
{
	 int score=0;
	
	sf::RenderWindow wn(sf::VideoMode(1366, 768), "Asteriod", sf::Style::Default);
	sf::Texture t1, t2;
	sf::Sprite background, explosion;
	//wn.setFramerateLimit(60);

	//score

	sf::Font font;
	sf::Text text;
	if (!font.loadFromFile("arial.ttf")) std::cout << "Error loading Menu Item Font";
	text.setString("SCORE:");
	text.setFont(font);
	text.setFillColor(sf::Color::White);
	text.setPosition(1200, 10);
	text.setCharacterSize(20);
	
	
	

	if (!t1.loadFromFile("background.png"))
	{
		std::cout << "Error loading file";
	}

	background.setTexture(t1);

	//sound buffer
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("bulletsound.ogg"))
		std::cout << "Error loading file";
	sf::Sound sound;
	sound.setBuffer(buffer);
	
	
	sf::SoundBuffer buffer1;
	if (!buffer1.loadFromFile("Explosion.ogg"))
		std::cout << "Error loading file";
	sf::Sound sound1;
	sound1.setBuffer(buffer1);

	player *myplayer = new player();
	collision *c = new collision();
	


	std::list<Bullet*> bulletarray;

	std::list<asteriod*> rocks;

	for (int i = 0; i<12; i++)
	{
		asteriod *a = new asteriod();
		a->setposition(rand() % 1300, rand() % 620, rand() % 360);
		rocks.push_back(a);
	}


	sf::Font numfont;
	sf::Text num1;

	if (!numfont.loadFromFile("arial.ttf")) std::cout << "Error loading Menu Item Font";

	
	num1.setFont(numfont);
	num1.setPosition(1300, 10);
	num1.setCharacterSize(20);
	num1.setFillColor(sf::Color::White);

	//health sprite
	float width, height;
	sf::Texture htexture;
	sf::Sprite hsprite;
	if (!htexture.loadFromFile("health.png"))
	{
		std::cout << "error loading health sprite" << std::endl;
	}
	hsprite.setTexture(htexture);
	hsprite.setScale(0.15f, 0.15f);
	width = htexture.getSize().x / 4.0f;
	height = htexture.getSize().y / 1.0f;
	
	
	float X = 0;
	float Y = 0;


	while (wn.isOpen())
	{
		wn.clear();
		wn.draw(background);
		myplayer->drawplayer(wn);



		sf::Event evnt;
		while (wn.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				wn.close();
				break;
			case sf::Event::KeyPressed:
			{
				myplayer->moveplayer();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))		//create bullet object dynamically
				{
					sound.setVolume(20.0f);
					sound.play();
					Bullet *b = new Bullet();
					b->setposition(myplayer->angle, myplayer->x, myplayer->y);
					bulletarray.push_back(b);

				}

				break;
			}
			}
		}

		if (rocks.size() < 12)
		{
			int i = rand() % 2;
			asteriod *a = new asteriod();
			if (i == 0)
			{
				a->setposition(rand() % 1300, 0, rand() % 360);
			}
			if (i == 1)
			{
				a->setposition(0, rand() % 620, rand() % 360);
			}
			if (a->life == true)
			{
				rocks.push_back(a);
				//std::cout << "hello" << std::endl;
			}
			else
			{
				delete a;

			}
		}

		
		for (auto a : rocks)

		{

			for (auto b : bulletarray)
			{

				if (c->iscollide(b, a))
				{
					sound1.play();
					a->life = 0;
					b->life = 0;
					c->life = true;
					X = a->x;
					Y = a->y;
					score++;
					
					std::string s = std::to_string(score);
					num1.setString(s);
					


					
				}
			}	

			if (c->iscollide1(myplayer, a))
			{
				sound1.play();
				
				hsprite.setTextureRect(sf::IntRect(0, 0, width*plife, height));
				a->life = 0;
				plife--;

				X = myplayer->x;
				Y = myplayer->y;
				c->life = true;

				
				if (plife < 0)
				{
					deadmessage(wn,score);


					//menu Menu(wn);
					//Menu.menuWindowIsOpen(wn);

				}
			}


		}


		for (auto i = rocks.begin(); i != rocks.end();)
		{
			asteriod *a = *i;
			a->update();														//update and draw asteriods
			if (a->life == false)
			{

				//
				i = rocks.erase(i);
				delete a;

			}
			else
			{

				a->drawasteriod(wn);
				i++;
			}


		}

		for (auto i = bulletarray.begin(); i != bulletarray.end();)
		{
			Bullet *b = *i;
			b->update();									//update and draw bullets
			if (b->life == false)
			{
				i = bulletarray.erase(i);
				delete b;
			}

			else
			{
				
				b->drawbullet(wn);
				i++;
			}


		}

		//std::cout << score << std::endl;
		c->explode(wn, X, Y);
		if (c->isEnd())
			c->life = 0;

		myplayer->moveplayer();

		wn.draw(text);
		wn.draw(num1);
		wn.draw(hsprite);

		wn.display();
	}



}






