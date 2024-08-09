#pragma once

#include <SDL_main.h>
#include <SDL2/SDL_image.h>
#include <memory>

class Sprite {
	private:
		std::unique_ptr<SDL_Texture> texture;
		SDL_Rect rect;
	public:
		float scale;
		float rotation;
};
