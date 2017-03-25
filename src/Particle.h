/*
 * Particle.h
 *
 *  Created on: Mar 25, 2017
 *      Author: vgomeniuk
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particleapp {

struct Particle {
	double m_x;  // double used for changing position smoothly
	double m_y;

	double m_speed;
	double m_direction;  // Direction in radians

public:
	Particle();
	void update(int delta_time);
};

} /* namespace particleapp */

#endif /* PARTICLE_H_ */
