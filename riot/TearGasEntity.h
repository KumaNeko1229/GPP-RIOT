#pragma once

#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include "PhysicsComponent.h"
#include "PositionComponent.h"
#include "LifeComponent.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "AnimatableComponent.h"
#include "CollidableComponent.h"
#include "PlayerEntity.h"

namespace Entity {

	class TearGas : ECS::Entity {};

	ECS::EntityIdType createTearGasEntity(ECS::Manager* manager, Graphics* graphics);

}