#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<functional>
#include "First.h"
#include "Second.h"

using namespace sf;

void menu(RenderWindow & window)
{
	Texture menuTexture1, menuTexture2, menuTexture3;
	menuTexture1.loadFromFile("images/button1.png");
	menuTexture2.loadFromFile("images/button2.png");
	menuTexture3.loadFromFile("images/button3.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3);
	bool isMenu = 1;
	int MenuNum = 0;
	menu1.setPosition(200, 200);
	menu2.setPosition(400, 200);
	menu3.setPosition(300, 350);

	Image FirstCloud;
	FirstCloud.loadFromFile("images/Cloud.png");

	Texture FCloudTexture;
	FCloudTexture.loadFromImage(FirstCloud);

	Sprite FCloudSprite;
	FCloudSprite.setTexture(FCloudTexture);
	FCloudSprite.setPosition(-65, 35);

	Image SecondCloud;
	SecondCloud.loadFromFile("images/SCloud.png");

	Texture SCloudTexture;
	SCloudTexture.loadFromImage(SecondCloud);

	Sprite SCloudSprite;
	SCloudSprite.setTexture(SCloudTexture);
	SCloudSprite.setPosition(550, 200);

	Font font;
	font.loadFromFile("Winter Snow.ttf");
	Text text("", font, 30);
	text.setStyle(Text::Bold);
	text.setPosition(255, 120);

	while (isMenu)
	{
		MenuNum = 0;
		Event event;
		menu1.setColor(Color::White);

		if (IntRect(200, 200, 150, 75).contains(Mouse::getPosition(window))) { MenuNum = 1; }
		if (IntRect(400, 200, 150, 75).contains(Mouse::getPosition(window))) { MenuNum = 2; }
		if (IntRect(300, 350, 150, 75).contains(Mouse::getPosition(window))) { MenuNum = 3; }

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
					if (MenuNum == 1) { First(window); }
					if (MenuNum == 2) { Second(window); }
					if (MenuNum == 3) { window.close(); isMenu = false; }
			}
		}
		window.setTitle("English Word");
		window.clear(sf::Color(71, 202, 221));
		text.setString("English Words");
		window.draw(text);
		window.draw(FCloudSprite);
		window.draw(SCloudSprite);
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}
}
