#pragma once

#include <vector>
#include <string>

#include "Entity.h"
#include "System.h"
#include "Manager.h"
#include "ButtonEntity.h"
#include "TextureComponent.h"
#include "GameStateComponent.h"

namespace System {

	class MainMenu : public ECS::System {
	private:
		Component::Texture textureComponent;
		Component::Text textComponent;

	public:
		void initialize(ECS::Manager* manager, Graphics* graphics, Input* input);
		void render();
		void update(float frametime);
	};

}