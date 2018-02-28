#pragma once

#include<SFML\Graphics.hpp>
#include<iostream>
#include<vector>

class asteriod
{

private:
	float angle = 0;
	sf::Texture t2;
	sf::Sprite asteriods;
	int i = 0 ,W = 1366, H = 768;
	float dx = 0, dy = 0;
	float frame = 0;
	float speed = 1;
  
public:
	float  x, y, R = 25;
	bool life;

	asteriod();
	~asteriod();
	void setposition(int X, int Y, float sangle);
	void update();
	void drawasteriod(sf::RenderWindow &window);
};

