#pragma once

#include "entity.h"
#include "graphics.h"
#include "manager.h"
#include "physics.h"
#include "transform.h"
#include "Collidable.h"
#include "texture.h"
#include "Animatable.h"
#include "position.h"

namespace Entity {

	class RubberBullet : ECS::Entity {};

	ECS::EntityIdType createRubberBulletEntity(ECS::Manager* manager, Graphics* graphics, float x, float y, float enemyAngle, float bulletAngle);
}