#pragma once
#include <string>
#include <GLM/glm.hpp>
#include "Model.hpp"

namespace Oreginum
{
	namespace Core
	{
		void initialize(const std::string& title, const glm::ivec2& resolution,
			const Model *model, const void *uniform_buffer_object,
			size_t uniform_buffer_object_size, bool debug = false);
		void destroy();

		void error(const std::string& error);
		bool update();

		int get_refresh_rate();
		glm::ivec2 get_screen_resolution();
		float get_time();
		float get_delta();
	}
}