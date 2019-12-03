#pragma once
#define WIN32_LEAN_AND_MEAN

#include "game.h"
#include "textureManager.h"
#include "renderSystem.h"
#include "PlayerMovementSystem.h"
#include "AnimationSystem.h"
#include "manager.h"
#include "systemRunner.h"
#include "player.h"
#include "MovementSystem.h"
#include "PlayerAttackSystem.h"
#include "MenuSystem.h"
#include "CollisionSystem.h"

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
