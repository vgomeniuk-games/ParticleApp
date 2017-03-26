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

Particle::Particle() : m_x(0), m_y(0), m_speed(0), m_direction(0) {
	this->init();
}
void Particle::init(){
	m_direction = (2 * M_PI * rand()) / RAND_MAX;  // In local scope [-1:1]
	m_speed = (0.04 * rand()) / RAND_MAX;
	m_speed *= m_speed;  // Differentiate particles distribution
}

void Particle::update(int deltaTime) {
	// Shift direction a bit each frame
	m_direction += deltaTime * 0.0003;

	// Calculate next position using speed and direction and delta time since last frame
	double xspeed = m_speed * cos(m_direction);
	double yspeed = m_speed * sin(m_direction);

	m_x += xspeed * deltaTime;
	m_y += yspeed * deltaTime;

	// In case particle goes out of local scope => initialize new speed / direction
	if (m_x < -1 || m_x > 1 || m_y < -1 || m_y > 1){
		this->init();
		return;
	}
	// Randomly initialize new speed / direction with probability ~1:100
	if (rand() < (RAND_MAX / 100)){
		this->init();
	}
}

std::pair<int, int> Particle::getWorldPosition(int width, int height) const {
	int x = (m_x + 1) * width / 2;
	int y = m_y * width / 2 + height / 2;
	return std::make_pair(x, y);
}

} /* namespace particleapp */
