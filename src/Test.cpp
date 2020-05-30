#include "Start.hpp"
#include "TextBox.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <functional>
#include <string.h>
#include <vector>

using namespace sf;
using namespace std;

void Test(sf::RenderWindow& window, const char* testnumber)
{
    const int height = 480;
    const int width = 720;
    const int GUI_TEXT_MAX = 24;
    const int wordquantity = 11;
    sf::String words[2][wordquantity];
    TextField field;

    Texture exTexture;
    exTexture.loadFromFile("images/ex.png");
    Sprite ex(exTexture);
    bool isMenu = 1;
    bool isMenu1 = 0;
    sf::String verify;
    int MenuNum = 0;
    int MenuNum1 = 0;
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
    nextButton.setPosition(290, 390);

    Font font;
    font.loadFromFile("Domkrat Bold.Ttf");
    const int textsize = 25;
    Text text("", font, textsize);
    text.setStyle(Text::Bold);
    text.setPosition(230, 15);

    string path = testnumber;

    ifstream wordsfile(path.c_str());
    string tmpstr;

    int wordnumber = 0;
    while (!wordsfile.eof()) {
        wordsfile >> tmpstr;
        words[0][wordnumber] = sf::String(tmpstr);
        wordsfile >> tmpstr;
        words[1][wordnumber] = sf::String(tmpstr);
        wordnumber++;
    }
    wordsfile.close();
    string firstword;
    string secondword;

    int wordcounter = 0;

    Text text2("", font, 30), text1(L"Верный ответ:", font, 30);
    Text CorrectWord(words[0][wordcounter], font, 30);

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

    while (isMenu) {
        Event event;
        MenuNum = 0;
        MenuNum1 = 0;

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
                        if (wordcounter < wordnumber - 1) {
                            firstword = field.getText();
                            transform(
                                    firstword.begin(),
                                    firstword.end(),
                                    firstword.begin(),
                                    _tolower);
                            secondword = words[0][wordcounter];
                        }
                        if (firstword == secondword) {
                            text2.setString(L"Ответ верный");
                            text2.setPosition(270, 210);
                            verify = "y";

                        } else {
                            text2.setString(L"Ответ неверный");
                            text2.setPosition(260, 210);
                            text1.setPosition(260, 240);
                            CorrectWord.setPosition(430, 240);
                            verify = "n";
                        }

                        isMenu1 = 1;
                        while (isMenu1) {
                            if (IntRect(290, 390, 150, 75)
                                        .contains(Mouse::getPosition(window))) {
                                MenuNum1 = 1;
                            }

                            while (window.pollEvent(event)) {
                                if (event.type == Event::Closed) {
                                    isMenu = false;
                                    exit(1999);
                                    window.close();
                                }

                                if (event.type == Event::MouseButtonReleased) {
                                    if (event.mouseButton.button
                                        == Mouse::Left) {
                                        if (MenuNum1 == 1) {
                                            isMenu1 = false;
                                        }
                                    }
                                }
                            }
                            window.setTitle("English Word");
                            window.clear(sf::Color(71, 202, 221));
                            window.draw(text2);
                            if (verify == "n") {
                                window.draw(text1);
                                window.draw(CorrectWord);
                            }
                            window.draw(nextButton);
                            window.draw(FCloudSprite);
                            window.draw(SCloudSprite);

                            window.display();
                        }
                        if (wordcounter < wordnumber - 1) {
                            wordcounter++;
                            field.clearfield();
                            text.setString(words[1][wordcounter]);
                            CorrectWord.setString(words[0][wordcounter]);
                        }
                        if (wordcounter > wordnumber - 2) {
                            while (isMenu) {
                                Text endtext(L"Тест окончен", font, 30);
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
                                                isMenu1 = false;
                                            }
                                        }
                                    }
                                }
                                window.display();
                            }
                        }
                    }
                }
            }

            field.input(event);
        }

        window.display();
    }
    Start(window);
}
