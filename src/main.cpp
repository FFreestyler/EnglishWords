#include "Menu.h"
#include "Start.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <functional>
#include <iostream>
#include <vector>

using namespace sf;

int main()
{
    const int height = 480; //������ ����
    const int width = 720;  //������ ����
    RenderWindow window(
            VideoMode(width, height),
            "English Words",
            sf::Style::Close); //�������� ����
    window.setVerticalSyncEnabled(
            true); //��������� ������������ ������������� ����

    while (window.isOpen()) //��������� ����
    {
        menu(window);
    }

    return 0;
}
