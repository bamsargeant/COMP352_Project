#ifndef STATEGAME_H
#define STATEGAME_H

#include "general.h"

#include "system/states/IState.h"
#include "system/AssetManager.h"
#include "system/GameData.h"
#include "system/Settings.h"
#include "system/InputHandler.h"

#include "physics/PhysicsFactory.h"
#include "physics/debug/VisualDebugger.h"
#include "physics/ContactListener.h"

//#include "entities/Laser.h"
//#include "entities/Player.h"
#include "objects/Object.h"
#include "objects/Wall.h"
#include "objects/ObjectManager.h"

#include "video/Camera.h"
//#include "video/AnimatedImage.h"
#include "video/sfFontRenderer.h"


/////////////////////////////////////////////////////////
//#include "animation/AnimationManager.h"
//#include "animation/AnimationInstruction.h"
//#include "animation/Animation.h"

class StateGame : public IState
{
    public:
        StateGame();
        virtual ~StateGame();

    public: // member variables
        //gzClock clock;

    public:
        virtual void load();
        virtual bool initialise();
        virtual void handleEvents();
        virtual void update();
        virtual void draw();
        virtual void freeResources();
        virtual void start();

        void loadLevel();

    public:

		ObjectManager		manager;
		AssetManager	    assets;
		InputHandler		input;
		Camera	            camera;

        sfFontRenderer*     font;
		// Box2D physics
		b2World*			world = nullptr;
		VisualDebugger*		debugDraw = nullptr;
		ContactListener		collisions;
		PhysicsFactory		factory;
		bool                drawPhysicsDebug = true;
};

#endif // STATEGAME_H
