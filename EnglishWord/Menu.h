#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<functional>
#include "Second.h"

using namespace sf;
using namespace std;

void menu(RenderWindow & window)
{
	Texture menuTexture2, menuTexture3;
	menuTexture2.loadFromFile("images/button1.png");
	menuTexture3.loadFromFile("images/button3.png");
	Sprite button2(menuTexture2), button3(menuTexture3);
	bool isMenu = 1;
	int MenuNum = 0;
	button2.setPosition(300, 200);
	button3.setPosition(300, 350);

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
	text.setPosition(263, 120);

	sf::Clock clock;

	while (isMenu)
	{
		MenuNum = 0;
		Event event;

		if (IntRect(300, 200, 150, 75).contains(Mouse::getPosition(window))) { MenuNum = 2; }
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
					if (MenuNum == 2) { Second(window); }
					if (MenuNum == 3) { window.close(); isMenu = false; }
			}

			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time/800;
			cout << time << endl;
		}
		window.setTitle("English Word");
		window.clear(sf::Color(71, 202, 221));
		text.setString("English Words");
		window.draw(text);
		window.draw(FCloudSprite);
		window.draw(SCloudSprite);
		window.draw(button2);
		window.draw(button3);

		window.display();
	}
}
