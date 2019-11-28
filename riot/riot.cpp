
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

	// TODO: Create the systems and register them to the manager

	// Initialize the systems
	for (ECS::System* systemPtr : manager.getSystems()) {
		systemPtr->initialize();
	}
}

//=============================================================================
// Update all game items
//=============================================================================
void Riot::update() {
	for (ECS::System* systemPtr : manager.getSystems()) {
		systemPtr->update();
	}
}

//=============================================================================
// Render game items
//=============================================================================
void Riot::render()
{
	graphics->spriteBegin();                // begin drawing sprites

	for (ECS::System* systemPtr : manager.getSystems()) {
		systemPtr->render();
	}

	graphics->spriteEnd();                  // end drawing sprites
}

//=============================================================================
// The graphics device was lost.
// Release all reserved video memory so graphics device may be reset.
//=============================================================================
void Riot::releaseAll()
{
	manager.releaseAll();
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

	for (ECS::System* systemPtr : manager.getSystems()) {
		systemPtr->resetAll();
	}
}