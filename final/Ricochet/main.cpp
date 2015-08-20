#include <iostream>

#include "general.h"

#include "system/Engine.h"
#include "system/GameData.h"
#include "system/Settings.h"

using namespace std;

int main()
{
    cout << "Template Project v0.1" << endl;

    Settings settings;
    gdata.settings = &settings;
    settings.readSettings();

    int flags = 0;
    if (settings.getFullscreen())   flags = sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen;
    else                            flags = sf::Style::Titlebar | sf::Style::Close;

    sf::RenderWindow window(sf::VideoMode(settings.getScreenWidth(), settings.getScreenHeight()), "Template v0.01",flags);
    window.setFramerateLimit(settings.getFpsLimit());
    window.setVerticalSyncEnabled(settings.getVsync());
    gdata.window = &window;

    Engine game;
    game.initialise();
    game.run();
    game.exit();

    return 0;
}
