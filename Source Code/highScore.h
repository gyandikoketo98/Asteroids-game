#pragma once
#include<SFML\Graphics.hpp>
#include<fstream>
#include<iostream>
#include<string>
class HighScore
{
private:
	sf::RenderWindow window;
	sf::Text text,num;
	sf::Font font,numfont;
	
	

public:
	HighScore(std::string a)
	{
		window.create(sf::VideoMode(400, 400), "High Score",sf::Style::Default);
		if (!font.loadFromFile("arial.ttf")) std::cout << "Error loading Menu Item Font";
		text.setString("High Score is: ");
		text.setFont(font);
		text.setFillColor(sf::Color::Red);
		
		text.setPosition(10,10);
		text.setCharacterSize(25);
		if (!numfont.loadFromFile("arial.ttf")) std::cout << "Error loading Menu Item Font";
		num.setString(a);
		num.setFont(numfont);
		num.setPosition(180,10);
		num.setCharacterSize(25);
		num.setFillColor(sf::Color::Red);
	}
	friend void show();
	void drawHighScore()
	{
		
		while (window.isOpen())
		{
			sf::Event eventX;
			while (window.pollEvent(eventX))
			{
				switch (eventX.type)
				{
				case sf::Event::EventType::Closed:
					window.close();
					break;
				}

			}

			window.clear();
			window.draw(text);
			window.draw(num);
			window.display();
		}
	}
};

void show()
{
	int Score;
	std::ifstream fin("HighScore.txt");
	fin >> Score;
	//	std::cout << HighScore << std::endl;
	fin.close();
	std::string s = std::to_string(Score);
	HighScore h1(s);
	h1.drawHighScore();
	
}