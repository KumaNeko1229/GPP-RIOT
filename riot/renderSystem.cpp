#include "renderSystem.h"

namespace System {

void RenderSystem::update(float frameTime) {
	// Get all texture components
	std::vector<Component::Texture>* componentsPtr =
		this->manager->getComponents<Component::Texture>();

	for (Component::Texture textureComponent : *componentsPtr) {
		// Ignore non-visible components
		if (!textureComponent.visible) {
			continue;
		}

		long viewableWidth = textureComponent.viewableRect.right - textureComponent.viewableRect.left;
		long viewableHeight = textureComponent.viewableRect.bottom - textureComponent.viewableRect.top;

		/*D3DXVECTOR2 spriteCenter = D3DXVECTOR2(
			(float)(viewableWidth / 2 * spriteData.scale),
			(float)(viewableHeight / 2 * spriteData.scale)
		);*/
	}
	//// get fresh texture incase onReset() was called
	//spriteData.texture = textureManager->getTexture();

	////////////

	//if (spriteData.texture == NULL)      // if no texture
	//	return;

	//// Find center of sprite
	//D3DXVECTOR2 spriteCenter = D3DXVECTOR2((float)(spriteData.width / 2 * spriteData.scale),
	//	(float)(spriteData.height / 2 * spriteData.scale));
	//// Screen position of the sprite
	//D3DXVECTOR2 translate = D3DXVECTOR2((float)spriteData.x, (float)spriteData.y);
	//// Scaling X,Y
	//D3DXVECTOR2 scaling(spriteData.scale, spriteData.scale);

	//if (spriteData.flipHorizontal)  // if flip horizontal
	//{
	//	scaling.x *= -1;            // negative X scale to flip
	//	// Get center of flipped image.
	//	spriteCenter.x -= (float)(spriteData.width * spriteData.scale);
	//	// Flip occurs around left edge, translate right to put
	//	// Flipped image in same location as original.
	//	translate.x += (float)(spriteData.width * spriteData.scale);
	//}
	//if (spriteData.flipVertical)    // if flip vertical
	//{
	//	scaling.y *= -1;            // negative Y scale to flip
	//	// Get center of flipped image
	//	spriteCenter.y -= (float)(spriteData.height * spriteData.scale);
	//	// Flip occurs around top edge, translate down to put
	//	// Flipped image in same location as original.
	//	translate.y += (float)(spriteData.height * spriteData.scale);
	//}

	//// Create a matrix to rotate, scale and position our sprite
	//D3DXMATRIX matrix;
	//D3DXMatrixTransformation2D(
	//	&matrix,                // the matrix
	//	NULL,                   // keep origin at top left when scaling
	//	0.0f,                   // no scaling rotation
	//	&scaling,               // scale amount
	//	&spriteCenter,          // rotation center
	//	(float)(spriteData.angle),  // rotation angle
	//	&translate);            // X,Y location

	//sprite->SetTransform(&matrix);

	//// Draw the sprite
	//sprite->Draw(spriteData.texture, &spriteData.rect, NULL, NULL, color);
}

void RenderSystem::render() {

}

void RenderSystem::releaseAll() {

}

void RenderSystem::resetAll() {

}

}
