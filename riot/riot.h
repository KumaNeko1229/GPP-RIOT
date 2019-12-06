#pragma once
#define WIN32_LEAN_AND_MEAN
#include <string.h>
#include "game.h"
#include "textureManager.h"
#include "renderSystem.h"
#include "GameStateSystem.h"
#include "PlayerMovementSystem.h"
#include "AnimationSystem.h"
#include "manager.h"
#include "systemRunner.h"
#include "MovementSystem.h"
#include "EnemyMovementSystem.h"
#include "PlayerAttackSystem.h"
#include "MenuSystem.h"
#include "CollisionSystem.h"
#include "HUDSystem.h"
#include "MainMenuSystem.h"
#include "ClickSystem.h"
#include "TextSystem.h"
#include "PauseMenuSystem.h"

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
