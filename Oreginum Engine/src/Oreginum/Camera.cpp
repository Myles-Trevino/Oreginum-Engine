#define GLM_FORECE_DEPTH_ZERO_TO_ONE
#define GLM_FORCE_RADIANS
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtx/quaternion.hpp>
#include "Core.hpp"
#include "Window.hpp"
#include "Keyboard.hpp"
#include "Mouse.hpp"
#include "Camera.hpp"

namespace
{
	float yaw{};
	float pitch{};
	const float pitch_limit{glm::radians(89.999f)};
	const glm::fvec3 world_up{0, -1, 0};
	const glm::fvec3 world_right{1, 0, 0};
	const glm::fvec3 world_forward{0, 0, 1};
	glm::fvec3 position;
	glm::fvec3 direction{0, 0, 1};
	glm::fvec3 forward{glm::normalize(direction*glm::fvec3{1, 0, 1})};
	glm::fvec3 right{glm::normalize(glm::cross(direction, world_up))};
	glm::fmat4 view;
	glm::fmat4 projection;

	constexpr float SENSITIVITY{.003f};
	const float FOV{glm::radians(90.f)};
	constexpr float NEAR_CLIP{.1f};
	constexpr float FAR_CLIP{100};
	constexpr float WALK_SPEED{5.f};
	constexpr float RUN_SPEED{10.f};

	bool frozen;
}

void Oreginum::Camera::update()
{
	if(!Window::is_visible()) return;

	if(Mouse::is_locked() && !::frozen)
	{
		glm::fvec2 cursor_delta{-glm::fvec2{Mouse::get_delta()}*SENSITIVITY};
		if(glm::length(cursor_delta))
		{
			yaw += cursor_delta.x;
			pitch += cursor_delta.y;
			if(pitch > pitch_limit) pitch = pitch_limit;
			else if(pitch < -pitch_limit) pitch = -pitch_limit;

			direction = glm::rotate(glm::angleAxis(yaw, world_up)*
				glm::angleAxis(pitch, world_right), world_forward);
			right = glm::normalize(glm::cross(direction, world_up));
			forward = glm::normalize(direction*glm::fvec3{1, 0, 1});
		}

		float velocity{(GetAsyncKeyState(VK_LSHIFT) ? RUN_SPEED : WALK_SPEED)*Core::get_delta()};
		if(Keyboard::is_held(Key::W)) position += direction*velocity;
		if(Keyboard::is_held(Key::S)) position -= direction*velocity;
		if(Keyboard::is_held(Key::A)) position -= right*velocity;
		if(Keyboard::is_held(Key::D)) position += right*velocity;
	}

	view = glm::lookAt(position, position+direction, world_up);
	projection = glm::perspective(FOV, Window::get_resolution().x/
		static_cast<float>(Window::get_resolution().y), NEAR_CLIP, FAR_CLIP);
	projection[1][1] *= -1;
}

void Oreginum::Camera::set_frozen(bool frozen){ ::frozen = frozen; }

void Oreginum::Camera::set_position(const glm::fvec3& position){ ::position = position; }

bool Oreginum::Camera::get_frozen(){ return frozen;}

const glm::fvec3& Oreginum::Camera::get_position(){ return position; }

const glm::fmat4& Oreginum::Camera::get_view(){ return view; }

const glm::fmat4& Oreginum::Camera::get_projection(){ return projection; }