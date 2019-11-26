#include "typeUtil.h"

namespace ECS {
namespace Types {

template<typename T> TypeId toTypeId() {
	return std::type_index(typeid(T));
}

bool isSameType(TypeId a, TypeId b) {
	// type_index can be compared directly with ==
	return a == b;
}

}
}