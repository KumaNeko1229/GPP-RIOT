#include "manager.h"

namespace ECS {

void Manager::addComponent(EntityIdType id, Component component) {
	Types::TypeId componentTypeId = Types::toTypeId<Component>();

	if (this->components.find(componentTypeId) == this->components.end())
	{
		// Add an empty vector with the componentType if it does not exist
		std::vector<Component>* componentVector = new std::vector<Component>();
		std::pair<Types::TypeId, std::vector<Component>*> emptyRecord
			(componentTypeId, componentVector);
		this->components.insert(emptyRecord);
	}

	this->components.at(componentTypeId)->push_back(component);

	// Add to the entity components
	// Check if there is a map for the entity id
	if (this->entityComponents.find(id) == this->entityComponents.end())
	{
		// Create an empty map
		std::unordered_map<Types::TypeId, int>* emptyMap = new std::unordered_map<Types::TypeId, int>();
		// Add the map to the entity components map
		std::pair<EntityIdType, std::unordered_map<Types::TypeId, int>*> emptyRecord =
			std::make_pair(id, emptyMap);
		this->entityComponents.insert(emptyRecord);
	}

	int componentIndex = this->components.at(componentTypeId)->size() - 1;
	std::pair<Types::TypeId, int> componentIndexPair = std::make_pair(componentTypeId, componentIndex);
	this->entityComponents.at(id)->insert(componentIndexPair);
}

void Manager::removeEntity(EntityIdType id, Types::TypeId entityTypeId) {
	// Remove the entity's components
	std::unordered_map<Types::TypeId, int>* componentMap = this->entityComponents.at(id);
	for (std::pair<Types::TypeId, int> componentPair : *componentMap)
	{
		Types::TypeId componentType = componentPair.first;

		int componentIndex = this->entityComponents.at(id)->at(componentType);
		std::vector<Component>* componentVectorPtr = this->components.at(componentType);
		componentVectorPtr->erase(componentVectorPtr->begin() + componentIndex);
	}

	// Remove the entity from the entityComponents map
	this->entityComponents.erase(id);

	// Remove the entity from the entityFamilies map
	this->entityFamilies.at(entityTypeId)->erase(id);

	// Remove the entity from the list of entities
	SAFE_DELETE(this->entities.at(id));
	this->entities.erase(id);
}

void Manager::releaseAll() {
	// Delete all entities
	// Create a copy of the entity ids and types
	std::vector<std::pair<EntityIdType, Types::TypeId>> entityCopy;
	entityCopy.reserve(this->entities.size());

	for (auto kv : this->entities)
	{
		EntityIdType entityId = kv.first;
		Types::TypeId entityType = kv.second->getTypeId();
		entityCopy.push_back(std::make_pair(entityId, entityType));
	}

	for (auto pair : entityCopy)
	{
		this->removeEntity(pair.first, pair.second);
	}

	// Clean up entityFamilies
	for (auto kv : this->entityFamilies)
	{
		SAFE_DELETE(kv.second);
	}
	this->entityFamilies.clear();

	// Clean up components
	for (auto kv : this->components)
	{
		SAFE_DELETE(kv.second);
	}
	this->components.clear();

	// Clean up entityComponents
	for (auto kv : this->entityComponents)
	{
		SAFE_DELETE(kv.second);
	}
	this->entityComponents.clear();
}

}
