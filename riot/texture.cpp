#include "texture.h"

namespace Component {

bool Texture::loadTexture(Graphics* graphics, const char* filePath) {
	this->filePath = filePath;

	try
	{
		HRESULT hr = graphics->loadTexture(
			filePath,
			TRANSCOLOR,
			this->totalWidth,
			this->totalHeight,
			this->texture
		);

		if (FAILED(hr))
		{
			SAFE_RELEASE(this->texture);
			return false;
		}

		return true;
	}
	catch (...)
	{
		return false;
	}
}

}