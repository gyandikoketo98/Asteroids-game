

#include "collision.h"
#include <iostream>
#include <cmath>
#include "Bullet.h"
#include "asteriod.h"


collision::collision()
{
	if (!t2.loadFromFile("explosion.png"))
	{
		std::cout << "Error loading file";
	}
	

	explosion.setTexture(t2);
	//std::cout << t2.getSize().x << "  " << t2.getSize().y << std::endl;
	//explosion.setScale(1.5, 1.5);
	explosion.setOrigin(128, 128);
	
	
}

bool collision::iscollide(Bullet *b, asteriod *a)
{

	if ((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y) <
		(b->R + a->R) *(b->R + a->R)) {
		a->life = 0;
		b->life = 0;
		return true;

	}
	else
		return false;

}

bool collision::iscollide1(player *p, asteriod *a)
{
	

	if ((a->x - p->x) * (a->x - p->x) + (a->y - p->y) * (a->y - p->y) <
		(p->R + a->R) *(p->R + a->R)) {
		
		return true;

	}
	else
	{
		
		return false;
		
	}
	
}



void collision::explode(sf::RenderWindow &window, float x, float y)
{
	if (life == true)
	{
	
	frame += animspeed;
	if (frame > framecount) frame -= framecount;
	explosion.setPosition(x, y);
	explosion.setTextureRect(sf::IntRect(int(frame) * 256, 0, 256, 256));
	window.draw(explosion);
	
	}
	
}
bool collision::isEnd()
{

	return (frame + animspeed >= 20);
}

collision::~collision()
{
}
