#pragma once
#define NOMINMAX
#define VK_USE_PLATFORM_WIN32_KHR
#define VULKAN_HPP_NO_EXCEPTIONS
#include <Vulkan/vulkan.hpp>
#include "Device.hpp"
#include "Command Pool.hpp"

namespace Oreginum::Vulkan
{
	class Command_Buffer
	{
	public:
		Command_Buffer(){}
		Command_Buffer(const Device& device, const Command_Pool& command_pool,
			vk::CommandBufferLevel level = vk::CommandBufferLevel::ePrimary);
		Command_Buffer *operator=(Command_Buffer other){ swap(&other); return this; }
		~Command_Buffer();

		void begin(vk::CommandBufferUsageFlagBits flags =
			vk::CommandBufferUsageFlagBits::eSimultaneousUse) const;
		void end() const;
		void submit() const;
		void end_and_submit() const { end(), submit(); }

		const vk::CommandBuffer& get() const { return *command_buffer; }

	private:
		const Device *device;
		const Command_Pool *command_pool;
		std::shared_ptr<vk::CommandBuffer> command_buffer =
			std::make_shared<vk::CommandBuffer>();

		void swap(Command_Buffer *other);
	};
}