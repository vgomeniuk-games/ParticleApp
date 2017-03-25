/*
 * Utils.h
 *
 *  Created on: Mar 25, 2017
 *      Author: vgomeniuk
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <iostream>
#include <SDL2/SDL.h>

namespace particleapp {
	// Handle SDL events
	bool processEvents() {
		SDL_Event event;  // Event handler
		while(SDL_PollEvent(&event)){
			if (event.type == SDL_QUIT){
				std::cout << "Close window event." << std::endl;
				return false;
			}
		}
		return true;
	};
}


#endif /* UTILS_H_ */
