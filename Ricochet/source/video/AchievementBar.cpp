#include "AchievementBar.h"

AchievementBar::AchievementBar()
{
    //ctor
}

AchievementBar::~AchievementBar()
{
    //dtor
}

void AchievementBar::setText(string description)
{
    text = description;
}


void AchievementBar::update()
{
    age += gdata.m_timeDelta;
    elapsed_time += (gdata.m_timeDelta * dir);
    if (elapsed_time <= 0)
    {
        dir *= -1;
        elapsed_time = 0;

    }
    else if (elapsed_time >= dur)
    {
        dir *= -1;
        elapsed_time = dur;
    }

    float transparency = (190 * (elapsed_time / dur));

    glow.setColor(sf::Color(255,255,255,64 + transparency));
}

void AchievementBar::init()
{
    gdata.audio->playSound("AchievementUnlocked",true);
    c_box = sf::Color(230,230,230);
    box.setSize(sf::Vector2f(500,50));
    box.setFillColor(c_box);
    box.setOutlineThickness(1);
    box.setOutlineColor(sf::Color(128,128,128));

    renderer.setWindow(gdata.window);
    renderer.setFont(gdata.assets->getFont("purista-medium-14"));
    renderer.setColor(sf::Color(64,64,64));

    trophey.setTexture(*gdata.assets->getTexture("trophey"));
    glow.setTexture(*gdata.assets->getTexture("achieve_glow"));
}

void AchievementBar::draw(int x, int y)
{
    box.setPosition(x,y);
    trophey.setPosition(x,y);
    glow.setPosition(x-15,y-15);

    gdata.window->draw(box);
    gdata.window->draw(trophey);
    gdata.window->draw(glow);

    renderer.setFont(gdata.assets->getFont("segoe-ui-light-20"));
    renderer.setColor(sf::Color::Black);
    renderer.drawString(x+60,y,"Achievement Unlocked!");

    renderer.setFont(gdata.assets->getFont("purista-medium-14"));
    renderer.setColor(sf::Color(94,94,94));
    renderer.drawString(x+60,y+25,text);
}

