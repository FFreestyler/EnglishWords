#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<functional>
#include "Menu.h"

using namespace sf;

void First(RenderWindow& window)
{

	Texture exTexture;
	exTexture.loadFromFile("images/ex.png");
	Sprite ex(exTexture);
	bool isMenu = 1;
	int MenuNum = 0;
	ex.setPosition(280, 435);

	Image BackGr;
	BackGr.loadFromFile("images/backgr.png");
	Texture BackGrTexture;
	BackGrTexture.loadFromImage(BackGr);
	Sprite BackGrSprite;
	BackGrSprite.setTexture(BackGrTexture);
	BackGrSprite.setPosition(0, 0);


	Font font;
	font.loadFromFile("Winter Snow.ttf");
	Text text("", font, 30);
	text.setStyle(Text::Bold);
	text.setPosition(255, 120);

	while (isMenu)
	{
		Event event;
		MenuNum = 0;

		if (IntRect(280, 435, 173, 32).contains(Mouse::getPosition(window))) { MenuNum = 1; }

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isMenu = false;
				exit(1999);
				window.close();
			}

			if (event.type == Event::MouseButtonReleased) {
				if (event.mouseButton.button == Mouse::Left)
					if (MenuNum == 1) { isMenu = false; }
			}
		}
		text.setString("");
		window.setTitle("English Word");
		window.clear(sf::Color(21, 132, 149));
		window.draw(text);
		window.draw(BackGrSprite);
		window.draw(ex);

		window.display();
	}
}