#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>



static int plife = 3;

class player
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RectangleShape rect;
	float dx=0,dy=0,W = 1366.f, H = 768.f;
	bool thrust;

	float maxSpeed = 1.5f;
	float speed;
	sf::Vector2u spritesize;
	


public:
	float R = 20;
	static int plife ;

	float x = 1366.0/2.0, y = 768.0/2.0;
	float angle = 0.f;
	

	player();
	void drawplayer(sf::RenderWindow &window);
	void moveplayer();
	//void rotateplayer(sf::RenderWindow &window);
	//sf::Vector2f playerposition();
	~player();
};

