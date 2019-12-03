#pragma once
#include "entity.h"
#include "manager.h"
#include "texture.h"
#include "transform.h"
#include "graphics.h"
#include "constants.h"
#include "Clickable.h"
#include "Text.h"
#include <string>

namespace Entity {

	class Button : ECS::Entity {};

	ECS::EntityIdType createButtonEntity(ECS::Manager* manager, Graphics* graphics);

}