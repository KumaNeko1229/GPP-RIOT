#pragma once
#include "entity.h"
#include "manager.h"
#include "texture.h"
#include "transform.h"
#include "graphics.h"
#include "constants.h"

namespace Entity {

	class Tile : ECS::Entity {};

	ECS::EntityIdType createPlayerEntity(ECS::Manager* manager, Graphics* graphics);

}