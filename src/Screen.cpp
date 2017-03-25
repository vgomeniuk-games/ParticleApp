/*
 * Screen.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: vgomeniuk
 */
#include <iostream>
#include "Screen.h"
using namespace std;
namespace particleapp {

Screen::Screen() : m_window(nullptr), m_renderer(nullptr), m_texture(nullptr), m_buffer(nullptr) {
}

bool Screen::init() {
	// Initialize application
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cerr << "SDL_INIT failed: " << SDL_GetError() << endl;
		return false;
	}
	// Create window
	m_window = SDL_CreateWindow(
		"Particle Explosion",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN
	);
	if (m_window == nullptr){
		cout << "Failed to create SDL_Window;" << endl;
		cerr << SDL_GetError() << endl;
		SDL_Quit();
		return false;
	}
	// Create renderer to render information to screen
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
	if (m_renderer == nullptr) {
		cout << "Failed to create SDL_Renderer;" << endl;
		cerr << SDL_GetError() << endl;
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}
	// Create texture to contain information
	m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (m_texture == nullptr) {
		cout << "Failed to create SDL_Texture;" << endl;
		cerr << SDL_GetError() << endl;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
		return false;
	}
	// Create and fill buffer
	auto buffer = unique_ptr<Uint32>(new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT]);
	memset(buffer.get(), 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

	for (int i=0; i< SCREEN_WIDTH*SCREEN_HEIGHT; ++i){
		buffer.get()[i] = 0xFFFF00FF;
	}

	// Update and render texture to screen
	SDL_UpdateTexture(m_texture, nullptr, buffer.get(), SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(m_renderer);
	SDL_RenderCopy(m_renderer, m_texture, nullptr, nullptr);
	SDL_RenderPresent(m_renderer);

	return true;
}
bool Screen::processEvents() {
	SDL_Event event;  // Event handler
	while(SDL_PollEvent(&event)){
		if (event.type == SDL_QUIT){
			cout << "Close window event." << endl;
			return false;
		}
	}
	return true;
}
void Screen::close() {
	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	SDL_Quit();
}

} /* namespace particleapp */
