
#ifndef _RIOT_H             // prevent multiple definitions if this
#define _RIOT_H            // ..file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "renderSystem.h"
#include "manager.h"
#include "systemRunner.h"
#include "typeUtil.h"

//=============================================================================
// Create game class
//=============================================================================
class Riot : public Game {
private:
	ECS::Manager* manager = NULL;
	ECS::SystemRunner systemRunner;

public:
	// Constructor
	Riot();

	// Destructor
	virtual ~Riot();

	// Initialize the game
	void initialize(HWND hwnd);
	void update();      // must override pure virtual from Game
	void render();
	void releaseAll();
	void resetAll();
};

#endif
