#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include <functional>
#include "Second.h"
#include "Menu.h"

using namespace sf;

void Second(RenderWindow& window)
{
    Texture exTexture;
    exTexture.loadFromFile("images/ex.png");
    Sprite ex(exTexture);
    bool isMenu = 1;
    int MenuNum = 0;
    ex.setPosition(274, 434);

    Image BackGr;
    BackGr.loadFromFile("images/backgr1.png");
    Texture BackGrTexture;
    BackGrTexture.loadFromImage(BackGr);
    Sprite BackGrSprite;
    BackGrSprite.setTexture(BackGrTexture);
    BackGrSprite.setPosition(0, 0);

    Texture testbut1, testbut2, testbut3, testbut4, testbut5, testbut6, testbut7, testbut8, testbut9, testbut10;
    testbut1.loadFromFile("images/testbut1.png");
    testbut2.loadFromFile("images/testbut2.png");
    testbut3.loadFromFile("images/testbut3.png");
    testbut4.loadFromFile("images/testbut4.png");
    testbut5.loadFromFile("images/testbut5.png");
    testbut6.loadFromFile("images/testbut6.png");
    testbut7.loadFromFile("images/testbut7.png");
    testbut8.loadFromFile("images/testbut8.png");
    testbut9.loadFromFile("images/testbut9.png");
    testbut10.loadFromFile("images/testbut10.png");
    Sprite testbut1Texture(testbut1), testbut2Texture(testbut2), testbut3Texture(testbut3), testbut4Texture(testbut4), testbut5Texture(testbut5),
        testbut6Texture(testbut6), testbut7Texture(testbut7), testbut8Texture(testbut8), testbut9Texture(testbut9), testbut10Texture(testbut10);
    //bool isMenu = 1;
    //int MenuNum = 0;
    testbut1Texture.setPosition(50, 50);
    testbut2Texture.setPosition(269, 50);
    testbut3Texture.setPosition(488, 50);
    testbut4Texture.setPosition(50, 145);
    testbut5Texture.setPosition(269, 145);
    testbut6Texture.setPosition(488, 145);
    testbut7Texture.setPosition(50, 240);
    testbut8Texture.setPosition(269, 240);
    testbut9Texture.setPosition(488, 240);
    testbut10Texture.setPosition(269, 335);

    Font font;
    font.loadFromFile("Winter Snow.ttf");
    Text text("", font, 30);
    text.setStyle(Text::Bold);
    text.setPosition(255, 120);

    while (isMenu)
    {
        Event event;
        MenuNum = 0;

        if (IntRect(274, 434, 173, 32).contains(Mouse::getPosition(window))) { MenuNum = 11; }
        if (IntRect(50, 50, 182, 63).contains(Mouse::getPosition(window))) { MenuNum = 1; }
        if (IntRect(269, 50, 182, 63).contains(Mouse::getPosition(window))) { MenuNum = 2; }
        if (IntRect(488, 50, 182, 63).contains(Mouse::getPosition(window))) { MenuNum = 3; }
        if (IntRect(50, 145, 182, 63).contains(Mouse::getPosition(window))) { MenuNum = 4; }
        if (IntRect(269, 145, 182, 63).contains(Mouse::getPosition(window))) { MenuNum = 5; }
        if (IntRect(488, 145, 182, 63).contains(Mouse::getPosition(window))) { MenuNum = 6; }
        if (IntRect(50, 240, 182, 63).contains(Mouse::getPosition(window))) { MenuNum = 7; }
        if (IntRect(269, 240, 182, 63).contains(Mouse::getPosition(window))) { MenuNum = 8; }
        if (IntRect(488, 240, 182, 63).contains(Mouse::getPosition(window))) { MenuNum = 9; }
        if (IntRect(269, 335, 182, 63).contains(Mouse::getPosition(window))) { MenuNum = 10; }

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
                    if (MenuNum == 11) { isMenu = false; }
                    if (MenuNum == 1) { printf("1"); }
					if (MenuNum == 2) { printf("2"); }
					if (MenuNum == 3) { printf("3"); }
					if (MenuNum == 4) { printf("4"); }
					if (MenuNum == 5) { printf("5"); }
					if (MenuNum == 6) { printf("6"); }
					if (MenuNum == 7) { printf("7"); }
					if (MenuNum == 8) { printf("8"); }
					if (MenuNum == 9) { printf("9"); }
					if (MenuNum == 10) { printf("10"); }
                    
            }
        }
        text.setString("");
        window.setTitle("English Word");
        window.clear(sf::Color(21, 132, 149));
        window.draw(text);
        window.draw(BackGrSprite);
        window.draw(ex);
        window.draw(testbut1Texture); window.draw(testbut2Texture); window.draw(testbut3Texture); window.draw(testbut4Texture); window.draw(testbut5Texture);
        window.draw(testbut6Texture); window.draw(testbut7Texture); window.draw(testbut8Texture); window.draw(testbut9Texture); window.draw(testbut10Texture);

        window.display();
    }
}