#ifndef TXTFIELD_H
#define TXTFIELD_H

#include <string>

#include <SFML/Graphics.hpp>


const int GUI_TEXT_MAX = 24;

const int GUI_TEXT_BACKSPACE = 8;
const int GUI_TEXT_ESCAPE = 27;

const sf::Color GUI_TEXT_WHITE = sf::Color(255, 255, 255);

class TextField {
public:
	TextField()
	{
		active = false;
		box.setFillColor(sf::Color::White);
		box.setOutlineThickness(1);

		renderPlaceholder = false;
		placeholder = "";

		txt.setFillColor(sf::Color::Black);

		CharacterSize = 18;

		size = GUI_TEXT_MAX;

		length = 0;
	}

	void setPosition(sf::Vector2f vec)
	{
		box.setPosition(vec);
		txt.setPosition(vec - sf::Vector2f(120, -5));
	}

	void input(sf::Event ev)
	{
		if (ev.type == sf::Event::MouseButtonReleased) {
			sf::Vector2f pos(ev.mouseButton.x, ev.mouseButton.y);
			if (box.getGlobalBounds().contains(pos)) {
				setActive(true);
			}
			else {
				setActive(false);
			}
		}

		if (ev.type == sf::Event::TextEntered && active) {
			sf::String str = txt.getString();

			if (ev.text.unicode == GUI_TEXT_BACKSPACE) {
				if (str.getSize() > 0) {
					length--;
					str = str.substring(0, str.getSize() - 1);
				}
			}
			else if (ev.text.unicode == GUI_TEXT_ESCAPE) {
				setActive(false);
			}
			else {
				sf::String sfstr = "";
				sfstr += ev.text.unicode;
				str += sfstr.toAnsiString();
			}

			if (str.getSize() == size) return;

			txt.setString(str);
			length++;
		}
	}

	void setFont(sf::Font& f)
	{
		txt.setFont(f);
		txt.setCharacterSize(18);

		box.setSize(sf::Vector2f((txt.getCharacterSize() * (size / 2 + 1)) + 10, txt.getCharacterSize() + 10));
	}

	const sf::String& getText()
	{
		return txt.getString();
	}

	void setPlaceholder(std::string str)
	{
		placeholder = str;
		renderPlaceholder = true;
		txt.setFillColor(GUI_TEXT_WHITE);
		txt.setString(placeholder);
		setActive(false);
	}

	void render(sf::RenderWindow& window)
	{
		window.draw(box);
		window.draw(txt);
	}

	void setLength(int arg)
	{
		size = arg;

		box.setSize(sf::Vector2f((txt.getCharacterSize() * (size / 2 + 1)) + 10, txt.getCharacterSize() + 10));
	}

	int getTextLength()
	{
		return length;
	}

	bool isActive()
	{
		return active;
	}

	void open()
	{
		setActive(true);
	}
	int getCharactersize()
	{
		return CharacterSize;
	}
private:
	sf::Text txt;
	sf::RectangleShape box;

	int size;

	int length;

	int CharacterSize;

	bool renderPlaceholder;

	void setActive(bool arg)
	{
		active = arg;
		if (active) {
			box.setOutlineColor(sf::Color::Red);
		}
		else {
			box.setOutlineColor(sf::Color::White);
		}

		/*if (renderPlaceholder && arg) {
			renderPlaceholder = false;
			txt.setString("");
			txt.setFillColor(sf::Color::Black);
		}*/
	}
	
	bool active;

	sf::Vector2f pos;

	std::string placeholder;
};

#endif