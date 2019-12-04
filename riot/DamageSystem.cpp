#include "DamageSystem.h"

namespace System {

	void DamageSystem::update() {
		// after checking if collision is true, handle the damage
		std::vector<Component::Damage>* componentPtrs = this->manager->getComponents<Component::Damage>();

		for (Component::Damage& damageComponent : *componentPtrs)
		{
			if (damageComponent.health <= 0)
			{
				// Kill each of the enemy entities
				if (manager->getEntity(damageComponent.entityId)->isSameType<Entity::Blocker>())
				{
					manager->removeEntity<Entity::Blocker>(damageComponent.entityId);
				}

				if (manager->getEntity(damageComponent.entityId)->isSameType<Entity::EliteGuard>())
				{
					manager->removeEntity<Entity::EliteGuard>(damageComponent.entityId);
				}

				if (manager->getEntity(damageComponent.entityId)->isSameType<Entity::EliteSoldier>())
				{
					manager->removeEntity<Entity::EliteSoldier>(damageComponent.entityId);
				}
			}
			damageComponent.damage = 0;
		}
	}

}