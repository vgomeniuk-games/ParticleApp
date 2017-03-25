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
using namespace std;

int main(int argc, char** argv) {
	particleapp::Screen screen;
	if (!screen.init()){
		return 1;
	}
	while(true){  // Main application loop
		// Update particles
		// Draw particles
		// Check for messages/events

		// Process pending events
		if (!screen.processEvents()){
			break;
		}

	}
	// Clean up
	screen.close();
	return 0;
}
