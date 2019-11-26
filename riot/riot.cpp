
#include "riot.h"

//=============================================================================
// Constructor
//=============================================================================
Riot::Riot() {}

//=============================================================================
// Destructor
//=============================================================================
Riot::~Riot()
{
	releaseAll();           // call onLostDevice() for every graphics item
}

//=============================================================================
// Initializes the game
// Throws GameError on error
//=============================================================================
void Riot::initialize(HWND hwnd)
{
	Game::initialize(hwnd); // throws GameError

	// nebula texture
	if (!mapTexture.initialize(graphics, MAP_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing map texture"));
	// planet texture
	if (!enemyTexture.initialize(graphics, ENEMY_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing enemy texture"));
	// ship texture
	if (!playerTexture.initialize(graphics, PLAYER_IMAGE))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player texture"));

	if (!map.initialize(graphics, 0, 0, 0, &mapTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing map"));
	if (!enemy.initialize(graphics, 0, 0, 0, &enemyTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));
	if (!player.initialize(graphics, 0, 0, 0, &playerTexture))
		throw(GameError(gameErrorNS::FATAL_ERROR, "Error initializing player"));

	return;
}

//=============================================================================
// Update all game items
//=============================================================================
void Riot::update() {}

//=============================================================================
// Artificial Intelligence
//=============================================================================
void Riot::ai() {}

//=============================================================================
// Handle collisions
//=============================================================================
void Riot::collisions() {}

//=============================================================================
// Render game items
//=============================================================================
void Riot::render()
{
	graphics->spriteBegin();                // begin drawing sprites
	graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Riot::releaseAll()
{
	Game::releaseAll();
	return;
}

//=============================================================================
// The grahics device has been reset.
// Recreate all surfaces.
//=============================================================================
void Riot::resetAll()
{
	Game::resetAll();
	return;
}