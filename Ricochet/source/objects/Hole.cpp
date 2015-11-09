#include "Hole.h"

Hole::Hole()
{
    //ctor
    m_type = HOLE;
}

Hole::~Hole()
{
    //dtor
}

void Hole::onUpdate()
{
    m_image.setOrigin( m_image.getTexture()->getSize().x / 2, m_image.getTexture()->getSize().y / 2 );
}

void Hole::onEnterCollision(CollisionData cd)
{
    if (cd.objectB->m_type == PLAYER)
    {
        if (gdata.countdown <= 0)
        {
            cout << "you won" << endl;
            gdata.audio->playSound("victory");
            m_image.setTexture(*gdata.assets->getTexture("hole_on"));
            cd.objectB->setLinearVelocity(Vector2(0,0));
            cd.objectB->m_active = false;
            gdata.show_progress = true;

            if (gdata.bounce_counter >= 20)
            {
                AchievementBar* a = new AchievementBar;
                a->init();
                a->setText("Complete a level while getting at least 20 bounces");
                gdata.achieves.push_back(a);
            }
        }
        //gdata.delay_reload = true;
    }
    else if (cd.objectB->m_type == GHOST_PLAYER)
    {
        m_image.setTexture(*gdata.assets->getTexture("hole_on"));
        cd.objectB->setLinearVelocity(Vector2(0,0));
        cd.objectB->m_active = false;
        gdata.show_progress = true;
    }
}


