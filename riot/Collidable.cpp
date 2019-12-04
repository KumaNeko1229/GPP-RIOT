#include "Collidable.h"

namespace Component {

	D3DXVECTOR2 Collidable::getCenter() {
		D3DXVECTOR2 centerVector {0, 0};
		for (D3DXVECTOR2 cornerVector : this->corners)
		{
			centerVector += cornerVector;
		}

		centerVector /= 4.0f;

		return centerVector;
	}

}