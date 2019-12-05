#pragma once

#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include "constants.h"
#include "PositionComponent.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "CollidableComponent.h"

namespace Entity {

	class Tile : ECS::Entity {};

	ECS::EntityIdType createTileEntity(ECS::Manager* manager, Graphics* graphics, int X, int Y);

}