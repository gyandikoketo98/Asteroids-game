#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include "Bullet.h"
#include "asteriod.h"
#include "player.h"

class collision
{
private:
	sf::Texture t2;
	sf::Sprite explosion;
	float frame = 0;
	float animspeed = .1;
	int framecount = 20;


public:
	 
	bool life = false;
	collision();
	~collision();
	bool iscollide(Bullet *b, asteriod *a);
	bool iscollide1(player *p, asteriod *a);
	void explode(sf::RenderWindow &window, float x, float y);
	bool isEnd();
};


