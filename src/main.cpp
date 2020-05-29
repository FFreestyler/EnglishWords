#include "menu.hpp"
#include "Start.hpp"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <functional>
#include <iostream>
#include <vector>

using namespace sf;

int main()
{
    const int height = 480; //Âûñîòà îêíà
    const int width = 720;  //Øèðèíà îêíà
    RenderWindow window(
            VideoMode(width, height),
            "English Words",
            sf::Style::Close); //Ñîçäàíèå îêíà
    window.setVerticalSyncEnabled(
            true); //Âêëþ÷åíèå âåðòèêàëüíîé ñèíõðîíèçàöèè îêíà

    while (window.isOpen()) //Îòðèñîâêà îêíà
    {
        menu(window);
    }

    return 0;
}
