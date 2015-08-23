#include <iostream>

#include "general.h"

#include "system/Engine.h"
#include "system/GameData.h"
#include "system/Settings.h"

using namespace std;

int main()
{

    #undef b2_velocityThreshold
    #define b2_velocityThreshold 0.001f

    cout << "Template Project v0.1" << endl;

    Settings settings;
    gdata.settings = &settings;
    settings.readSettings();

    int flags = 0;
    if (settings.getFullscreen())   flags = sf::Style::Titlebar | sf::Style::Close | sf::Style::Fullscreen;
    else                            flags = sf::Style::Titlebar | sf::Style::Close;


    sf::ContextSettings s;
    s.antialiasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode(settings.getScreenWidth(), settings.getScreenHeight()), "Template v0.01",flags,s);
    window.setFramerateLimit(settings.getFpsLimit());
    window.setVerticalSyncEnabled(settings.getVsync());
    //window.setVerticalSyncEnabled(true);
    gdata.window = &window;

    Engine game;
    game.initialise();
    game.run();
    game.exit();

    return 0;
}
