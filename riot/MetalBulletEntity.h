#pragma once

#include "Entity.h"
#include "graphics.h"
#include "manager.h"
#include "PhysicsComponent.h"
#include "TransformComponent.h"
#include "CollidableComponent.h"
#include "TextureComponent.h"
#include "AnimatableComponent.h"
#include "PositionComponent.h"
#include "PlayerEntity.h"

namespace Entity {

	class MetalBullet : ECS::Entity {};

	ECS::EntityIdType createMetalBulletEntity(ECS::Manager* manager, Graphics* graphics, float x, float y, float enemyAngle, float bulletAngle);

}