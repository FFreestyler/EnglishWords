#include "Menu.h"
#include "TextBox.h"
#include "Verify.h"
#include <SFML/Graphics.hpp>
#include <codecvt>
#include <fstream>
#include <functional>
#include <iostream>
#include <locale.h>
#include <string>
#include <vector>

using namespace sf;
using namespace std;

void Test(RenderWindow& window, string testnumber)
{
    setlocale(LC_ALL, "RUSSIAN");
    const int height = 480; //������ ����
    const int width = 720;  //������ ����
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
    font.loadFromFile("font.ttf");
    const int textsize = 25;
    Text text("", font, textsize);
    text.setStyle(Text::Bold);
    text.setPosition(230, 15);

    ifstream wordsfile;

    string tmpstr;
    wordsfile.open("tests/" + testnumber);
    int wordnumber = 0;
    while (!wordsfile.eof()) {
        wordsfile >> tmpstr;
        words[0][wordnumber] = sf::String(tmpstr);
        wordsfile >> tmpstr;
        words[1][wordnumber] = sf::String(tmpstr);
        wordnumber++;
    }
    wordsfile.close();

    text.setPosition(
            (width / 2)
                    - (field.getCharactersize() * (GUI_TEXT_MAX / 2 + 1)) / 2,
            height / 2 - 40);
    text.setString(words[1][0]);
    field.setFont(font);
    field.setPosition(sf::Vector2f(
            (width / 2)
                    - (field.getCharactersize() * (GUI_TEXT_MAX / 2 + 1)) / 2,
            height / 2));
    field.open();

    int wordcounter = 0;

    while (isMenu) {
        Event event;
        MenuNum = 0;

        if (IntRect(274, 434, 173, 32).contains(Mouse::getPosition(window))) {
            MenuNum = 11;
        }
        if (IntRect(524, 434, 173, 32).contains(Mouse::getPosition(window))) {
            MenuNum = 1;
        }

        window.setTitle("English Word");
        window.clear(sf::Color(21, 132, 149));
        window.draw(BackGrSprite);
        window.draw(ex);
        window.draw(VerifyButton);
        field.render(window);
        window.draw(text);

        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                isMenu = false;
                exit(1999);
                window.close();
            }

            if (event.type == Event::MouseButtonReleased) {
                if (event.mouseButton.button == Mouse::Left) {
                    if (MenuNum == 11) {
                        isMenu = false;
                    }
                    if (MenuNum == 1) {
                        string firstword = field.getText();
                        transform(
                                firstword.begin(),
                                firstword.end(),
                                firstword.begin(),
                                tolower);
                        string secondword = words[0][wordcounter];
                        if (firstword == secondword) {
                            Verify(window, "y", words[0][wordcounter]);
                        } else {
                            Verify(window, "n", words[0][wordcounter]);
                        }
                        if (wordcounter == wordnumber - 1) {
                            while (isMenu) {
                                Text endtext(L"���� �������", font, 30);
                                endtext.setPosition(275, 210);
                                window.clear(sf::Color(21, 132, 149));
                                window.draw(BackGrSprite);
                                window.draw(ex);
                                window.draw(endtext);
                                if (IntRect(274, 434, 173, 32)
                                            .contains(Mouse::getPosition(
                                                    window))) {
                                    MenuNum = 11;
                                }
                                while (window.pollEvent(event)) {
                                    if (event.type
                                        == Event::MouseButtonReleased) {
                                        if (event.mouseButton.button
                                            == Mouse::Left) {
                                            if (MenuNum == 11) {
                                                isMenu = false;
                                            }
                                        }
                                    }
                                }
                                window.display();
                            }
                        } else {
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