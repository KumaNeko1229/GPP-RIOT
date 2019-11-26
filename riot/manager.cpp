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

template<typename ComponentType> std::vector<ComponentType> Manager::getComponents() {
	Types::TypeId componentTypeId = Types::toTypeId<ComponentType>();

	if (this->components.find(componentTypeId) == this->components.end()) {
		// Add an empty vector with the componentType if it does not exist
		std::vector<ComponentType> componentVector;
		std::pair<Types::TypeId, std::vector<ComponentType>> emptyRecord
			(componentTypeId, &componentVector);
		this->components.insert(emptyRecord);
	}

	std::vector<ComponentType> componentVector = this->components.at(componentTypeId);
	return componentVector;
}

template<typename ComponentType> ComponentType Manager::getEntityComponent(EntityIdType id) {

}

template<typename ComponentType> void Manager::addComponent(EntityIdType id, ComponentType component) {
	Types::TypeId componentTypeId = Types::toTypeId<ComponentType>();

	if (this->components.find(componentTypeId) == this->components.end()) {
		// Add an empty vector with the componentType if it does not exist
		std::vector<ComponentType> componentVector { component };
		std::pair<Types::TypeId, std::vector<ComponentType>> emptyRecord
			(componentTypeId, &componentVector);
		this->components.insert(emptyRecord);
	} else {
		((std::vector<ComponentType>) this->components.at(componentTypeId)).push_back(component);
	}
}

void Manager::removeEntity(EntityIdType id) {

}

}
