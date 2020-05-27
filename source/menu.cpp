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
	const int height = 480; //������ ����
	const int width = 720; //������ ����
	RenderWindow window(VideoMode(width, height), "English Words", sf::Style::None);//�������� ����
	window.setVerticalSyncEnabled(true);//��������� ������������ ������������� ����

	while (window.isOpen()) //��������� ����
	{
		menu(window);
	}

	return 0;
}