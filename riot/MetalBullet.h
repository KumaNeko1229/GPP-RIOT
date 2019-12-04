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

	class MetalBullet : ECS::Entity {};

	ECS::EntityIdType createMetalBulletEntity(ECS::Manager* manager, Graphics* graphics, int x, int y, float angle);

}