#pragma once

#include "SDL3/SDL.h"

#include <vector>

namespace Arietis::Systems {
	class Telemetry {
	private:
		std::vector<Uint64> m_frame_times;
		int m_frame_time_index;

		Uint64 m_previous_frame_time;
		int m_fps_cap;
		int m_frame_rate;
		int m_delay;
		bool m_logging_fps;
		bool m_fixed_fps;

	public:
		Telemetry();
		void telemetry_tick();
		void set_logging_fps(bool logging_fps);
	};
}