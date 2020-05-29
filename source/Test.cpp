#include "Menu.h"
#include "TextBox.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace sf;
using namespace std;

void Test(RenderWindow& window, string testnumber)
{
    const int height = 480; //Высота окна
    const int width = 720;  //Ширина окна
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

    Font font;
    font.loadFromFile("Winter Snow.ttf");
    const int textsize = 28;
    Text text("", font, textsize);
    text.setStyle(Text::Bold);
    text.setPosition(230, 15);

    ifstream wordsfile;
    string tmpstr;
    wordsfile.open("tests/" + testnumber);
    int wordnumber = 0;
    while (!wordsfile.eof()) {
        wordsfile >> tmpstr;
        words[0][wordnumber] = tmpstr;
        wordsfile >> tmpstr;
        words[1][wordnumber] = tmpstr;
        wordnumber++;
    }
    wordsfile.close();

    text.setPosition(
            (width / 2)
                    - (field.getCharactersize() * (GUI_TEXT_MAX / 2 + 1)) / 2,
            height / 2 - 40);
    text.setString(words[0][0]);
    field.setFont(font);
    field.setPlaceholder("Your answer");
    field.setPosition(sf::Vector2f(
            (width / 2)
                    - (field.getCharactersize() * (GUI_TEXT_MAX / 2 + 1)) / 2,
            height / 2));
    field.open();

    while (isMenu) {
        Event event;
        MenuNum = 0;

        if (IntRect(274, 434, 173, 32).contains(Mouse::getPosition(window))) {
            MenuNum = 11;
        }
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                isMenu = false;
                exit(1999);
                window.close();
            }

            if (event.type == Event::MouseButtonReleased) {
                if (event.mouseButton.button == Mouse::Left)
                    if (MenuNum == 11) {
                        isMenu = false;
                    }
            }
        }
        window.setTitle("English Word");
        window.clear(sf::Color(21, 132, 149));
        window.draw(BackGrSprite);
        window.draw(ex);
        field.render(window);
        window.draw(text);

        window.display();
    }
}