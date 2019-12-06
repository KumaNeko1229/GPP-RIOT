#pragma once

#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include "constants.h"
#include "PlayerEntity.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "AttackComponent.h"
#include "PositionComponent.h"
#include "DamageComponent.h"
#include "CollidableComponent.h"
#include "AnimatableComponent.h"

namespace Entity {

	class Blocker : ECS::Entity {};

	ECS::EntityIdType createBlockerEntity(ECS::Manager* manager, Graphics* graphics, int x, int y);
}