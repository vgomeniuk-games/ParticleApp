/*
 * Screen.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: vgomeniuk
 */
#include <iostream>
#include "Screen.h"
#include "utils/ColorGenerator.h"

namespace particleapp {


bool Screen::init() {
	// Initialize application
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "SDL_INIT failed;" << std::endl;
		std::cerr << SDL_GetError() << std::endl;
		return false;
	}
	// Create window
	m_window = SDL_CreateWindow(
		"Particle Explosion",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WIDTH,
		HEIGHT,
		SDL_WINDOW_SHOWN
	);
	if (m_window == nullptr){
		std::cout << "Failed to create SDL_Window;" << std::endl;
		std::cerr << SDL_GetError() << std::endl;
		this->close();
		return false;
	}
	// Create renderer to display information on screen
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == nullptr) {
		std::cout << "Failed to create SDL_Renderer;" << std::endl;
		std::cerr << SDL_GetError() << std::endl;
		this->close();
		return false;
	}
	// Create texture containing information
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, WIDTH, HEIGHT);
	if (m_texture == nullptr) {
		std::cout << "Failed to create SDL_Texture;" << std::endl;
		std::cerr << SDL_GetError() << std::endl;
		this->close();
		return false;
	}
	// Create and clear pixel buffer and blur buffer
	m_pixel_buffer = upVector(new std::vector<Uint32>(WIDTH * HEIGHT));
	m_blur_buffer = upVector(new std::vector<Uint32>(WIDTH * HEIGHT));
	return true;
}

void Screen::update(){
	// Update and render texture to screen
	SDL_UpdateTexture(m_texture, nullptr, &(*m_pixel_buffer).front(), WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, nullptr, nullptr);
	SDL_RenderPresent(m_renderer);
}

void Screen::setPixel(int x, int y, Uint32 color) {
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT){
		return;  // Guard accessing pixels outside buffer in case of wrong calculations
	}

	// Save pixel color to buffer
	(*m_pixel_buffer)[(y * WIDTH) + x] = color;

}

void Screen::boxBlur(){
	// Swap buffers to  store pixels in blur buffer
	upVector temp = std::move(m_pixel_buffer);
	m_pixel_buffer = std::move(m_blur_buffer);
	m_blur_buffer = std::move(temp);

	for (int y = 0; y < HEIGHT; ++y) {
		for (int x = 0; x < WIDTH; ++x){
			// 0 0 0
			// 0 1 0
			// 0 0 0

			// Count RGB values of neighbor cells
			int red_total = 0;
			int green_total = 0;
			int blue_total = 0;

			// Iterate over neighbor pixels
			for (int row = -1; row <= 1; ++row){
				for (int col = -1; col <= 1; ++col){
					int nb_x = x + col;
					int nb_y = y + row;

					// Don't affect pixels outside screen
					if ((nb_x >= 0 && nb_x < WIDTH) && (nb_y >= 0 && nb_y < HEIGHT)){
						// Parse pixel color as RGB value
						Uint32 color = (*m_blur_buffer)[nb_y * WIDTH + nb_x];
						Uint8 red = color >> 24;
						Uint8 green = color >> 16;
						Uint8 blue = color >> 8;

						red_total += red;
						green_total += green;
						blue_total += blue;
					}
				}
			}
			// Calculate average shade for the pixel in matrix of neighbor pixels
			Uint32 color = ColorGenerator::fillColor(red_total / 9, green_total / 9, blue_total / 9);
			setPixel(x, y, color);
		}
	}
}

void Screen::close() {
	// Close every handler opened and quit application
	if (m_texture != nullptr){
		SDL_DestroyTexture(m_texture);
	}
	if (m_renderer != nullptr) {
		SDL_DestroyRenderer(m_renderer);
	}
	if (m_window != nullptr){
		SDL_DestroyWindow(m_window);
	}
	SDL_Quit();
}

} /* namespace particleapp */
