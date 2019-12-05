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
#include "Collidable.h"
#include "Player.h"

namespace Entity {

	class Blocker : ECS::Entity {};

	ECS::EntityIdType createBlockerEntity(ECS::Manager* manager, Graphics* graphics, int x, int y);
}