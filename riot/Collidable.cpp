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

	std::array<D3DXVECTOR2, 4> Collidable::getSortedCorners() {
		std::array<D3DXVECTOR2, 4> sortedCorners;
		D3DXVECTOR2 centerVector = this->getCenter();
		for (D3DXVECTOR2 vector : this->corners)
		{
			D3DXVECTOR2 differenceVector = vector - centerVector;
			if (differenceVector.x < 0 && differenceVector.y >= 0)
			{
				sortedCorners[0] = vector;
			}
			else if (differenceVector.x >= 0 && differenceVector.y >= 0)
			{
				sortedCorners[1] = vector;
			}
			else if (differenceVector.x < 0 && differenceVector.y < 0)
			{
				sortedCorners[2] = vector;
			}
			else
			{
				sortedCorners[3] = vector;
			}
		}

		return sortedCorners;
	}
}