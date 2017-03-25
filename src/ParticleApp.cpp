//============================================================================
// Name        : ParticleApp.cpp
// Author      : Viktor Gomeniuk
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Screen.h"
#include <SDL2/SDL.h>

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

		for(int y = 0; y < Screen::SCREEN_HEIGHT; ++y){
			for (int x = 0; x < Screen::SCREEN_WIDTH; ++x){
				screen.setPixel(x, y, 128, 0, 255);
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
