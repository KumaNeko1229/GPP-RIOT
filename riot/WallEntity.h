#pragma once

#include "Entity.h"
#include "Manager.h"
#include "CollisionType.h"
#include "graphics.h"
#include "constants.h"
#include "PlayerEntity.h"
#include "BlockerEntity.h"
#include "GuardEntity.h"
#include "EliteGuardEntity.h"
#include "EliteSoldierEntity.h"
#include "PositionComponent.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "CollidableComponent.h"

namespace Entity {

	class Wall : ECS::Entity {};

	ECS::EntityIdType createWallEntity(ECS::Manager* manager, Graphics* graphics, int X, int Y);

}