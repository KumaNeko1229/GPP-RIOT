#pragma once

#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <typeindex>

#include "typeUtil.h"
#include "entity.h"
#include "system.h"

namespace ECS {

class Manager {
	private:
		// EntityId -> Entity
		std::unordered_map<EntityIdType, Entity*> entities;
		// EntityType -> unordered_set<EntityId>
		std::unordered_map<Types::TypeId, std::unordered_set<EntityIdType>*> entityFamilies;
		// Component -> vector<T>
		std::unordered_map<Types::TypeId, void*> components;
		// EntityId -> ComponentType -> vector index
		std::unordered_map<EntityIdType, std::unordered_map<Types::TypeId, int>> entityComponents;
		EntityIdType lastCreatedEntityId = NULL;

		std::vector<System*> systems;
	public:
		template<typename EntityType> EntityIdType createEntity();

		template<typename ComponentType> std::vector<ComponentType> getComponents();
		template<typename ComponentType> ComponentType getEntityComponent(EntityIdType id);
		std::vector<System*> getSystems() { return this->systems; };

		template<typename ComponentType> void addComponent(EntityIdType id, ComponentType component);
		void registerSystem(System* system);

		template<typename EntityType> void removeEntity(EntityIdType id);
};

}
