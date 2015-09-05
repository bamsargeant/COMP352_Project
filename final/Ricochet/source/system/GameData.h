#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "general.h"
#include "video/Camera.h"

//class Camera;
class Settings;
class AssetManager;
class Object;
class PhysicsFactory;

class GameData
{
    public:
		GameData();
		virtual ~GameData(){}

    public: // variables
        bool			running = true;
		RunState		gamestate = STATE_MENU;

		AssetManager*	    assets = nullptr;
		sf::RenderWindow*   window = nullptr;
		Settings*		    settings = nullptr;
		Camera*			    camera = nullptr;
		b2World*		    world = nullptr;
		PhysicsFactory*     factory = nullptr;

		float			zoom = 1.0;
		double			m_timeDelta = 0;
		Vector2         mouse;
		Vector2         mouse_raw;

		sf::View*       view = nullptr;
		int             level = 1;
		bool            reload = false;
		bool            delay_reload = false;
		bool            draw_debug = false;
		bool            draw_grid = false;

		//Object* player = nullptr;

    public:

		void updateKeys();
		vector<KeyboardKey>	keys;
		Vector2 toPixels(float x, float y);
		Vector2 toPixels(Vector2 p);
		Vector2 toPixels(b2Vec2 p);

		Vector2 toScreenPixels(float x, float y);
		Vector2 toScreenPixels(Vector2 p);
		Vector2 toScreenPixels(b2Vec2 p);
};


extern GameData gdata;
#endif // GAMEDATA_H
