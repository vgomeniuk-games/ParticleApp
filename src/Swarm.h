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
	const static int NPARTICLES = 5000;
private:
	std::shared_ptr<Particle> const m_Particles;
	int last_tick;
public:
	Swarm();
	void update(int execution_time);
	Particle* const getParticles();
};

} /* namespace particleapp */

#endif /* SWARM_H_ */
