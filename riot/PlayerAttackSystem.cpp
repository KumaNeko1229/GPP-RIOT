#include "PlayerAttackSystem.h"

namespace System {

	// check for the timer, and create the bullets here
	void PlayerAttack::update(float frameTime)
	{
		Component::GameState& gameState = this->manager->getComponents<Component::GameState>()->at(0);
		if (gameState.displayState == Component::DisplayState::INGAME)
		{
			// get the position of the player entity
			std::unordered_set<ECS::EntityIdType>* playerPtrs = this->manager->getEntities<Entity::Player>();
			for (ECS::EntityIdType id : *playerPtrs)
			{
				// get the position of the player
				Component::Position& positionComponent = this->manager->getEntityComponent<Component::Position>(id);
				Component::Attack& attackComponent = this->manager->getEntityComponent<Component::Attack>(id);
				Component::Texture& textureComponent = this->manager->getEntityComponent<Component::Texture>(id);
				Component::Transform& transformComponent = this->manager->getEntityComponent<Component::Transform>(id);

				if (input->getMouseLButton())
				{
					attackComponent.cooldownTime -= frameTime;
					if (attackComponent.cooldownTime <= 0)
					{
						float bulletAngle = 0;
						float yDiff = input->getMouseY() - positionComponent.y - (textureComponent.viewableRect.bottom - textureComponent.viewableRect.top) / 2;
						float xDiff = input->getMouseX() - positionComponent.x - (textureComponent.viewableRect.right - textureComponent.viewableRect.left) / 2;

						if (!(xDiff == 0 && yDiff == 0))
						{
							bulletAngle = atan(yDiff / xDiff);
						}

						if (xDiff < 0)
						{
							const int ySign = (yDiff < 0) ? -1 : 1;
							bulletAngle = atan(yDiff / xDiff) + PI * ySign; // reverse the angle to ensure it lies on the correct side of the screen
						}

						// in case the division to get the centre returns a 0.5
						float bulletPositionX = 0.0f;
						float bulletPositionY = 0.0f;
						// get the centre of the player so it renders outside of the player sprite by calculating the (x, y) with the size of the sprite, and corrections made
						// for the spritesheet whitespace, not pixel-perfect for simplicity
						if (transformComponent.angle == UP_ANGLE)
						{
							bulletPositionX = positionComponent.x + (textureComponent.viewableRect.right - textureComponent.viewableRect.left) / 2;
							bulletPositionY = positionComponent.y;
						}
						if (transformComponent.angle == DOWN_ANGLE)
						{
							bulletPositionX = positionComponent.x + (textureComponent.viewableRect.right - textureComponent.viewableRect.left) / 2;
							bulletPositionY = positionComponent.y + (textureComponent.viewableRect.bottom - textureComponent.viewableRect.top);
						}
						if (transformComponent.angle == RIGHT_ANGLE)
						{
							bulletPositionX = positionComponent.x + (textureComponent.viewableRect.right - textureComponent.viewableRect.left);
							bulletPositionY = positionComponent.y;
						}
						if (transformComponent.angle == LEFT_ANGLE)
						{
							bulletPositionX = positionComponent.x;
							bulletPositionY = positionComponent.y;
						}

						// rotate the player to a "decent" position to fire the shot, for simplicity
						if (0 >= bulletAngle && bulletAngle >= -(PI / 2))
						{
							transformComponent.angle = UP_ANGLE;
						}
						if ((-PI / 2) >= bulletAngle && bulletAngle >= -(PI))
						{
							transformComponent.angle = LEFT_ANGLE;
						}
						if ((PI / 2) <= bulletAngle && bulletAngle <= PI)
						{
							transformComponent.angle = DOWN_ANGLE;
						}
						if (0 <= bulletAngle && bulletAngle <= (PI / 2))
						{
							transformComponent.angle = RIGHT_ANGLE;
						}

						// create the bullet here
						Entity::createBulletEntity(this->manager, this->graphics, bulletPositionX, bulletPositionY, transformComponent.angle, bulletAngle);

						// reset the bullet cooldown
						attackComponent.cooldownTime = attackComponent.interval;
					}
				}

				input->setMouseLButton(FALSE);
			}
		}
	}
}
