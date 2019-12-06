#pragma once

#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include "constants.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "AnimatableComponent.h"
#include "AttackComponent.h"
#include "PhysicsComponent.h"
#include "PositionComponent.h"
#include "DamageComponent.h"
#include "CollidableComponent.h"

namespace Entity {

class Player : ECS::Entity {};

ECS::EntityIdType createPlayerEntity(ECS::Manager* manager, Graphics* graphics, int x, int y);

}
