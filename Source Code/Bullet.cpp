

#include "Bullet.h"
#include <iostream>
#include <cmath>


Bullet::Bullet()
{
	if (!t1.loadFromFile("redbullet.png"))
	{
		std::cout << "Error loading file";
	}
	
	bullet.setTexture(t1);
	bullet.setTextureRect(sf::IntRect(0, 0, 32, 32));
	bullet.setScale(0.6, 0.8);
	bullet.setOrigin(20, 30);

	bullet.setPosition(x, y);
}

Bullet::~Bullet()
{
	
}

void Bullet::setposition(float a, float X, float Y)
{
	x = X; y = Y;
	angle = a;

}



void Bullet::update()
{
	
	
	
	dx = sin(angle*0.0174444)*3;
	dy = -cos(angle*0.0174444)*3;
	
	x += dx;
	y += dy;

	if (x > W || x<0 || y > H || y < 0)
	{
		life = false;
		
	}
	bullet.setPosition(x, y);
	
}

void Bullet::drawbullet(sf::RenderWindow &window)
{
		
		bullet.setRotation(angle);
		window.draw(bullet);
		
}



