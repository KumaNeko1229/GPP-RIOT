#pragma once

#include "typeUtil.h"

namespace ECS {

typedef unsigned int EntityIdType;

class Entity {
	private:
		EntityIdType id;
		Types::TypeId entityTypeId = Types::NothingTypeId;
	public:
		static EntityIdType createEntityId(EntityIdType previousId);

		Entity();
		Entity(EntityIdType id, Types::TypeId entityTypeId);
		~Entity();

		EntityIdType getId() { return id; };
		template<typename T> bool isSameType();
};

}
