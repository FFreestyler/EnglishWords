#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP
#include <SFML/Graphics.hpp>

class TextField {
public:
    TextField();

    void setPosition(sf::Vector2f vec);

    void input(sf::Event ev);

    void setFont(sf::Font& f);

    const sf::String& getText();

    void setPlaceholder(std::string str);

    void render(sf::RenderWindow& window);

    void setLength(int arg);

    int getTextLength();

    bool isActive();

    void open();

    int getCharactersize();

private:
    sf::Text txt;
    sf::RectangleShape box;

    int size;

    int length;

    int CharacterSize;

    bool renderPlaceholder;

    void setActive(bool arg);

    bool active;

    sf::Vector2f pos;

    std::string placeholder;
};

#endif