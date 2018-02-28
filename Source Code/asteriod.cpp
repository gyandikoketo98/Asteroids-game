#include "asteriod.h"
#include <iostream>



asteriod::asteriod()
{
	if (!t2.loadFromFile("asteriod.png"))
	{
		std::cout << "Error loading file";
	}
	asteriods.setTexture(t2);
	//asteriods.setTextureRect(sf::IntRect(0, 0, 64, 64));
	//std::cout << "object has been created" << std::endl;
	asteriods.setOrigin(32, 32);
	asteriods.setScale(0.8, 0.8);
}

void asteriod::setposition(int X,int Y,float sangle)
{

	x = X; y =Y;
	//angle = sangle+1;

	if (x != 0 && y != 0 && x != W && y != H)
		life = false;
	else
		life = true;
	
	
	dx = rand() % 4 -2;
	dy = rand() % 4 -2; 
	if (dx == 0 || dy == 0)
	{
		dx = rand()%2+1;
		dy = rand() %2+1;
	}
	
}


void asteriod::update()
{
	asteriods.setTextureRect(sf::IntRect(frame * 64, 0, 64, 64));
	// (frame>16)?frame =0:frame++;
	
		
	
	
	
		x += dx;
		y += dy;

		if (x > W || x<0 || y>H || y < 0)
			life = false;
		
	


}



void asteriod::drawasteriod(sf::RenderWindow &window)
{
	asteriods.setPosition(x, y);
	//std::cout << "object has been displayed" << std::endl;
	window.draw(asteriods);
	
}
asteriod::~asteriod()
{
}
