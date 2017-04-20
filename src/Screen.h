/*
 * Screen.h
 *
 *  Created on: Mar 25, 2017
 *      Author: vgomeniuk
 */
#include <memory>
#include <vector>
#include <SDL.h>

#ifndef SCREEN_H_
#define SCREEN_H_

namespace particleapp {

	typedef std::unique_ptr<std::vector<Uint32>> upVector;

class Screen {
public:
	const static int WIDTH = 800;
	const static int HEIGHT = 600;

public:
	Screen() : m_window(nullptr), m_renderer(nullptr), m_texture(nullptr), m_pixel_buffer(nullptr), m_blur_buffer(nullptr) {};
	bool init();
	void update();
	void setPixel(int x, int y, Uint32 color);
	void boxBlur();
	void close();

private:
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	upVector m_pixel_buffer;
	upVector m_blur_buffer;

};

} /* namespace particleapp */

#endif /* SCREEN_H_ */
