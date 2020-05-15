#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<functional>

void menu(RenderWindow& window)
{
	Texture menuTexture1, menuTexture2, menuTexture3;
	menuTexture1.loadFromFile("images/button1.png");
	menuTexture2.loadFromFile("images/button2.png");
	menuTexture3.loadFromFile("images/button3.png");
	Sprite menu1(menuTexture1), menu2(menuTexture2), menu3(menuTexture3);
	bool isMenu = 1;
	int MenuNum = 0;
	menu1.setPosition(200, 200);
	menu2.setPosition(400, 200);
	menu3.setPosition(300, 350);

	while (isMenu)
	{

		MenuNum = 0;

		if (IntRect(200, 200, 0, 0).contains(Mouse::getPosition(window))) { MenuNum = 1; }

		if (Mouse::isButtonPressed(Mouse::Left)) {
			if (MenuNum == 1) { window.close(); isMenu = false; }
		}
		window.draw(menu1);
		window.draw(menu2);
		window.draw(menu3);

		window.display();
	}



}
