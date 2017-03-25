/*
 * Screen.h
 *
 *  Created on: Mar 25, 2017
 *      Author: vgomeniuk
 */
#include <memory>
#include <SDL2/SDL.h>

#ifndef SCREEN_H_
#define SCREEN_H_

namespace particleapp {

class Screen {
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;

public:
	Screen();
	bool init();
	bool processEvents();
	void close();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void boxBlur();
private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	std::unique_ptr<Uint32> m_buffer;
	std::unique_ptr<Uint32> m_blur_buffer;
};

} /* namespace particleapp */

#endif /* SCREEN_H_ */
