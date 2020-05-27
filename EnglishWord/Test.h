#pragma once
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<functional>
#include "Menu.h"
#include "Verify.h"
#include <locale.h>
#include <codecvt>
#include "TextBox.h"

using namespace sf;
using namespace std;

void Test(RenderWindow& window, string testnumber)
{
	setlocale(LC_ALL, "RUSSIAN");
	const int height = 480; //Высота окна
	const int width = 720; //Ширина окна
	const int GUI_TEXT_MAX = 24;
	const int wordquantity = 10;
	sf::String words[2][wordquantity];
	TextField field;

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

	Texture VerifyTexture;
	VerifyTexture.loadFromFile("images/verifyb.png");
	Sprite VerifyButton(VerifyTexture);
	VerifyButton.setPosition(524, 434);


	Font font;
<<<<<<< HEAD
	font.loadFromFile("font.ttf");
	const int textsize = 28;
=======
	font.loadFromFile("17904.ttf");
	const int textsize = 25;
>>>>>>> 29df9c7272275c2e410f6701cfd742b7f920608f
	Text text("", font, textsize);
	text.setStyle(Text::Bold);
	text.setPosition(230, 15);

	ifstream wordsfile;

	string tmpstr;
	wordsfile.open("tests/" + testnumber);
	int wordnumber = 0;
	while (!wordsfile.eof())
	{
		wordsfile >> tmpstr;
		words[0][wordnumber] = sf::String(tmpstr);
		wordsfile >> tmpstr;
		words[1][wordnumber] = sf::String(tmpstr);
		wordnumber++;
	}
	wordsfile.close();

	text.setPosition((width / 2) - (field.getCharactersize() * (GUI_TEXT_MAX / 2 + 1)) / 2, height / 2 - 40);
	text.setString(words[1][0]);
	field.setFont(font);
	field.setPosition(sf::Vector2f((width / 2) - (field.getCharactersize() * (GUI_TEXT_MAX / 2 + 1))/2, height / 2));
	field.open();

	int wordcounter = 0;

	while (isMenu)
	{
		Event event;
		MenuNum = 0;

		if (IntRect(274, 434, 173, 32).contains(Mouse::getPosition(window))) { MenuNum = 11; }
		if (IntRect(524, 434, 173, 32).contains(Mouse::getPosition(window))) { MenuNum = 1; }

		window.setTitle("English Word");
		window.clear(sf::Color(21, 132, 149));
		window.draw(BackGrSprite);
		window.draw(ex);
		window.draw(VerifyButton);
		field.render(window);
		window.draw(text);

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
					if (MenuNum == 11)
					{
						isMenu = false;
					}
					if (MenuNum == 1)
					{
						string firstword = field.getText();
						transform(firstword.begin(), firstword.end(), firstword.begin(), tolower);
						string secondword = words[0][wordcounter];
						if (firstword == secondword)
						{
							Verify(window, "y", words[0][wordcounter]);
						}
						else
						{
							Verify(window, "n", words[0][wordcounter]);
						}
						if (wordcounter == wordnumber - 1)
						{
							while (isMenu)
							{
								Text endtext(L"Тест окончен", font, 30);
								endtext.setPosition(275, 210);
								window.clear(sf::Color(21, 132, 149));
								window.draw(BackGrSprite);
								window.draw(ex);
								window.draw(endtext);
								if (IntRect(274, 434, 173, 32).contains(Mouse::getPosition(window))) { MenuNum = 11; }
								while (window.pollEvent(event))
								{
									if (event.type == Event::MouseButtonReleased)
									{
										if (event.mouseButton.button == Mouse::Left)
										{
											if (MenuNum == 11)
											{
												isMenu = false;
											}
										}
									}
								}
								window.display();
							}
						}
						else
						{
							wordcounter++;
							field.clearfield();
							text.setString(words[1][wordcounter]);
						}
					}
				}
			}

			field.input(event);
		}


		window.display();
	}
}