#pragma once

#include "entity.h"
#include "manager.h"
#include "texture.h"
#include "transform.h"
#include "graphics.h"
#include "constants.h"
#include "Attack.h"
#include "Position.h"
#include "Damage.h"

namespace Entity {

	class Guard : ECS::Entity {};

	ECS::EntityIdType createGuardEntity(ECS::Manager* manager, Graphics* graphics);
}