//============================================================================
// Name        : ParticleApp.cpp
// Author      : Viktor Gomeniuk
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
using namespace std;

int main(int argc, char** argv) {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 600;

	// Initialize application
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "SDL_INIT failed." << endl;
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
		cerr << SDL_GetError() << endl;
		SDL_Quit();
		return 2;
	}
	// Create renderer to render information to screen
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr) {
		cout << "Failed to create SDL_Renderer;" << endl;
		cerr << SDL_GetError() << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}
	// Create texture to contain information
	SDL_Texture* texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (texture == nullptr) {
		cout << "Failed to create SDL_Texture;" << endl;
		cerr << SDL_GetError() << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}
	// Create and fill buffer with white pixels
	auto buffer = unique_ptr<Uint32>(new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]);
	memset(buffer.get(), 0xFF, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	// Update and render texture to screen
	SDL_UpdateTexture(texture, nullptr, buffer.get(), SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, nullptr, nullptr);
	SDL_RenderPresent(renderer);

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
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
