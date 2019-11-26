#pragma once

#include <typeinfo>

namespace ECS {

typedef unsigned int EntityIdType;

template<typename EntityType>
class Entity {
	private:
		EntityIdType id;
		const std::type_info& entityType = typeid(EntityType);
	public:
		Entity() {};
		Entity(EntityIdType id) { this->id = id; };
		~Entity() {};

		EntityIdType getId() { return id; };
		template<typename T> bool isType() { typeid(T) == entityType; };
};

}
