
#ifndef _RIOT_H             // prevent multiple definitions if this 
#define _RIOT_H            // ..file is included in more than one place
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "image.h"

//=============================================================================
// Create game class
//=============================================================================
class Riot : public Game
{
private:
	// variables
	TextureManager mapTexture;
	TextureManager enemyTexture;
	TextureManager playerTexture;
	Image map;
	Image enemy;
	Image player;

public:
	// Constructor
	Riot();

	// Destructor
	virtual ~Riot();

	// Initialize the game
	void initialize(HWND hwnd);
	void update();      // must override pure virtual from Game
	void ai();          // "
	void collisions();  // "
	void render();      // "
	void releaseAll();
	void resetAll();
};

#endif
