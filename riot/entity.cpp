#include "entity.h"

namespace ECS {

Entity::Entity() {
	this->id = NULL;
}

// entityTypeId is passed as an argument so that it is easier to manage
// entities in container types
Entity::Entity(EntityIdType id, Types::TypeId entityTypeId) {
	this->id = id;
	this->entityTypeId = entityTypeId;
}

Entity::~Entity() {}

// template is used here over passing TypeId as a variable so that toTypeId
// does not have to be used
template<typename T> bool Entity::isSameType() {
	return Types::isSameType(Types::toTypeId<T>(), this->entityTypeId);
}

}