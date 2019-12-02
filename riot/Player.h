#pragma once

#include "entity.h"
#include "manager.h"
#include "texture.h"
#include "transform.h"
#include "graphics.h"
#include "constants.h"
#include "attack.h"
#include "physics.h"
#include "position.h"

namespace Entity {

class Player : ECS::Entity {};

ECS::EntityIdType createPlayerEntity(ECS::Manager* manager, Graphics* graphics);

}
