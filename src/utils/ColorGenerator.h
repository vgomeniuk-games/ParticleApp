/*
 * ColorGenerator.h
 *
 *  Created on: Mar 25, 2017
 *      Author: vgomeniuk
 */

#ifndef UTILS_COLORGENERATOR_H_
#define UTILS_COLORGENERATOR_H_

#include <SDL2/SDL.h>

namespace particleapp {

// Generate color using RGB values or current execution time
class ColorGenerator{
public:
	static Uint32 fillColor(Uint8 red,Uint8 green, Uint8 blue);
	static Uint32 generate(int executionTime);
};

} /* namespace particleapp */

#endif /* UTILS_COLORGENERATOR_H_ */
