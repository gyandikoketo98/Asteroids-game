#include "player.h"
#include <iostream>
#include <cmath>





player::player()
{
	if (!texture.loadFromFile("spaceship.png"))
	{
		std::cout << "Error loading file";
	}
	
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(40, 0, 40, 40));

	texture.setSmooth(true);
	sprite.setOrigin(20,20);
	
	
}

void player::drawplayer(sf::RenderWindow &window)
{
	sprite.setPosition(x, y);
	//sprite.setRotation(angle+90);
	window.draw(sprite);
}

void player::moveplayer()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		angle -= 0.8;
		sprite.setRotation(angle);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		angle += 1;
		sprite.setRotation(angle );
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		thrust = true;
		sprite.setTextureRect(sf::IntRect(40, 40, 40, 40));
	}
	else
	{
		thrust = false;
		sprite.setTextureRect(sf::IntRect(40, 0, 40, 40));
	}

		if (thrust)
	{
			
			dx += sin(angle*0.0174444)*0.01;
		    dy -= cos(angle*0.0174444)*0.01;
	}
	else
	{
		dx *= 0.99;
		dy *= 0.99;
	}

	speed = sqrt(dx*dx + dy * dy);
	if (speed>maxSpeed)
	{
		dx *= maxSpeed / speed;
		dy *= maxSpeed / speed;
	}


	x += dx;
	y += dy;

	if (x>W) x = 0; if (x<0) x = W;
	if (y>H) y = 0; if (y<0) y = H;
	
	

}



player::~player()
{
}
