//============================================================================
// Name        : ParticleApp.cpp
// Author      : Viktor Gomeniuk
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>
#include "Screen.h"

using namespace particleapp;


int main(int argc, char** argv) {
	Screen screen;
	if (!screen.init()){
		return 1;
	}
	while(true){  // Main application loop
		// Update particles
		// Draw particles
		// Check for messages/events

		// Change color over time from 0 to 255 (use different multiplier for each RGB channel)
		int deltaTime = SDL_GetTicks();
		int red = (1 + sin(deltaTime * 0.0001)) * 128;
		int green = (1 + sin(deltaTime * 0.0002)) * 128;
		int blue = (1 + sin(deltaTime * 0.0003)) * 128;

		for(int y = 0; y < Screen::SCREEN_HEIGHT; ++y){
			for (int x = 0; x < Screen::SCREEN_WIDTH; ++x){
				screen.setPixel(x, y, red, green, blue);
			}
		}

		screen.update();

		// Process pending events
		if (!screen.processEvents()){
			break;
		}

	}
	// Clean up
	screen.close();
	return 0;
}
