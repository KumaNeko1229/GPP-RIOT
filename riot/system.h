#pragma once

namespace ECS {

class System {
	public:
		System() {};
		~System() {};

		virtual void initialize() = 0;

		virtual void update() = 0;

		virtual void render() = 0;

		virtual void releaseAll() = 0;

		virtual void resetAll() = 0;
};

}
