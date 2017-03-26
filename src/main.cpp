//============================================================================
// Name        : ParticleApp.cpp
// Author      : Viktor Gomeniuk
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <memory>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"
#include "utils/Utils.h"
#include "utils/ColorGenerator.h"


using namespace particleapp;


int main(int argc, char** argv) {
	// Initialize random generator (used in Particles)
	std::srand(time(nullptr));

	Screen screen;
	if (!screen.init()){
		return 1;
	}
	Swarm swarm;  // Particles container
	Uint32 color;  // Color of particles
	int tickTime;  // Time since 1st tick
	while(true){
		tickTime = SDL_GetTicks();
		swarm.update(tickTime);  // Clear previous frame and update particles

		// Generate color and draw particles
		color = ColorGenerator::generate(tickTime);
		for (auto const & particle : (*swarm.getParticles())) {
			// Get particle world position
			int x, y;
			std::tie(x, y) = particle.getWorldPosition(Screen::WIDTH, Screen::HEIGHT);
			screen.setPixel(x, y, color);
		}
		screen.boxBlur();
		screen.update();

		// Process pending events
		if (!processEvents()){
			break;
		}

	}

	// Clean up
	screen.close();
	return 0;
}
