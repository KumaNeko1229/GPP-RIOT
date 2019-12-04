#pragma once

#include "entity.h"
#include "Manager.h"
#include "graphics.h"
#include "Physics.h"
#include "Position.h"
#include "Life.h"
#include "Texture.h"
#include "Transform.h"
#include "Animatable.h"
#include "Collidable.h"
#include "Player.h"

namespace Entity {

	class TearGas : ECS::Entity {};

	ECS::EntityIdType createTearGasEntity(ECS::Manager* manager, Graphics* graphics);

}