#pragma once

#include "entity.h"
#include "manager.h"
#include "texture.h"
#include "transform.h"
#include "Animatable.h"
#include "graphics.h"
#include "constants.h"
#include "attack.h"
#include "physics.h"
#include "position.h"
#include "Damage.h"
#include "Collidable.h"

namespace Entity {

class Player : ECS::Entity {};

ECS::EntityIdType createPlayerEntity(ECS::Manager* manager, Graphics* graphics, int x, int y);

}
