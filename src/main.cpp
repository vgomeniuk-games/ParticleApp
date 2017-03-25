//============================================================================
// Name        : ParticleApp.cpp
// Author      : Viktor Gomeniuk
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <memory>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <SDL2/SDL.h>
#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"


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
		int execution_time = SDL_GetTicks();

		// Clear previous frame and update particles
		swarm.update(execution_time);

		// Change color over time from 0 to 255 (use different multiplier for each RGB channel)
		int red = (1 + sin(execution_time * 0.0001)) * 128;
		int green = (1 + sin(execution_time * 0.0002)) * 128;
		int blue = (1 + sin(execution_time * 0.0003)) * 128;

//		// Draw particles
		const Particle * const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; ++i) {
			Particle particle = pParticles[i];
			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = particle.m_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}
		screen.boxBlur();
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
