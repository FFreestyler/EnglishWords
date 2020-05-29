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
    const int height = 480; //Высота окна
    const int width = 720;  //Ширина окна
    RenderWindow window(
            VideoMode(width, height),
            "English Words",
            sf::Style::Close); //Создание окна
    window.setVerticalSyncEnabled(
            true); //Включение вертикальной синхронизации окна

    while (window.isOpen()) //Отрисовка окна
    {
        menu(window);
    }

    return 0;
}
