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
	while(true){  // Main application loop
		// Update particles
		screen.clear();
		swarm.update();

		// Change color over time from 0 to 255 (use different multiplier for each RGB channel)
		int deltaTime = SDL_GetTicks();
		int red = (1 + sin(deltaTime * 0.0001)) * 128;
		int green = (1 + sin(deltaTime * 0.0002)) * 128;
		int blue = (1 + sin(deltaTime * 0.0003)) * 128;

		// Draw particles
		const Particle * const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; ++i) {
			Particle particle = pParticles[i];
			particle.update();
			int x = (particle.m_x + 1) * Screen::SCREEN_WIDTH / 2;
			int y = (particle.m_y + 1) * Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}


//		for(int y = 0; y < Screen::SCREEN_HEIGHT; ++y){
//			for (int x = 0; x < Screen::SCREEN_WIDTH; ++x){
//				screen.setPixel(x, y, red, green, blue);
//			}
//		}

		screen.update();

		// Process pending events
		if (!screen.processEvents()){
			delete [] pParticles;  // TODO
			break;
		}

	}
	// Clean up

	screen.close();
	return 0;
}
