#ifndef LASER_H
#define LASER_H

#include "general.h"
#include "Obstacle.h"
#include "system/AssetManager.h"
#include "video/particles/SparksEmitter.h"

class Laser : public Obstacle
{
    public:
        Laser();
        virtual ~Laser();

    public:
        SparksEmitter emitter;

        sf::Sprite laser_beam;
        sf::Sprite laser_end;

        sf::Sprite laser_head;

        float start_angle = 0;
        float delta_angle = 0;
        float r_duration = 0;
        float r_time = 0;
        bool increasing = false;
        bool rotating = false;

        float rotation_speed = 0;

        float rotation = 0;
        float stand_rotation = 0;

        Vector2 rotated_laser;
        Vector2 laser_dir;  // normalised vec of the direction the laser is pointing
		Vector2	laser;
		Vector2 laserPos;

        virtual void onUpdate();
		virtual void onDraw();
		virtual void freeResources();

		void rotateLaser();
		void moveLaser();
		void raycast();
};

#endif // LASER_H
