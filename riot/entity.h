#pragma once

#include <typeinfo>

namespace ECS {

template <typename EntityType>
class Entity {
	private:
		int id;
		const std::type_info& entityType = typeid(EntityType);
	public:
		Entity() {};
		Entity(int id) { this->id = id; };
		~Entity() {};

		int getId() { return id; };
		template <typename T> bool isType() { typeid(T) == entityType; };
};

}
