#include "PlayerAttackSystem.h"

namespace System {

	void PlayerAttackSystem::initialize(ECS::Manager* manager, Graphics* graphics, Input* input) {};

	// check for the timer, and create the bullets here
	void PlayerAttackSystem::update(float frameTime)
	{
		std::vector<Component::Attack>* componentPtrs = this->manager->getComponents<Component::Attack>();

		for (Component::Attack attackComponent : *componentPtrs)
		{
			attackComponent.cooldownTime -= frameTime;
			if (attackComponent.cooldownTime >= 0)
			{
				// create the bullet here
				attackComponent.cooldownTime = attackComponent.interval;
			}
		}
	}
}
