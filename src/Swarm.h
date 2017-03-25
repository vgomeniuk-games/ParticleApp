/*
 * Swarm.h
 *
 *  Created on: Mar 25, 2017
 *      Author: vgomeniuk
 */

#ifndef SWARM_H_
#define SWARM_H_
#include <memory>
#include "Particle.h"

namespace particleapp {

class Swarm {
public:
	const static int NPARTICLES = 1000;
private:
	std::shared_ptr<Particle> const m_Particles;
public:
	Swarm();
	void update();
	Particle* const getParticles();
};

} /* namespace particleapp */

#endif /* SWARM_H_ */
