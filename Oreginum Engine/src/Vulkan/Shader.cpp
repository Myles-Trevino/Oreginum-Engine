#include <fstream>
#include "../Oreginum/Core.hpp"
#include "Shader.hpp"

Oreginum::Vulkan::Shader::Shader(const Device& device, const std::vector<
	std::pair<std::string, vk::ShaderStageFlagBits>>& shaders) : device(device)
{
	for(const auto& s : shaders)
	{
		modules.push_back(create_shader_module(s.first));

		vk::PipelineShaderStageCreateInfo shader_stage_information;
		shader_stage_information.setStage(s.second);
		shader_stage_information.setModule(modules.back());
		shader_stage_information.setPName("main");
		shader_stage_information.setPSpecializationInfo(nullptr);

		information.push_back(shader_stage_information);
	}
}

Oreginum::Vulkan::Shader::~Shader()
{ for(vk::ShaderModule m : modules) device.get().destroyShaderModule(m); }

vk::ShaderModule Oreginum::Vulkan::Shader::create_shader_module(const std::string& shader)
{
	std::ifstream file{"Resources/Shaders/"+shader+".spv", std::ios::ate | std::ios::binary};
	if(!file.is_open()) Oreginum::Core::error("Could not open shader \""+shader+"\".");
	size_t size{static_cast<size_t>(file.tellg())};
	file.seekg(0);
	std::vector<char> data(size);
	file.read(data.data(), size);
	file.close();

	vk::ShaderModuleCreateInfo shader_module_information;
	shader_module_information.setCodeSize(data.size());
	shader_module_information.setPCode(reinterpret_cast<const uint32_t *>(data.data()));

	vk::ShaderModule shader_module;
	if(device.get().createShaderModule(&shader_module_information,
		nullptr, &shader_module) != vk::Result::eSuccess)
		Oreginum::Core::error("Could not create Vulkan shader module \""+shader+"\".");
	return shader_module;
}