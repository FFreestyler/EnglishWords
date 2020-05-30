#include "Start.hpp"
#include "menu.hpp"
#include <SFML/Graphics.hpp>
#include <functional>
#include <vector>

using namespace sf;

int main()
{
    const int height = 480; // Window height
    const int width = 720;  // Window width
    RenderWindow window(
            VideoMode(width, height),
            "English Words",
            sf::Style::Close);           // Create window
    window.setVerticalSyncEnabled(true); // Enabled Vertical Sync

    while (window.isOpen()) // Open window
    {
        menu(window);
    }

    return 0;
}
