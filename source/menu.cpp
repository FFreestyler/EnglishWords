#include <SFML/Graphics.hpp>
#include<iostream>
#include<fstream>
#include<vector>
#include<functional>
#include "Menu.h"
#include "Second.h"

using namespace sf;

int main()
{
	const int height = 480; //Высота окна
	const int width = 720; //Ширина окна
	RenderWindow window(VideoMode(width, height), "English Words", sf::Style::None);//Создание окна
	window.setVerticalSyncEnabled(true);//Включение вертикальной синхронизации окна

	while (window.isOpen()) //Отрисовка окна
	{
		menu(window);
	}

	return 0;
}