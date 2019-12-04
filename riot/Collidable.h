#pragma once

#include <functional>
#include <unordered_set>
#include <d3dx9math.h>
#include "CollisionType.h"
#include "Component.h"
#include "Manager.h"

namespace Component {

	struct Collidable : ECS::Component {
		float radius;
		// Top left, top right, bottom left, bottom right
		D3DXVECTOR2 corners[4];

		Collision::CollisionType collisionType;

		std::unordered_set<ECS::EntityIdType> collidingWith;

		std::function<void(ECS::Manager* manager, ECS::EntityIdType entityId)> onEnter;

		std::function<void(ECS::Manager* manager, ECS::EntityIdType entityId)> onStay;

		std::function<void(ECS::Manager* manager, ECS::EntityIdType entityId)> onExit;

		D3DXVECTOR2 getCenter();
	};

}

