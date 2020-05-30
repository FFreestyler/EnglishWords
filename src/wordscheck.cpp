#include "menu.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <vector>

using namespace sf;
using namespace std;

void wordscheck(RenderWindow& window)
{
    Texture menuTexture1, menuTexture2, menuTexture3;
    menuTexture1.loadFromFile("images/nextButtonSmall.png");
    menuTexture2.loadFromFile("images/ex.png");
    menuTexture3.loadFromFile("images/backButtonSmall.png");

    Sprite button1(menuTexture1), button2(menuTexture2), button3(menuTexture3);
    bool isMenu = 1;
    int MenuNum = 0;

    button1.setPosition(510, 430);
    button2.setPosition(260, 430);
    button3.setPosition(10, 430);

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
    font.loadFromFile("font.ttf");
    Text text("", font, 30);
    text.setStyle(Text::Bold);
    text.setPosition(260, 80);

    sf::Clock clock;

    const int wordquantity = 11;
    sf::String words[2][wordquantity];

    char testnumber = '1';

    ifstream wordsfile;

    string tmpstr, path;
    path = "tests/";
    path += testnumber;
    path += ".txt";
    wordsfile.open(path.c_str());
    int wordnumber = 0;
    while (!wordsfile.eof()) {
        wordsfile >> tmpstr;
        words[0][wordnumber] = sf::String(tmpstr);
        wordsfile >> tmpstr;
        words[1][wordnumber] = sf::String(tmpstr);
        wordnumber++;
    }
    wordsfile.close();

    while (isMenu) {
        MenuNum = 0;
        Event event;

        if (IntRect(260, 430, 173, 32).contains(Mouse::getPosition(window))) {
            MenuNum = 1;
        }
        if (testnumber != '9') {
            if (IntRect(510, 430, 173, 32)
                        .contains(Mouse::getPosition(window))) {
                MenuNum = 2;
            }
        }
        if (testnumber != '1') {
            if (IntRect(10, 430, 173, 32)
                        .contains(Mouse::getPosition(window))) {
                MenuNum = 3;
            }
        }
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                isMenu = false;
                exit(1999);
                window.close();
            }

            if (event.type == Event::MouseButtonReleased) {
                if (event.mouseButton.button == Mouse::Left) {
                    if (MenuNum == 1) {
                        isMenu = false;
                    } else {
                        if (MenuNum == 2) {
                            testnumber++;
                        }
                        if (MenuNum == 3) {
                            testnumber--;
                        }
                        ifstream wordsfile;
                        path = "tests/";
                        path += testnumber;
                        path += ".txt";
                        wordsfile.open(path.c_str());
                        int wordnumber = 0;
                        while (!wordsfile.eof()) {
                            wordsfile >> tmpstr;
                            words[0][wordnumber] = sf::String(tmpstr);
                            wordsfile >> tmpstr;
                            words[1][wordnumber] = sf::String(tmpstr);
                            wordnumber++;
                        }
                        wordsfile.close();
                    }
                }
            }
        }
        window.setTitle("English Words");
        window.clear(sf::Color(71, 202, 221));
        window.draw(FCloudSprite);
        window.draw(SCloudSprite);
        if (testnumber != '9') {
            window.draw(button1);
        }
        if (testnumber != '1') {
            window.draw(button3);
        }
        window.draw(button2);
        for (int wordcounter = 1; wordcounter < 10; ++wordcounter) {
            text.setString(
                    words[1][wordcounter - 1] + " - "
                    + words[0][wordcounter - 1]);
            text.setPosition(220, wordcounter * 40);
            window.draw(text);
        }

        window.display();
    }
    menu(window);
}
