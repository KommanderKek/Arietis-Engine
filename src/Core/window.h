#pragma once

#include "../UI/widget.h"
#include "../UI/menu.h"

#include <SDL3/SDL.h>

#include <vector>
#include <memory>
#include <string>

namespace Arietis::Core {
	class Window {
	private:
		SDL_Window* m_window;
		SDL_Renderer* m_renderer;

		std::string m_title;
		int m_width;
		int m_height;
		SDL_WindowFlags m_flags;

		std::vector<std::shared_ptr<UI::Menu>> m_menus;

	public:
		Window(std::string title, int width, int height, SDL_WindowFlags flags);
		~Window();
		void add_menu(std::shared_ptr<UI::Menu> menu);
		void remove_menu(std::shared_ptr<UI::Menu> menu);
		void render_menus();
		void dispatch_event(SDL_Event* event);
		SDL_Window* get_sdl_window();
	};
}