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

	class EliteGuard : ECS::Entity {};

	ECS::EntityIdType createEliteGuardEntity(ECS::Manager* manager, Graphics* graphics, int x, int y);

}