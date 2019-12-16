#pragma once

#include <forward_list>

#include "PositionComponent.h"
#include "CollidableComponent.h"
#include "GameStateComponent.h"

bool withinRange(float a, float b, float value);
bool inLineOfSight(
	Component::Position playerPos,
	Component::Position enemyPos,
	std::forward_list<Component::Collidable> walls
);
bool checkForRange(float range, Component::Position playerPos, Component::Position enemyPos);
