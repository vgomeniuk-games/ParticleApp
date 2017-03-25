/*
 * Swarm.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: vgomeniuk
 */

#include "Swarm.h"

namespace particleapp {

Swarm::Swarm() : m_Particles(new Particle[NPARTICLES]) {
	// TODO Auto-generated constructor stub

}

Particle* const Swarm::getParticles() {
	return m_Particles.get();
}

void Swarm::update(){
	for (int p = 0; p < NPARTICLES; ++p) {
		m_Particles.get()[p].update();
	}
}

} /* namespace particleapp */
