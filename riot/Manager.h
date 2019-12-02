#pragma once

#include <utility>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <typeindex>

#include "constants.h"
#include "typeUtil.h"
#include "entity.h"
#include "component.h"

namespace ECS {

class Manager {
	private:
		// EntityId -> Entity*
		std::unordered_map<EntityIdType, Entity*> entities;
		// EntityType -> unordered_set<EntityId>*
		std::unordered_map<Types::TypeId, std::unordered_set<EntityIdType>*> entityFamilies;
		// Component -> vector<Component>*
		std::unordered_map<Types::TypeId, void*> components;
		// EntityId -> ComponentType -> vector index
		std::unordered_map<EntityIdType, std::unordered_map<Types::TypeId, int>*> entityComponents;
		EntityIdType lastCreatedEntityId = NULL;

	public:
		Manager() {};
		~Manager() { this->releaseAll(); };

		// Managing ECS
		template<typename EntityType> EntityIdType createEntity();

		template<typename ComponentType> std::vector<ComponentType>* getComponents();
		template<typename ComponentType> ComponentType getEntityComponent(EntityIdType id);

		template<typename ComponentType> void addComponent(EntityIdType id, ComponentType component);

		template<typename EntityType> void removeEntity(EntityIdType id);
		void removeEntity(EntityIdType id, Types::TypeId entityType);

		// Memory clean up
		void releaseAll();
};

}

#include "Manager.tpp"
