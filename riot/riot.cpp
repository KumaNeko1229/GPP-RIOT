
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
	this->manager = new ECS::Manager();
	this->systemRunner.setManager(this->manager);

	// TODO: Create the systems and register them to the manager

	this->systemRunner.initialize(this->graphics);
}

//=============================================================================
// Update all game items
//=============================================================================
void Riot::update() {
	this->systemRunner.update();
}

//=============================================================================
// Render game items
//=============================================================================
void Riot::render()
{
	graphics->spriteBegin();                // begin drawing sprites

	this->systemRunner.render();

	graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Riot::releaseAll()
{
	this->systemRunner.releaseAll();
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

	this->systemRunner.resetAll();
}