/*
 * Swarm.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: vgomeniuk
 */

#include "Swarm.h"

namespace particleapp {

shpVector const Swarm::getParticles() {
	return m_particles;
}

void Swarm::update(int execution_time){
	int delta_time = execution_time - last_tick;
	for (int p = 0; p < SIZE; ++p) {
		(*m_particles)[p].update(delta_time);
	}
	last_tick = execution_time;
}

} /* namespace particleapp */
