#pragma once

#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include "constants.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include "ClickableComponent.h"
#include "TextComponent.h"
#include "PositionComponent.h"
#include <string>

namespace Entity {

	class Pause : ECS::Entity {};

	ECS::EntityIdType createPauseEntity(ECS::Manager* manager, Graphics* graphics, float x, float y);

}