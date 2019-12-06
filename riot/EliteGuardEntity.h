#pragma once

#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include "constants.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "AttackComponent.h"
#include "PositionComponent.h"
#include "DamageComponent.h"
#include "AnimatableComponent.h"

namespace Entity {

	class EliteGuard : ECS::Entity {};

	ECS::EntityIdType createEliteGuardEntity(ECS::Manager* manager, Graphics* graphics, int x, int y);

}