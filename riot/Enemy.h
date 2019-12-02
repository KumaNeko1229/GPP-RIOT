#pragma once
#include "entity.h"
#include "manager.h"
#include "texture.h"
#include "transform.h"
#include "graphics.h"
#include "constants.h"

namespace Entity {

	class Blocker : ECS::Entity {};
	class Guard : ECS::Entity {};
	class EliteGuard : ECS::Entity {};
	class EliteSoldier : ECS::Entity {};

	ECS::EntityIdType createBlockerEntity(ECS::Manager* manager, Graphics* graphics);
	ECS::EntityIdType createGuardEntity(ECS::Manager* manager, Graphics* graphics);
	ECS::EntityIdType createEliteGuardEntity(ECS::Manager* manager, Graphics* graphics);
	ECS::EntityIdType createEliteSoldierEntity(ECS::Manager* manager, Graphics* graphics);
	
}