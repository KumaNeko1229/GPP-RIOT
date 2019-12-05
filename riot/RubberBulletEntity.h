#pragma once

#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include "PhysicsComponent.h"
#include "TransformComponent.h"
#include "CollidableComponent.h"
#include "TextureComponent.h"
#include "AnimatableComponent.h"
#include "PositionComponent.h"
#include "PlayerEntity.h"

namespace Entity {

	class RubberBullet : ECS::Entity {};

	ECS::EntityIdType createRubberBulletEntity(ECS::Manager* manager, Graphics* graphics, float x, float y, float enemyAngle, float bulletAngle);
}