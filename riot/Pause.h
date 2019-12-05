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
#include "Position.h"

namespace Entity {

	class Pause : ECS::Entity {};

	ECS::EntityIdType createPauseEntity(ECS::Manager* manager, Graphics* graphics, float x, float y);

}