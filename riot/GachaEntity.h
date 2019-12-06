#pragma once
#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include "constants.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "PositionComponent.h"

namespace Entity {

	class Gacha : ECS::Entity {};

	ECS::EntityIdType createGachaEntity(ECS::Manager* manager, Graphics* graphics);

}