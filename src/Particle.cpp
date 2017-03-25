/*
 * Particle.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: vgomeniuk
 */

#include "Particle.h"
#include <stdlib.h>

namespace particleapp {

Particle::Particle() {
	// TODO Auto-generated constructor stub
	m_x = (2.0* rand())/RAND_MAX - 1;  // -1:1
	m_y = (2.0* rand())/RAND_MAX - 1;  // -1:1
	m_xspeed = 0.01 * ((2.0 * rand()) / RAND_MAX - 1);
	m_yspeed = 0.01 * ((2.0 * rand()) / RAND_MAX - 1);
}

void Particle::update(){
	m_x += m_xspeed;
	m_y += m_yspeed;

	if (m_x <= -1 || m_x >= 1){
		m_xspeed = - m_xspeed;
	}
	if (m_y <= -1 || m_y >= 1){
		m_yspeed = - m_yspeed;
	}
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

} /* namespace particleapp */
