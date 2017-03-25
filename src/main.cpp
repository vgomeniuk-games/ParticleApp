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
	Swarm swarm;
	while(true){
		// Get tick time
		int execution_time = SDL_GetTicks();

		// Clear previous frame and update particles
		swarm.update(execution_time);

		// Draw particles
		shpVector pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::SIZE; ++i) {
			Particle particle = (*pParticles)[i];
			int x = (particle.m_x + 1) * Screen::WIDTH / 2;
			int y = particle.m_y * Screen::WIDTH / 2 + Screen::HEIGHT / 2;
			Uint32 color = ColorGenerator::generate(execution_time);
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
