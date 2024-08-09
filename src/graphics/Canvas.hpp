#pragma once

#include <SDL.h>
#include <memory>

class Canvas {
	private:
		SDL_Window * window = nullptr;
		SDL_Renderer * renderer = nullptr;
		SDL_Surface * windowSurface;

		int x = 0;
		int y = 0;
		float scale = 1;
		const int ASPECT_RATIO[2] = {16, 9};
	public:
		int width = 1152;
		int height = 648;
		SDL_Rect canvasSpace;
	public:
		~Canvas();
		Canvas();
		void setScale();
		void updateCanvasSpace();
		void render();

		inline SDL_Window * getWindow() const {
			return window;
		}
		inline SDL_Renderer * getRenderer() const {
			return renderer;
		}	
};

extern std::unique_ptr<Canvas> g_canvas;
