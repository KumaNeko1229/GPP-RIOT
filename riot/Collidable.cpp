#include "Collidable.h"

namespace Component {

	float Collidable::getXCenter() {
		return ((float) (this->edges.left + this->edges.right)) / 2.0f;
	}

	float Collidable::getYCenter() {
		return ((float) (this->edges.top + this->edges.bottom)) / 2.0f;
	}

}