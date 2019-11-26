#pragma once

#include <utility>
#include <vector>
#include <unordered_map>
#include <typeindex>

#include "typeUtil.h"
#include "entity.h"

namespace ECS {

class Manager {
	private:
		// Entity -> vector<Entity>
		std::unordered_map<Types::TypeId, std::vector<Entity>> entities;
		// Component -> vector<T>
		std::unordered_map<Types::TypeId, void*> components;
		// EntityId -> ComponentType -> vector index
		std::unordered_map<EntityIdType, std::unordered_map<Types::TypeId, int>> entityComponents;
		EntityIdType lastCreatedEntityId = NULL;

	public:
		template<typename EntityType> EntityIdType createEntity();

		template<typename ComponentType> std::vector<ComponentType> getComponents();
		template<typename ComponentType> ComponentType getEntityComponent(EntityIdType id);

		template<typename ComponentType> void addComponent(EntityIdType id, ComponentType component);

		void removeEntity(EntityIdType id);
};

}
