#include "telemetry.h"

#include "SDL3/SDL.h"

#include <cmath>

using namespace Arietis::Systems;

Telemetry::Telemetry() {
	m_frame_times = std::vector<Uint64>(128);
	m_frame_time_index = 0;

	m_previous_frame_time = SDL_GetTicksNS();
	m_frame_rate = 0;
	m_fps_cap = 240;
	m_delay = 0;
	m_logging_fps = true;
	m_fixed_fps = true;
}

void Telemetry::telemetry_tick() {
	if (m_frame_time_index == m_frame_times.size()) {
		double average_frame_time = 0;
		for (Uint64 frame_time : m_frame_times) {
			average_frame_time += static_cast<double>(frame_time);
		}
		average_frame_time /= m_frame_times.size();
		m_frame_rate = static_cast<int>(std::round(1000000000.0f / average_frame_time));
		m_frame_time_index = 0;
		if (m_logging_fps) {
			SDL_Log("%d FPS", m_frame_rate);
		}
	}
	Uint64 current_frame_time = SDL_GetTicksNS();
	Uint64 frame_time_diff = current_frame_time - m_previous_frame_time;
	m_previous_frame_time = current_frame_time;
	m_frame_times[m_frame_time_index++] = frame_time_diff;

	if (m_fixed_fps and m_frame_rate != 0) {
		Uint64 fps_cap_time = static_cast<Uint64>(std::round(1000000000.0f / m_fps_cap));
		if (frame_time_diff != fps_cap_time) {
			m_delay += static_cast<int>(fps_cap_time - frame_time_diff);
		}
		if (m_delay < 0) {
			m_delay = 0;
		}
		SDL_DelayNS(m_delay);
	}
}

void Telemetry::set_logging_fps(bool logging_fps) {
	m_logging_fps = logging_fps;
}