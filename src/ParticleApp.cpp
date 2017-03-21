//============================================================================
// Name        : ParticleApp.cpp
// Author      : Viktor Gomeniuk
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL2/SDL.h>
using namespace std;

int main(int argc, char** argv) {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	// Initialize application
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL_INIT failed." << endl;
		return 1;
	}
	// Create window
	SDL_Window* window = SDL_CreateWindow(
		"Particle Explosion",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN
	);
	if (window == nullptr){
		cout << SDL_GetError() << endl;
		SDL_Quit();
		return 2;
	}
	bool quit = false;  // Main loop trigger
	SDL_Event event;  // Event handler
	while(!quit){  // Main application loop
		// Update particles
		// Draw particles
		// Check for messages/events

		// Process pending events
		while(SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				cout << "Close window event." << endl;
				quit = true;
			}
		}
	}

	// Clean up
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
