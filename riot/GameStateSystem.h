#pragma once

#include "System.h"
#include "Manager.h"
#include "GameStateEntity.h"
#include "GameStateComponent.h"

namespace System {

	class GameState : public ECS::System {
		private:
			ECS::EntityIdType gameStateId;

		public:
			void initialize(ECS::Manager* manager, Graphics* graphics, Input* input);
			void update(float frameTime);
			void releaseAll();
	};

}
