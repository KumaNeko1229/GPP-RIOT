#pragma once

#include <functional>
#include <unordered_set>
#include "CollisionType.h"
#include "Component.h"
#include "Manager.h"

namespace Component {

	struct Collidable : ECS::Component {
		float radius;
		RECT edges;

		Collision::CollisionType collisionType;

		std::unordered_set<ECS::EntityIdType> collidingWith;

		std::function<void(ECS::Manager* manager, ECS::EntityIdType entityId)> onEnter;

		std::function<void(ECS::Manager* manager, ECS::EntityIdType entityId)> onStay;

		std::function<void(ECS::Manager* manager, ECS::EntityIdType entityId)> onExit;

		float getXCenter();
		float getYCenter();
	};

}

