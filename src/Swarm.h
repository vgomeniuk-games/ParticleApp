/*
 * Swarm.h
 *
 *  Created on: Mar 25, 2017
 *      Author: vgomeniuk
 */

#ifndef SWARM_H_
#define SWARM_H_

#include <memory>
#include <vector>
#include "Particle.h"

namespace particleapp {

typedef std::shared_ptr<std::vector<Particle>> shpVector;

class Swarm {

public:
	const static int SIZE = 5000;

public:
	Swarm() : m_particles(new std::vector<Particle>(SIZE)), last_tick(0) {};
	shpVector const getParticles();
	void update(int execution_time);

private:
	shpVector m_particles;
	int last_tick;

};

} /* namespace particleapp */

#endif /* SWARM_H_ */
