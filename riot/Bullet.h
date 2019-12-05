#pragma once

#include "Entity.h"
#include "Manager.h"
#include "Physics.h"
#include "Transform.h"
#include "Collidable.h"
#include "Texture.h"
#include "Animatable.h"
#include "Position.h"
#include "Damage.h"

namespace Entity {

	class Bullet : ECS::Entity {};

	ECS::EntityIdType createBulletEntity(ECS::Manager* manager, Graphics* graphics, float x, float y, float playerAngle, float bulletAngle);

}