/*
 * Particle.h
 *
 *  Created on: Mar 25, 2017
 *      Author: vgomeniuk
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <utility>

namespace particleapp {

struct Particle {
public:
	double m_x;  // double used for changing position smoothly
	double m_y;

public:
	Particle();
	void update(int deltaTime);
	std::pair<int, int> getWorldPosition(int width, int height) const;
private:
	double m_speed;
	double m_direction;  // Direction in radians

private:
	void init();

};

} /* namespace particleapp */

#endif /* PARTICLE_H_ */
