#pragma once
#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<functional>
#include "Second.h"

using namespace sf;
using namespace std;

void Verify(RenderWindow& window, string verify, string correctw)
{
	
	bool isMenu = 1;
	int MenuNum = 0;

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

	Texture nextButtonTexture;
	Image Button;
	Button.loadFromFile("images/nextButton.png");
	nextButtonTexture.loadFromImage(Button);
	Sprite nextButton;
	nextButton.setTexture(nextButtonTexture);
	nextButton.setPosition(290,390);

	Font font;
	font.loadFromFile("Domkrat Bold.ttf");
	Text text("", font, 30);
	text.setStyle(Text::Bold);
	text.setPosition(281, 120);

	Text text1(L"Верный ответ:", font, 30);
	Text CorrectWord(correctw, font, 30);

	if (verify == "y")
	{
		text.setString(L"Ответ верный");
		text.setPosition(270, 210);
	}
	else
	{
		text.setString(L"Ответ неверный");
		text.setPosition(260, 210);
		text1.setPosition(260, 240);
		CorrectWord.setPosition(450, 240);
	}

	sf::Clock clock;

	while (isMenu)
	{
		MenuNum = 0;
		Event event;

		if (IntRect(290, 390, 150, 75).contains(Mouse::getPosition(window))) { MenuNum = 1; }

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isMenu = false;
				exit(1999);
				window.close();
			}

			if (event.type == Event::MouseButtonReleased)
			{
				if (event.mouseButton.button == Mouse::Left)
				{
					if (MenuNum == 1)
					{
						isMenu = false;
					}
				}
			}
		}
		window.setTitle("English Word");
		window.clear(sf::Color(71, 202, 221));
		window.draw(text);
		if (verify == "n")
		{
			window.draw(text1);
			window.draw(CorrectWord);
		}
		window.draw(nextButton);
		window.draw(FCloudSprite);
		window.draw(SCloudSprite);

		window.display();
	}
}
