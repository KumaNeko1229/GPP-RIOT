#include "manager.h"

namespace ECS {

template<typename EntityType> EntityIdType Manager::createEntity() {
	// Create the entity
	Types::TypeId entityType = Types::toTypeId(EntityType);
	EntityIdType newEntityId = Entity::createEntityId(this->lastCreatedEntityId);
	Entity entity = Entity(newEntityId, entityType);

	// Add the entity to the entities map
	if (this->entities.find(entityType) == this->entities.end()) {
		// Add an empty vector with the entityType if it does not exist
		std::pair<Types::TypeId, std::vector<Entity>> emptyRecord (entityType, std::vector<Entity>());
		this->entities.insert(emptyRecord);
	}

	this->entities.at(entityType).push_back(entity);

	return newEntityId;
}

template<typename EntityType> Entity Manager::getEntity(EntityIdType id) {

}

template<typename ComponentType> ComponentType Manager::getEntityComponent(EntityIdType id) {

}

template<typename ComponentType> void Manager::addComponent(EntityIdType id, ComponentType component) {

}

void Manager::removeEntity(EntityIdType id) {

}

}
