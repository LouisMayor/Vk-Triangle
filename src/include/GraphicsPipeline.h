#pragma once

namespace VkRes
{
	class GraphicsPipeline
	{
	public:

		GraphicsPipeline() = default;

		void Destroy(vk::Device _device)
		{ }

		void SetInputAssembler()
		{ }

		void SetViewport()
		{ }

		void SetRasterizer()
		{ }

		void SetPushConstants()
		{ }

		template <typename PushConstT> void SetPushConstants()
		{ }

		void SetShaders()
		{ }

		void SetPipelineLayout()
		{ }

		bool CreateGraphicPipeline()
		{ }

		vk::PipelineLayout PipelineLayout()
		{ }

		vk::Pipeline Pipeline()
		{ }

	private:
		// Input & Vertex
		vk::PipelineInputAssemblyStateCreateInfo         m_input_assembly_state_create_info;
		vk::PipelineVertexInputStateCreateInfo           m_vertex_input_state_create_info;
		vk::VertexInputBindingDescription                m_vertex_binding_desc;
		std::vector<vk::VertexInputAttributeDescription> m_vertex_attribute_descs;

		// Viewport
		vk::PipelineViewportStateCreateInfo m_viewport_state_create_info;
		vk::Viewport                        m_viewport;
		vk::Rect2D                          m_rect;

		// Rasterizer
		vk::PipelineRasterizationStateCreateInfo m_rasterization_state_create_info;
		vk::PipelineMultisampleStateCreateInfo   m_multisample_state_create_info;
		vk::PipelineDepthStencilStateCreateInfo  m_depth_stencil_state_create_info;
		vk::PipelineColorBlendStateCreateInfo    m_colour_blend_create_info;
		vk::PipelineColorBlendAttachmentState    m_colour_blend_attachement;

		// Shaders
		std::vector<vk::PipelineShaderStageCreateInfo> m_shader_stages;

		// PushConstants
		vk::PushConstantRange m_push_constant;

		// Pipeline
		vk::PipelineLayoutCreateInfo   m_layout_create_info;
		vk::GraphicsPipelineCreateInfo m_graphics_pipeline_create_info;
		vk::PipelineLayout             m_layout;
		vk::Pipeline                   m_pipeline;

		// Stage tracking
		bool has_set_input_assembler = false;
		bool has_set_viewport        = false;
		bool has_set_rasterizer      = false;
		bool has_set_shader_stages   = false;
		bool has_set_pipline_layout  = false;
	};
}
