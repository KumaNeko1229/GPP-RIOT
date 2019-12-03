#pragma once

#include "entity.h"
#include "Manager.h"
#include "graphics.h"
#include "constants.h"
#include "position.h"
#include "texture.h"
#include "transform.h"
#include "Collidable.h"

namespace Entity {

	class Tile : ECS::Entity {};

	ECS::EntityIdType createTileEntity(ECS::Manager* manager, Graphics* graphics, int X, int Y, int TileType);

}