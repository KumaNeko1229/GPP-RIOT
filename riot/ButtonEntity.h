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

	class Button : ECS::Entity {};

	ECS::EntityIdType createButtonEntity(ECS::Manager* manager, Graphics* graphics, std::string buttonName, float x, float y, float fontsize);

}