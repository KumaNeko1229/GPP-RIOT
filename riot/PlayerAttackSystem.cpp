#include "PlayerAttackSystem.h"

namespace System {

	// check for the timer, and create the bullets here
	void PlayerAttackSystem::update(float frameTime)
	{
		std::vector<Component::Attack>* componentPtrs = this->manager->getComponents<Component::Attack>();

		for (Component::Attack attackComponent : *componentPtrs)
		{
			attackComponent.cooldownTime -= frameTime;
			if (attackComponent.cooldownTime >= 0)
			{
				if (input->getMouseLButton())
				{
					// create the bullet here
					Entity::createBulletEntity(this->manager, this->graphics, x, y);
					attackComponent.cooldownTime = attackComponent.interval;
					input->setMouseLButton(FALSE);
				}
			}
		}
	}
}
