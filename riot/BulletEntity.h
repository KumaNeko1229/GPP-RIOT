#pragma once

#include "Entity.h"
#include "Manager.h"
#include "PhysicsComponent.h"
#include "TransformComponent.h"
#include "CollidableComponent.h"
#include "TextureComponent.h"
#include "AnimatableComponent.h"
#include "PositionComponent.h"
#include "DamageComponent.h"

namespace Entity {

	class Bullet : ECS::Entity {};

	ECS::EntityIdType createBulletEntity(ECS::Manager* manager, Graphics* graphics, float x, float y, float playerAngle, float bulletAngle);

}