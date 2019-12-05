#pragma once

#include "Entity.h"
#include "Manager.h"
#include "graphics.h"
#include "constants.h"
#include "TextureComponent.h"
#include "TransformComponent.h"
#include <string>

namespace Entity {

	class HealthBar : ECS::Entity {

		ECS::EntityIdType createHealthBarEntity(ECS::Manager* manager, Graphics* graphics);

	};
}