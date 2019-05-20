#pragma once

namespace VkRes
{
	class GraphicsPipeline
	{
	public:

		GraphicsPipeline() = default;

		void Destroy(vk::Device _device)
		{ }

		void SetInputAssembler(vk::VertexInputBindingDescription                _binding_desc,
		                       std::vector<vk::VertexInputAttributeDescription> _attribute_desc,
		                       vk::PrimitiveTopology                            _topology,
		                       vk::Bool32                                       _primitive_restart)
		{ }

		void SetViewport(vk::Extent2D _viewport_dimensions, float _min_depth, float _max_depth)
		{ }

		void SetRasterizer(vk::Bool32              _depth_write,
		                   vk::Bool32              _depth_test,
		                   vk::CompareOp           _depth_comp_op,
		                   vk::SampleCountFlagBits _multisampling_count,
		                   vk::Bool32              _sample_shading)
		{ }

		void SetPushConstants(uint32_t _offset, vk::ShaderStageFlagBits _stage)
		{ }

		template <typename PushConstT> void SetPushConstants(uint32_t                _offset,
		                                                     uint32_t                _size,
		                                                     vk::ShaderStageFlagBits _stage)
		{ }

		void SetShaders(std::vector<vk::PipelineShaderStageCreateInfo> _shaders)
		{ }

		void SetPipelineLayout(vk::Device               _device,
		                       vk::DescriptorSetLayout* _descriptor_set_layout,
		                       uint32_t                 _descriptor_set_layout_count,
		                       uint32_t                 _push_constant_count)
		{ }

		bool CreateGraphicPipeline(vk::Device _device, vk::RenderPass _render_pass)
		{ }

		vk::PipelineLayout& PipelineLayout()
		{
			return m_layout;
		}

		vk::Pipeline& Pipeline()
		{
			return m_pipeline;
		}

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
