#pragma once
#include "entity.h"
#include "manager.h"
#include "texture.h"
#include "transform.h"
#include "graphics.h"
#include "constants.h"
#include <string>

namespace Entity {

	class HealthBar : ECS::Entity {

		ECS::EntityIdType createHealthBarEntity(ECS::Manager* manager, Graphics* graphics);

	};
}