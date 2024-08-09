#pragma once

class Engine {
	private:
		bool running = false;
		double deltaTime;
	public:
		void start();
		void stop();
	private:
		void run();
		void pollEvents();
		void update(double delta);
		void render();
		void setAspectRatio();
};
