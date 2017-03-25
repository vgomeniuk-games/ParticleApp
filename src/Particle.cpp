/*
 * Particle.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: vgomeniuk
 */

#include "Particle.h"
#include <math.h>
#include <stdlib.h>

namespace particleapp {

Particle::Particle() : m_x(0), m_y(0) {
	this->init();
}
void Particle::init(){
	m_direction = (2 * M_PI * rand()) / RAND_MAX;
	m_speed = (0.04 * rand()) / RAND_MAX;
	m_speed *= m_speed;  // Differentiate particles distribution
}

void Particle::update(int delta_time) {
	m_direction += delta_time * 0.0003;

	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	m_x += xspeed * delta_time;
	m_y += yspeed * delta_time;

	// In case particle goes out local scope => initialize new speed / direction
	if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1){
		this->init();
		return;
	}
	// Randomly initialize new speed / direction with probability ~1:100
	if (rand() < (RAND_MAX / 100)){
		this->init();
	}
}

} /* namespace particleapp */
