/*
 * Swarm.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: vgomeniuk
 */

#include "Swarm.h"

namespace particleapp {

Swarm::Swarm() : m_Particles(new Particle[NPARTICLES]), last_tick(0) {
	// TODO Auto-generated constructor stub

}

Particle* const Swarm::getParticles() {
	return m_Particles.get();
}

void Swarm::update(int execution_time){
	int delta_time = execution_time - last_tick;
	for (int p = 0; p < NPARTICLES; ++p) {
		m_Particles.get()[p].update(delta_time);
	}
	last_tick = execution_time;
}

} /* namespace particleapp */
