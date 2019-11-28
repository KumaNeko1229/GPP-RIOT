#pragma once

#include "manager.h"

namespace ECS {

template<typename EntityType> EntityIdType Manager::createEntity() {
	// Create the entity
	Types::TypeId entityType = Types::toTypeId<EntityType>();
	EntityIdType newEntityId = Entity::createEntityId(this->lastCreatedEntityId);
	Entity entity = new Entity(newEntityId, entityType);

	// Add the entity to the entities map
	std::pair<EntityIdType, Entity*> entityRecord (newEntityId, &entity);
	this->entities.insert(entityRecord);

	// Add the entity to the entityFamilies map
	if (this->entityFamilies.find(entityType) == this->entityFamilies.end())
	{
		// Add an empty set with the entityType if it does not exist
		std::unordered_set<EntityIdType> emptySet = new std::unordered_set<EntityIdType>();
		std::pair<Types::TypeId, std::unordered_set<EntityIdType>*> emptyRecord
			(entityType, &emptySet);
		this->entityFamilies.insert(emptyRecord);
	}
	this->entityFamilies.at(entityType)->insert(newEntityId);

	return newEntityId;
}

template<typename ComponentType> std::vector<ComponentType>* Manager::getComponents() {
	// Ensure that the ComponentType is a Component
	static_assert(
		std::is_base_of<Component, ComponentType>::value,
		"Attempting to getComponents of non-Component type"
	);

	Types::TypeId componentTypeId = Types::toTypeId<ComponentType>();

	if (this->components.find(componentTypeId) == this->components.end())
	{
		// Add an empty vector with the componentType if it does not exist
		std::vector<ComponentType> componentVector = new std::vector<ComponentType>();
		std::pair<Types::TypeId, std::vector<ComponentType>*> emptyRecord
			(componentTypeId, &componentVector);
		this->components.insert(emptyRecord);
	}

	std::vector<ComponentType>* componentVectorPtr = this->components.at(componentTypeId);
	return componentVectorPtr;
}

template<typename ComponentType> ComponentType Manager::getEntityComponent(EntityIdType id) {
	// Ensure that the ComponentType is a Component
	static_assert(
		std::is_base_of<Component, ComponentType>::value,
		"Attempting to getComponents of non-Component type"
	);

	Types::TypeId componentTypeId = Types::toTypeId(ComponentType);
	int componentIndex = this->entityComponents.at(id).at(componentTypeId);
	std::vector<ComponentType>* componentVectorPtr = this->components.at(componentTypeId);
	return componentVectorPtr->at(componentIndex);
}

template<typename ComponentType> void Manager::addComponent(EntityIdType id, ComponentType component) {
	// Ensure that the ComponentType is a Component
	static_assert(
		std::is_base_of<Component, ComponentType>::value,
		"Attempting to getComponents of non-Component type"
	);

	Types::TypeId componentTypeId = Types::toTypeId<ComponentType>();

	if (this->components.find(componentTypeId) == this->components.end())
	{
		// Add an empty vector with the componentType if it does not exist
		std::vector<ComponentType> componentVector = new std::vector<ComponentType> { component };
		std::pair<Types::TypeId, std::vector<ComponentType>*> emptyRecord
			(componentTypeId, &componentVector);
		this->components.insert(emptyRecord);
	}
	else
	{
		this->components.at(componentTypeId)->push_back(component);
	}
}

template<typename EntityType> void Manager::removeEntity(EntityIdType id) {
	Types::TypeId entityTypeId = Types::toTypeId(EntityType);

	// Remove the entity's components
	std::unordered_map componentMap = this->entityComponents.at(id);
	for (std::pair<Types::TypeId, int> componentPair : componentMap)
	{
		Types::TypeId componentType = componentPair.first;

		int componentIndex = this->entityComponents.at(id).at(componentType);
		std::vector<componentType>* componentVectorPtr = this->components.at(componentType);
		componentVectorPtr->erase(componentIndex);
	}

	// Remove the entity from the entityComponents map
	this->entityComponents.erase(id);

	// Remove the entity from the entityFamilies map
	this->entityFamilies.at(entityTypeId)->erase(id);

	// Remove the entity from the list of entities
	SAFE_DELETE(this->entities.at(entityTypeId));
	this->entities.erase(entityTypeId);
}

}
