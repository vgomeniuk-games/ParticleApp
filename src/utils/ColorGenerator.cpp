/*
 * ColorGenerator.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: vgomeniuk
 */

#include "ColorGenerator.h"

namespace particleapp {

Uint32 ColorGenerator::fillColor(Uint8 red,Uint8 green, Uint8 blue){
	// Hex-decimal color value
	Uint32 color = 0;

	// Fill color with hex-color using shifting
	color += red;
	color <<= 8;

	color += green;
	color <<= 8;

	color += blue;
	color <<= 8;

	color += 0xFF;  // alpha not used in this demo
	return color;
}

Uint32 ColorGenerator::generate(int executionTime){
	// Change color over time from 0 to 255 (use different multiplier for each RGB channel)
	int red = (1 + sin(executionTime * 0.0001)) * 128;
	int green = (1 + sin(executionTime * 0.0002)) * 128;
	int blue = (1 + sin(executionTime * 0.0003)) * 128;
	return fillColor(red, green, blue);
}

} /* namespace particleapp */
