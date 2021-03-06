#pragma once
#define GLM_FORECE_DEPTH_ZERO_TO_ONE
#define GLM_FORCE_RADIANS
#include <GLM/glm.hpp>

namespace Oreginum
{
	namespace Camera
	{
		void update();

		void set_frozen(bool frozen);
		void set_position(const glm::fvec3& position);

		bool get_frozen();
		const glm::fvec3& get_position();
		const glm::fmat4& get_view();
		const glm::fmat4& get_projection();
	}
}