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

	class Bullet : ECS::Entity {};

	ECS::EntityIdType createBulletEntity(ECS::Manager* manager, Graphics* graphics, float x, float y, float playerAngle, float bulletAngle);

}