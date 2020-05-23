#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<functional>
#include "Menu.h"

using namespace sf;

void TestFirst(RenderWindow& window)
{

	Texture exTexture;
	exTexture.loadFromFile("images/ex.png");
	Sprite ex(exTexture);
	bool isMenu = 1;
	int MenuNum = 0;
	ex.setPosition(274, 434);

	Image BackGr;
	BackGr.loadFromFile("images/backgr.png");
	Texture BackGrTexture;
	BackGrTexture.loadFromImage(BackGr);
	Sprite BackGrSprite;
	BackGrSprite.setTexture(BackGrTexture);
	BackGrSprite.setPosition(0, 0);


	Font font;
	font.loadFromFile("Winter Snow.ttf");
	Text text("", font, 28);
	text.setStyle(Text::Bold);
	text.setPosition(230, 15);

	sf::String English[10] = { "ABC" , "CDE" };
	text.setPosition(250, 200);
	text.setString(English[0] + " " + English[1]);

	while (isMenu)
	{
		Event event;
		MenuNum = 0;

		if (IntRect(274, 434, 173, 32).contains(Mouse::getPosition(window))) { MenuNum = 11; }

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
				if (MenuNum == 11) { isMenu = false; }
			}
		}
		window.setTitle("English Word");
		window.clear(sf::Color(21, 132, 149));
		window.draw(BackGrSprite);
		window.draw(ex);
		window.draw(text);


		window.display();
	}
}