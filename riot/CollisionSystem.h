#pragma once

#include <vector>

#include "system.h"
#include "manager.h"

namespace System {

	class CollisionSystem : public ECS::System {
	public:
		void initialize(ECS::Manager* manager);

		void update();

		void collideWithBullet();

		void collideWithEnemies();

		void collideWithWall();
	};

}
