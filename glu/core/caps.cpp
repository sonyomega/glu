#include "caps.hpp"

bool caps::check(GLint MajorVersionRequire, GLint MinorVersionRequire)
{
	return (VersionData.Major * 100 + VersionData.Minor * 10)
		>= (MajorVersionRequire * 100 + MinorVersionRequire * 10);
}

void caps::initVersion()
{
	profile Profile = VersionData.Profile;
	memset(&VersionData, 0, sizeof(VersionData));
	VersionData.Profile = Profile;

	glGetIntegerv(GL_MINOR_VERSION, &VersionData.Minor);
	glGetIntegerv(GL_MAJOR_VERSION, &VersionData.Major);
	glGetIntegerv(GL_NUM_EXTENSIONS, &VersionData.NumExtensions);

	if(this->VersionData.Profile == CORE || this->VersionData.Profile == COMPATIBILITY)
	{
		for (GLint i = 0; i < VersionData.NumExtensions; ++i)
		{
			const char* Extension = reinterpret_cast<const char*>(glGetStringi(GL_EXTENSIONS, i));
			if(!strcmp("GL_ARB_multitexture", Extension)) {
				VersionData.GL.ARB_multitexture = true;
				continue;
			}
			if(!strcmp("GL_ARB_transpose_matrix", Extension)) {
				VersionData.GL.ARB_transpose_matrix = true;
				continue;
			}
			if(!strcmp("GL_ARB_multisample", Extension)) {
				VersionData.GL.ARB_multisample = true;
				continue;
			}
			if(!strcmp("GL_ARB_texture_env_add", Extension)) {
				VersionData.GL.ARB_texture_env_add = true;
				continue;
			}
			if(!strcmp("GL_ARB_texture_cube_map", Extension)) {
				VersionData.GL.ARB_texture_cube_map = true;
				continue;
			}
			if(!strcmp("GL_ARB_texture_compression", Extension)) {
				VersionData.GL.ARB_texture_compression = true;
				continue;
			}
			if(!strcmp("GL_ARB_texture_border_clamp", Extension)) {
				VersionData.GL.ARB_texture_border_clamp = true;
				continue;
			}
			if(!strcmp("GL_ARB_point_parameters", Extension)) {
				VersionData.GL.ARB_point_parameters = true;
				continue;
			}
			if(!strcmp("GL_ARB_vertex_blend", Extension)) {
				VersionData.GL.ARB_vertex_blend = true;
				continue;
			}
			if(!strcmp("GL_ARB_matrix_palette", Extension)) {
				VersionData.GL.ARB_matrix_palette = true;
				continue;
			}
			if(!strcmp("GL_ARB_texture_env_combine", Extension)) {
				VersionData.GL.ARB_texture_env_combine = true;
				continue;
			}
			if(!strcmp("GL_ARB_texture_env_crossbar", Extension)) {
				VersionData.GL.ARB_texture_env_crossbar = true;
				continue;
			}
			if(!strcmp("GL_ARB_texture_env_dot3", Extension)) {
				VersionData.GL.ARB_texture_env_dot3 = true;
				continue;
			}
			if(!strcmp("GL_ARB_texture_mirrored_repeat", Extension)) { 
				VersionData.GL.ARB_texture_mirrored_repeat = true;
				continue;
			}
			if(!strcmp("GL_ARB_depth_texture", Extension)) {
				VersionData.GL.ARB_depth_texture = true;
				continue;
			}
			if(!strcmp("GL_ARB_shadow", Extension)) {
				VersionData.GL.ARB_shadow = true;
				continue;
			}
			if(!strcmp("GL_ARB_shadow_ambient", Extension)) {
				VersionData.GL.ARB_shadow_ambient = true;
				continue;
			}
			if(!strcmp("GL_ARB_window_pos", Extension)) {
				VersionData.GL.ARB_window_pos = true;
				continue;
			}
			if(!strcmp("GL_ARB_vertex_program", Extension)) {
				VersionData.GL.ARB_vertex_program = true;
				continue;
			}
			if(!strcmp("GL_ARB_fragment_program", Extension)) {
				VersionData.GL.ARB_fragment_program = true;
				continue;
			}
			if(!strcmp("GL_ARB_vertex_buffer_object", Extension)) {
				VersionData.GL.ARB_vertex_buffer_object = true;
				continue;
			}
			if(!strcmp("GL_ARB_occlusion_query", Extension)) {
				VersionData.GL.ARB_occlusion_query = true;
				continue;
			}
			if(!strcmp("GL_ARB_shader_objects", Extension)) {
				VersionData.GL.ARB_shader_objects = true;
				continue;
			}
			if(!strcmp("GL_ARB_vertex_shader", Extension)) {
				VersionData.GL.ARB_vertex_shader = true;
				continue;
			}
			if(!strcmp("GL_ARB_fragment_shader", Extension)) {
				VersionData.GL.ARB_fragment_shader = true;
				continue;
			}
			if(!strcmp("GL_ARB_shading_language_100", Extension)) {
				VersionData.GL.ARB_shading_language_100 = true;
				continue;
			}
			if(!strcmp("GL_ARB_texture_non_power_of_two", Extension)) {
				VersionData.GL.ARB_texture_non_power_of_two = true;
				continue;
			}
			if(!strcmp("GL_ARB_point_sprite", Extension)) {
				VersionData.GL.ARB_point_sprite = true;
				continue;
			}
			if(!strcmp("GL_ARB_fragment_program_shadow", Extension)) {
				VersionData.GL.ARB_fragment_program_shadow = true;
				continue;
			}
			if(!strcmp("GL_ARB_draw_buffers", Extension)) {
				VersionData.GL.ARB_draw_buffers = true;
				continue;
			}
			if(!strcmp("GL_ARB_texture_rectangle", Extension)) {
				VersionData.GL.ARB_texture_rectangle = true;
				continue;
			}
			if(!strcmp("GL_ARB_color_buffer_float", Extension))
				VersionData.GL.ARB_color_buffer_float = true;
			else if(!strcmp("GL_ARB_half_float_pixel", Extension))
				VersionData.GL.ARB_half_float_pixel = true;
			else if(!strcmp("GL_ARB_texture_float", Extension))
				VersionData.GL.ARB_texture_float = true;
			else if(!strcmp("GL_ARB_pixel_buffer_object", Extension))
				VersionData.GL.ARB_pixel_buffer_object = true;
			else if(!strcmp("GL_ARB_depth_buffer_float", Extension))
				VersionData.GL.ARB_depth_buffer_float = true;
			else if(!strcmp("GL_ARB_draw_instanced", Extension))
				VersionData.GL.ARB_draw_instanced = true;
			else if(!strcmp("GL_ARB_framebuffer_object", Extension))
				VersionData.GL.ARB_framebuffer_object = true;
			else if(!strcmp("GL_ARB_framebuffer_sRGB", Extension))
				VersionData.GL.ARB_framebuffer_sRGB = true;
			else if(!strcmp("GL_ARB_geometry_shader4", Extension))
				VersionData.GL.ARB_geometry_shader4 = true;
			else if(!strcmp("GL_ARB_half_float_vertex", Extension))
				VersionData.GL.ARB_half_float_vertex = true;
			else if(!strcmp("GL_ARB_instanced_arrays", Extension))
				VersionData.GL.ARB_instanced_arrays = true;
			else if(!strcmp("GL_ARB_map_buffer_range", Extension))
				VersionData.GL.ARB_map_buffer_range = true;
			else if(!strcmp("GL_ARB_texture_buffer_object", Extension))
				VersionData.GL.ARB_texture_buffer_object = true;
			else if(!strcmp("GL_ARB_texture_compression_rgtc", Extension))
				VersionData.GL.ARB_texture_compression_rgtc = true;
			else if(!strcmp("GL_ARB_texture_rg", Extension))
				VersionData.GL.ARB_texture_rg = true;
			else if(!strcmp("GL_ARB_vertex_array_object", Extension))
				VersionData.GL.ARB_vertex_array_object = true;
			else if(!strcmp("GL_ARB_uniform_buffer_object", Extension))
				VersionData.GL.ARB_uniform_buffer_object = true;
			else if(!strcmp("GL_ARB_compatibility", Extension))
				VersionData.GL.ARB_compatibility = true;
			else if(!strcmp("GL_ARB_copy_buffer", Extension))
				VersionData.GL.ARB_copy_buffer = true;
			else if(!strcmp("GL_ARB_shader_texture_lod", Extension))
				VersionData.GL.ARB_shader_texture_lod = true;
			else if(!strcmp("GL_ARB_depth_clamp", Extension))
				VersionData.GL.ARB_depth_clamp = true;
			else if(!strcmp("GL_ARB_draw_elements_base_vertex", Extension))
				VersionData.GL.ARB_draw_elements_base_vertex = true;
			else if(!strcmp("GL_ARB_fragment_coord_conventions", Extension))
				VersionData.GL.ARB_fragment_coord_conventions = true;
			else if(!strcmp("GL_ARB_provoking_vertex", Extension))
				VersionData.GL.ARB_provoking_vertex = true;
			else if(!strcmp("GL_ARB_seamless_cube_map", Extension))
				VersionData.GL.ARB_seamless_cube_map = true;
			else if(!strcmp("GL_ARB_sync", Extension))
				VersionData.GL.ARB_sync = true;
			else if(!strcmp("GL_ARB_texture_multisample", Extension))
				VersionData.GL.ARB_texture_multisample = true;
			else if(!strcmp("GL_ARB_vertex_array_bgra", Extension))
				VersionData.GL.ARB_vertex_array_bgra = true;
			else if(!strcmp("GL_ARB_draw_buffers_blend", Extension))
				VersionData.GL.ARB_draw_buffers_blend = true;
			else if(!strcmp("GL_ARB_sample_shading", Extension))
				VersionData.GL.ARB_sample_shading = true;
			else if(!strcmp("GL_ARB_texture_cube_map_array", Extension))
				VersionData.GL.ARB_texture_cube_map_array = true;
			else if(!strcmp("GL_ARB_texture_gather", Extension))
				VersionData.GL.ARB_texture_gather = true;
			else if(!strcmp("GL_ARB_texture_query_lod", Extension))
				VersionData.GL.ARB_texture_query_lod = true;
			else if(!strcmp("GL_ARB_shading_language_include", Extension))
				VersionData.GL.ARB_shading_language_include = true;
			else if(!strcmp("GL_ARB_texture_compression_bptc", Extension))
				VersionData.GL.ARB_texture_compression_bptc = true;
			else if(!strcmp("GL_ARB_blend_func_extended", Extension))
				VersionData.GL.ARB_blend_func_extended = true;
			else if(!strcmp("GL_ARB_explicit_attrib_location", Extension))
				VersionData.GL.ARB_explicit_attrib_location = true;
			else if(!strcmp("GL_ARB_occlusion_query2", Extension))
				VersionData.GL.ARB_occlusion_query2 = true;
			else if(!strcmp("GL_ARB_sampler_objects", Extension))
				VersionData.GL.ARB_sampler_objects = true;
			else if(!strcmp("GL_ARB_shader_bit_encoding", Extension))
				VersionData.GL.ARB_shader_bit_encoding = true;
			else if(!strcmp("GL_ARB_texture_rgb10_a2ui", Extension))
				VersionData.GL.ARB_texture_rgb10_a2ui = true;
			else if(!strcmp("GL_ARB_texture_swizzle", Extension))
				VersionData.GL.ARB_texture_swizzle = true;
			else if(!strcmp("GL_ARB_timer_query", Extension))
				VersionData.GL.ARB_timer_query = true;
			else if(!strcmp("GL_ARB_vertex_type_2_10_10_10_rev", Extension))
				VersionData.GL.ARB_vertex_type_2_10_10_10_rev = true;
			else if(!strcmp("GL_ARB_draw_indirect", Extension))
				VersionData.GL.ARB_draw_indirect = true;
			else if(!strcmp("GL_ARB_gpu_shader5", Extension))
				VersionData.GL.ARB_gpu_shader5 = true;
			else if(!strcmp("GL_ARB_gpu_shader_fp64", Extension))
				VersionData.GL.ARB_gpu_shader_fp64 = true;
			else if(!strcmp("GL_ARB_shader_subroutine", Extension))
				VersionData.GL.ARB_shader_subroutine = true;
			else if(!strcmp("GL_ARB_tessellation_shader", Extension))
				VersionData.GL.ARB_tessellation_shader = true;
			else if(!strcmp("GL_ARB_texture_buffer_object_rgb32", Extension))
				VersionData.GL.ARB_texture_buffer_object_rgb32 = true;
			else if(!strcmp("GL_ARB_transform_feedback2", Extension))
				VersionData.GL.ARB_transform_feedback2 = true;
			else if(!strcmp("GL_ARB_transform_feedback3", Extension))
				VersionData.GL.ARB_transform_feedback3 = true;
			else if(!strcmp("GL_ARB_ES2_compatibility", Extension))
				VersionData.GL.ARB_ES2_compatibility = true;
			else if(!strcmp("GL_ARB_get_program_binary", Extension))
				VersionData.GL.ARB_get_program_binary = true;
			else if(!strcmp("GL_ARB_separate_shader_objects", Extension))
				VersionData.GL.ARB_separate_shader_objects = true;
			else if(!strcmp("GL_ARB_shader_precision", Extension))
				VersionData.GL.ARB_shader_precision = true;
			else if(!strcmp("GL_ARB_vertex_attrib_64bit", Extension))
				VersionData.GL.ARB_vertex_attrib_64bit = true;
			else if(!strcmp("GL_ARB_viewport_array", Extension))
				VersionData.GL.ARB_viewport_array = true;
			else if(!strcmp("GL_ARB_cl_event", Extension))
				VersionData.GL.ARB_cl_event = true;
			else if(!strcmp("GL_ARB_debug_output", Extension))
				VersionData.GL.ARB_debug_output = true;
			else if(!strcmp("GL_ARB_robustness", Extension))
				VersionData.GL.ARB_robustness = true;
			else if(!strcmp("GL_ARB_shader_stencil_export", Extension))
				VersionData.GL.ARB_shader_stencil_export = true;
			else if(!strcmp("GL_ARB_base_instance", Extension))
				VersionData.GL.ARB_base_instance = true;
			else if(!strcmp("GL_ARB_shading_language_420pack", Extension))
				VersionData.GL.ARB_shading_language_420pack = true;
			else if(!strcmp("GL_ARB_transform_feedback_instanced", Extension))
				VersionData.GL.ARB_transform_feedback_instanced = true;
			else if(!strcmp("GL_ARB_compressed_texture_pixel_storage", Extension))
				VersionData.GL.ARB_compressed_texture_pixel_storage = true;
			else if(!strcmp("GL_ARB_conservative_depth", Extension))
				VersionData.GL.ARB_conservative_depth = true;
			else if(!strcmp("GL_ARB_internalformat_query", Extension))
				VersionData.GL.ARB_internalformat_query = true;
			else if(!strcmp("GL_ARB_map_buffer_alignment", Extension))
				VersionData.GL.ARB_map_buffer_alignment = true;
			else if(!strcmp("GL_ARB_shader_atomic_counters", Extension))
				VersionData.GL.ARB_shader_atomic_counters = true;
			else if(!strcmp("GL_ARB_shader_image_load_store", Extension))
				VersionData.GL.ARB_shader_image_load_store = true;
			else if(!strcmp("GL_ARB_shading_language_packing", Extension))
				VersionData.GL.ARB_shading_language_packing = true;
			else if(!strcmp("GL_ARB_texture_storage", Extension))
				VersionData.GL.ARB_texture_storage = true;
			else if(!strcmp("GL_KHR_texture_compression_astc_hdr", Extension))
				VersionData.GL.KHR_texture_compression_astc_hdr = true;
			else if(!strcmp("GL_KHR_texture_compression_astc_ldr", Extension))
				VersionData.GL.KHR_texture_compression_astc_ldr = true;
			else if(!strcmp("GL_KHR_debug", Extension))
				VersionData.GL.KHR_debug = true;
			else if(!strcmp("GL_ARB_arrays_of_arrays", Extension))
				VersionData.GL.ARB_arrays_of_arrays = true;
			else if(!strcmp("GL_ARB_clear_buffer_object", Extension))
				VersionData.GL.ARB_clear_buffer_object = true;
			else if(!strcmp("GL_ARB_compute_shader", Extension))
				VersionData.GL.ARB_compute_shader = true;
			else if(!strcmp("GL_ARB_copy_image", Extension))
				VersionData.GL.ARB_copy_image = true;
			else if(!strcmp("GL_ARB_texture_view", Extension))
				VersionData.GL.ARB_texture_view = true;
			else if(!strcmp("GL_ARB_vertex_attrib_binding", Extension))
				VersionData.GL.ARB_vertex_attrib_binding = true;
			else if(!strcmp("GL_ARB_robustness_isolation", Extension))
				VersionData.GL.ARB_robustness_isolation = true;
			else if(!strcmp("GL_ARB_robustness_isolation", Extension))
				VersionData.GL.ARB_robustness_isolation = true;
			else if(!strcmp("GL_ARB_ES3_compatibility", Extension))
				VersionData.GL.ARB_ES3_compatibility = true;
			else if(!strcmp("GL_ARB_explicit_uniform_location", Extension))
				VersionData.GL.ARB_explicit_uniform_location = true;
			else if(!strcmp("GL_ARB_fragment_layer_viewport", Extension))
				VersionData.GL.ARB_fragment_layer_viewport = true;
			else if(!strcmp("GL_ARB_framebuffer_no_attachments", Extension))
				VersionData.GL.ARB_framebuffer_no_attachments = true;
			else if(!strcmp("GL_ARB_internalformat_query2", Extension))
				VersionData.GL.ARB_internalformat_query2 = true;
			else if(!strcmp("GL_ARB_invalidate_subdata", Extension))
				VersionData.GL.ARB_invalidate_subdata = true;
			else if(!strcmp("GL_ARB_multi_draw_indirect", Extension))
				VersionData.GL.ARB_multi_draw_indirect = true;
			else if(!strcmp("GL_ARB_program_interface_query", Extension))
				VersionData.GL.ARB_program_interface_query = true;
			else if(!strcmp("GL_ARB_robust_buffer_access_behavior", Extension))
				VersionData.GL.ARB_robust_buffer_access_behavior = true;
			else if(!strcmp("GL_ARB_shader_image_size", Extension))
				VersionData.GL.ARB_shader_image_size = true;
			else if(!strcmp("GL_ARB_shader_storage_buffer_object", Extension))
				VersionData.GL.ARB_shader_storage_buffer_object = true;
			else if(!strcmp("GL_ARB_stencil_texturing", Extension))
				VersionData.GL.ARB_stencil_texturing = true;
			else if(!strcmp("GL_ARB_texture_buffer_range", Extension))
				VersionData.GL.ARB_texture_buffer_range = true;
			else if(!strcmp("GL_ARB_texture_query_levels", Extension))
				VersionData.GL.ARB_texture_query_levels = true;
			else if(!strcmp("GL_ARB_texture_storage_multisample", Extension))
				VersionData.GL.ARB_texture_storage_multisample = true;
			else if(!strcmp("GL_ARB_buffer_storage", Extension))
				VersionData.GL.ARB_buffer_storage = true;
			else if(!strcmp("GL_ARB_clear_texture", Extension))
				VersionData.GL.ARB_clear_texture = true;
			else if(!strcmp("GL_ARB_enhanced_layouts", Extension))
				VersionData.GL.ARB_enhanced_layouts = true;
			else if(!strcmp("GL_ARB_multi_bind", Extension))
				VersionData.GL.ARB_multi_bind = true;
			else if(!strcmp("GL_ARB_query_buffer_object", Extension))
				VersionData.GL.ARB_query_buffer_object = true;
			else if(!strcmp("GL_ARB_texture_mirror_clamp_to_edge", Extension))
				VersionData.GL.ARB_texture_mirror_clamp_to_edge = true;
			else if(!strcmp("GL_ARB_texture_stencil8", Extension))
				VersionData.GL.ARB_texture_stencil8 = true;
			else if(!strcmp("GL_ARB_vertex_type_10f_11f_11f_rev", Extension))
				VersionData.GL.ARB_vertex_type_10f_11f_11f_rev = true;
			else if(!strcmp("GL_ARB_bindless_texture", Extension))
				VersionData.GL.ARB_bindless_texture = true;
			else if(!strcmp("GL_ARB_compute_variable_group_size", Extension))
				VersionData.GL.ARB_compute_variable_group_size = true;
			else if(!strcmp("GL_ARB_indirect_parameters", Extension))
				VersionData.GL.ARB_indirect_parameters = true;
			else if(!strcmp("GL_ARB_seamless_cubemap_per_texture", Extension))
				VersionData.GL.ARB_seamless_cubemap_per_texture = true;
			else if(!strcmp("GL_ARB_shader_draw_parameters", Extension))
				VersionData.GL.ARB_shader_draw_parameters = true;
			else if(!strcmp("GL_ARB_shader_group_vote", Extension))
				VersionData.GL.ARB_shader_group_vote = true;
			else if(!strcmp("GL_ARB_sparse_texture", Extension))
				VersionData.GL.ARB_sparse_texture = true;
				
			// EXT
			if(!strcmp("GL_EXT_transform_feedback", Extension)) {
				VersionData.GL.EXT_transform_feedback = true;
				continue;
			}
			if(!strcmp("GL_EXT_direct_state_access", Extension)) {
				VersionData.GL.EXT_direct_state_access = true;
				continue;
			}
			if(!strcmp("GL_EXT_texture_filter_anisotropic", Extension)) {
				VersionData.GL.EXT_texture_filter_anisotropic = true;
				continue;
			}
			if(!strcmp("GL_EXT_texture_compression_s3tc", Extension)) {
				VersionData.GL.EXT_texture_compression_s3tc = true;
				continue;
			}
			if(!strcmp("GL_EXT_texture_array", Extension)) {
				VersionData.GL.EXT_texture_array = true;
				continue;
			}
			if(!strcmp("GL_EXT_texture_snorm", Extension)) {
				VersionData.GL.EXT_texture_snorm = true;
				continue;
			}
			if(!strcmp("GL_EXT_texture_sRGB_decode", Extension)) {
				VersionData.GL.EXT_texture_sRGB_decode = true;
				continue;
			}
			if(!strcmp("GL_EXT_framebuffer_multisample_blit_scaled", Extension)) {
				VersionData.GL.EXT_framebuffer_multisample_blit_scaled = true;
				continue;
			}
			if(!strcmp("GL_EXT_shader_integer_mix", Extension)) {
				VersionData.GL.EXT_shader_integer_mix = true;
				continue;
			}

			// NV
			if(!strcmp("GL_NV_explicit_multisample", Extension)) {
				VersionData.GL.NV_explicit_multisample = true;
				continue;
			}
			if(!strcmp("GL_NV_shader_buffer_load", Extension)) {
				VersionData.GL.NV_shader_buffer_load = true;
				continue;
			}
			if(!strcmp("GL_NV_vertex_buffer_unified_memory", Extension)) {
				VersionData.GL.NV_vertex_buffer_unified_memory = true;
				continue;
			}
			if(!strcmp("GL_NV_shader_buffer_load", Extension)) {
				VersionData.GL.NV_shader_buffer_load = true;
				continue;
			}
			if(!strcmp("NV_bindless_multi_draw_indirect", Extension)) {
				VersionData.GL.NV_bindless_multi_draw_indirect = true;
				continue;
			}
			if(!strcmp("NV_blend_equation_advanced", Extension)) {
				VersionData.GL.NV_blend_equation_advanced = true;
				continue;
			}

			// AMD
			if(!strcmp("AMD_depth_clamp_separate", Extension)) {
				VersionData.GL.AMD_depth_clamp_separate = true;
				continue;
			}
			if(!strcmp("AMD_stencil_operation_extended", Extension)) {
				VersionData.GL.AMD_stencil_operation_extended = true;
				continue;
			}
			if(!strcmp("AMD_vertex_shader_viewport_index", Extension)) {
				VersionData.GL.AMD_vertex_shader_viewport_index = true;
				continue;
			}
			if(!strcmp("AMD_vertex_shader_layer", Extension)) {
				VersionData.GL.AMD_vertex_shader_layer = true;
				continue;
			}
			if(!strcmp("AMD_shader_trinary_minmax", Extension)) {
				VersionData.GL.AMD_shader_trinary_minmax = true;
				continue;
			}
			if(!strcmp("AMD_interleaved_elements", Extension)) {
				VersionData.GL.AMD_interleaved_elements = true;
				continue;
			}
			if(!strcmp("AMD_shader_atomic_counter_ops", Extension)) {
				VersionData.GL.AMD_shader_atomic_counter_ops = true;
				continue;
			}
		}
	}
}

void caps::initCompute()
{
	memset(&ComputeData, 0, sizeof(ComputeData));

	if(check(4, 3) || VersionData.GL.ARB_compute_shader)
	{
		glGetIntegerv(GL_MAX_COMPUTE_TEXTURE_IMAGE_UNITS, &ComputeData.MAX_COMPUTE_TEXTURE_IMAGE_UNITS);
		glGetIntegerv(GL_MAX_COMPUTE_UNIFORM_COMPONENTS, &ComputeData.MAX_COMPUTE_UNIFORM_COMPONENTS);
		glGetIntegerv(GL_MAX_COMPUTE_SHARED_MEMORY_SIZE, &ComputeData.MAX_COMPUTE_SHARED_MEMORY_SIZE);
		glGetIntegerv(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS, &ComputeData.MAX_COMPUTE_WORK_GROUP_INVOCATIONS);
		glGetIntegerv(GL_MAX_COMPUTE_WORK_GROUP_COUNT, &ComputeData.MAX_COMPUTE_WORK_GROUP_COUNT);
		glGetIntegerv(GL_MAX_COMPUTE_WORK_GROUP_SIZE, &ComputeData.MAX_COMPUTE_WORK_GROUP_SIZE);
	}

	if(check(4, 3) || (VersionData.GL.ARB_compute_shader && VersionData.GL.ARB_uniform_buffer_object))
	{
		glGetIntegerv(GL_MAX_COMPUTE_UNIFORM_BLOCKS, &ComputeData.MAX_COMPUTE_UNIFORM_BLOCKS);
		glGetIntegerv(GL_MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS, &ComputeData.MAX_COMBINED_COMPUTE_UNIFORM_COMPONENTS);
	}

	if(check(4, 3) || (VersionData.GL.ARB_compute_shader && VersionData.GL.ARB_shader_image_load_store))
		glGetIntegerv(GL_MAX_COMPUTE_IMAGE_UNIFORMS, &ComputeData.MAX_COMPUTE_IMAGE_UNIFORMS);

	if(check(4, 3) || (VersionData.GL.ARB_compute_shader && VersionData.GL.ARB_shader_atomic_counters))
	{
		glGetIntegerv(GL_MAX_COMPUTE_ATOMIC_COUNTERS, &ComputeData.MAX_COMPUTE_ATOMIC_COUNTERS);
		glGetIntegerv(GL_MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS, &ComputeData.MAX_COMPUTE_ATOMIC_COUNTER_BUFFERS);
	}

	if(check(4, 3) || VersionData.GL.ARB_compute_shader && VersionData.GL.ARB_shader_storage_buffer_object)
		glGetIntegerv(GL_MAX_COMPUTE_SHADER_STORAGE_BLOCKS, &ComputeData.MAX_COMPUTE_SHADER_STORAGE_BLOCKS);
}

void caps::initVertex()
{
	memset(&VertexData, 0, sizeof(VertexData));

	if(check(2, 1) || Version.GL.ARB_vertex_shader)
	{
		glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &VertexData.MAX_VERTEX_ATTRIBS);
		glGetIntegerv(GL_MAX_VERTEX_OUTPUT_COMPONENTS, &VertexData.MAX_VERTEX_OUTPUT_COMPONENTS);
		glGetIntegerv(GL_MAX_VERTEX_TEXTURE_IMAGE_UNITS, &VertexData.MAX_VERTEX_TEXTURE_IMAGE_UNITS);
		glGetIntegerv(GL_MAX_VERTEX_UNIFORM_COMPONENTS, &VertexData.MAX_VERTEX_UNIFORM_COMPONENTS);
		glGetIntegerv(GL_MAX_VERTEX_UNIFORM_VECTORS, &VertexData.MAX_VERTEX_UNIFORM_VECTORS);
	}
	if(check(3, 2) || (Version.GL.ARB_vertex_shader && Version.GL.ARB_uniform_buffer_object))
	{
		glGetIntegerv(GL_MAX_VERTEX_UNIFORM_BLOCKS, &VertexData.MAX_VERTEX_UNIFORM_BLOCKS);
		glGetIntegerv(GL_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS, &VertexData.MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS);
	}
	if(check(4, 2) || (Version.GL.ARB_vertex_shader && Version.GL.ARB_shader_atomic_counters))
		glGetIntegerv(GL_MAX_VERTEX_ATOMIC_COUNTERS, &VertexData.MAX_VERTEX_ATOMIC_COUNTERS);
	if(check(4, 3) || (Version.GL.ARB_vertex_shader && Version.GL.ARB_shader_storage_buffer_object))
		glGetIntegerv(GL_MAX_VERTEX_SHADER_STORAGE_BLOCKS, &VertexData.MAX_VERTEX_SHADER_STORAGE_BLOCKS);
}

void caps::initControl()
{
	memset(&ControlData, 0, sizeof(ControlData));

	if(check(4, 0) || VersionData.GL.ARB_tessellation_shader)
	{
		glGetIntegerv(GL_MAX_TESS_CONTROL_INPUT_COMPONENTS, &ControlData.MAX_TESS_CONTROL_INPUT_COMPONENTS);
		glGetIntegerv(GL_MAX_TESS_CONTROL_OUTPUT_COMPONENTS, &ControlData.MAX_TESS_CONTROL_OUTPUT_COMPONENTS);
		glGetIntegerv(GL_MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS, &ControlData.MAX_TESS_CONTROL_TEXTURE_IMAGE_UNITS);
		glGetIntegerv(GL_MAX_TESS_CONTROL_UNIFORM_COMPONENTS, &ControlData.MAX_TESS_CONTROL_UNIFORM_COMPONENTS);
	}
	if(check(4, 0) || (VersionData.GL.ARB_tessellation_shader && VersionData.GL.ARB_uniform_buffer_object))
	{
		glGetIntegerv(GL_MAX_TESS_CONTROL_UNIFORM_BLOCKS, &ControlData.MAX_TESS_CONTROL_UNIFORM_BLOCKS);
		glGetIntegerv(GL_MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS, &ControlData.MAX_COMBINED_TESS_CONTROL_UNIFORM_COMPONENTS);
	}
	if(check(4, 2) || (VersionData.GL.ARB_tessellation_shader && VersionData.GL.ARB_shader_atomic_counters))
		glGetIntegerv(GL_MAX_TESS_CONTROL_ATOMIC_COUNTERS, &ControlData.MAX_TESS_CONTROL_ATOMIC_COUNTERS);
	if(check(4, 3) || (VersionData.GL.ARB_tessellation_shader && VersionData.GL.ARB_shader_storage_buffer_object))
		glGetIntegerv(GL_MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS, &ControlData.MAX_TESS_CONTROL_SHADER_STORAGE_BLOCKS);
}

void caps::initEvaluation()
{
	memset(&EvaluationData, 0, sizeof(EvaluationData));

	if(check(4, 0) || VersionData.GL.ARB_tessellation_shader)
	{
		glGetIntegerv(GL_MAX_TESS_EVALUATION_INPUT_COMPONENTS, &EvaluationData.MAX_TESS_EVALUATION_INPUT_COMPONENTS);
		glGetIntegerv(GL_MAX_TESS_EVALUATION_OUTPUT_COMPONENTS, &EvaluationData.MAX_TESS_EVALUATION_OUTPUT_COMPONENTS);
		glGetIntegerv(GL_MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS, &EvaluationData.MAX_TESS_EVALUATION_TEXTURE_IMAGE_UNITS);
		glGetIntegerv(GL_MAX_TESS_EVALUATION_UNIFORM_COMPONENTS, &EvaluationData.MAX_TESS_EVALUATION_UNIFORM_COMPONENTS);
	}
	if(check(4, 0) || (VersionData.GL.ARB_tessellation_shader && VersionData.GL.ARB_uniform_buffer_object))
	{
		glGetIntegerv(GL_MAX_TESS_EVALUATION_UNIFORM_BLOCKS, &EvaluationData.MAX_TESS_EVALUATION_UNIFORM_BLOCKS);
		glGetIntegerv(GL_MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS, &EvaluationData.MAX_COMBINED_TESS_EVALUATION_UNIFORM_COMPONENTS);
	}
	if(check(4, 2) || (VersionData.GL.ARB_tessellation_shader && VersionData.GL.ARB_shader_atomic_counters))
		glGetIntegerv(GL_MAX_TESS_EVALUATION_ATOMIC_COUNTERS, &EvaluationData.MAX_TESS_EVALUATION_ATOMIC_COUNTERS);
	if(check(4, 3) || (VersionData.GL.ARB_tessellation_shader && VersionData.GL.ARB_shader_storage_buffer_object))
		glGetIntegerv(GL_MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS, &EvaluationData.MAX_TESS_EVALUATION_SHADER_STORAGE_BLOCKS);
}

void caps::initGeometry()
{
	memset(&GeometryData, 0, sizeof(GeometryData));

	if(check(3, 2) || VersionData.GL.ARB_geometry_shader4)
	{
		glGetIntegerv(GL_MAX_GEOMETRY_INPUT_COMPONENTS, &GeometryData.MAX_GEOMETRY_INPUT_COMPONENTS);
		glGetIntegerv(GL_MAX_GEOMETRY_OUTPUT_COMPONENTS, &GeometryData.MAX_GEOMETRY_OUTPUT_COMPONENTS);
		glGetIntegerv(GL_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS, &GeometryData.MAX_GEOMETRY_TEXTURE_IMAGE_UNITS);
		glGetIntegerv(GL_MAX_GEOMETRY_UNIFORM_COMPONENTS, &GeometryData.MAX_GEOMETRY_UNIFORM_COMPONENTS);
	}
	if(check(3, 2) || (VersionData.GL.ARB_geometry_shader4 && VersionData.GL.ARB_uniform_buffer_object))
	{
		glGetIntegerv(GL_MAX_GEOMETRY_UNIFORM_BLOCKS, &GeometryData.MAX_GEOMETRY_UNIFORM_BLOCKS);
		glGetIntegerv(GL_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS, &GeometryData.MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS);
	}
	if(check(4, 0) || (VersionData.GL.ARB_geometry_shader4 && VersionData.GL.ARB_transform_feedback3))
		glGetIntegerv(GL_MAX_VERTEX_STREAMS, &GeometryData.MAX_VERTEX_STREAMS);
	if(check(4, 2) || (VersionData.GL.ARB_geometry_shader4 && VersionData.GL.ARB_shader_atomic_counters))
		glGetIntegerv(GL_MAX_GEOMETRY_ATOMIC_COUNTERS, &GeometryData.MAX_GEOMETRY_ATOMIC_COUNTERS);
	if(check(4, 3) || (VersionData.GL.ARB_geometry_shader4 && VersionData.GL.ARB_shader_storage_buffer_object))
		glGetIntegerv(GL_MAX_GEOMETRY_SHADER_STORAGE_BLOCKS, &GeometryData.MAX_GEOMETRY_SHADER_STORAGE_BLOCKS);
}

void caps::initFragment()
{
	memset(&FragmentData, 0, sizeof(FragmentData));

	if(check(2, 1))
		glGetIntegerv(GL_MAX_DRAW_BUFFERS, &FragmentData.MAX_DRAW_BUFFERS);

	if(check(2, 1) || VersionData.GL.ARB_fragment_shader)
	{
		glGetIntegerv(GL_MAX_FRAGMENT_INPUT_COMPONENTS, &FragmentData.MAX_FRAGMENT_INPUT_COMPONENTS);
		glGetIntegerv(GL_MAX_FRAGMENT_UNIFORM_COMPONENTS, &FragmentData.MAX_FRAGMENT_UNIFORM_COMPONENTS);
		glGetIntegerv(GL_MAX_FRAGMENT_UNIFORM_VECTORS, &FragmentData.MAX_FRAGMENT_UNIFORM_VECTORS);
	}
	if(check(3, 2) || (VersionData.GL.ARB_fragment_shader && VersionData.GL.ARB_uniform_buffer_object))
	{
		glGetIntegerv(GL_MAX_FRAGMENT_UNIFORM_BLOCKS, &FragmentData.MAX_FRAGMENT_UNIFORM_BLOCKS);
		glGetIntegerv(GL_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS, &FragmentData.MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS);
	}
	if(check(3, 3) || (VersionData.GL.ARB_blend_func_extended))
		glGetIntegerv(GL_MAX_DUAL_SOURCE_DRAW_BUFFERS, &FragmentData.MAX_DUAL_SOURCE_DRAW_BUFFERS);
	if(check(4, 2) || (VersionData.GL.ARB_fragment_shader && VersionData.GL.ARB_shader_atomic_counters))
		glGetIntegerv(GL_MAX_FRAGMENT_ATOMIC_COUNTERS, &FragmentData.MAX_FRAGMENT_ATOMIC_COUNTERS);
	if(check(4, 3) || (VersionData.GL.ARB_fragment_shader && VersionData.GL.ARB_shader_storage_buffer_object))
		glGetIntegerv(GL_MAX_FRAGMENT_SHADER_STORAGE_BLOCKS, &FragmentData.MAX_FRAGMENT_SHADER_STORAGE_BLOCKS);
}

void caps::initPulling()
{
	memset(&PullingData, 0, sizeof(PullingData));

	if(check(2, 1))
	{
		glGetIntegerv(GL_MAX_ELEMENTS_INDICES, &PullingData.MAX_ELEMENTS_INDICES);
		glGetIntegerv(GL_MAX_ELEMENTS_VERTICES, &PullingData.MAX_ELEMENTS_VERTICES);
	}

	if(check(4, 3) || (VersionData.GL.ARB_vertex_attrib_binding))
	{
		glGetIntegerv(GL_MAX_VERTEX_ATTRIB_RELATIVE_OFFSET, &PullingData.MAX_VERTEX_ATTRIB_RELATIVE_OFFSET);
		glGetIntegerv(GL_MAX_VERTEX_ATTRIB_BINDINGS, &PullingData.MAX_VERTEX_ATTRIB_BINDINGS);
	}

	if(check(4, 3) || (VersionData.GL.ARB_ES3_compatibility))
		glGetIntegerv(GL_MAX_ELEMENT_INDEX, &PullingData.MAX_ELEMENT_INDEX);
}

void caps::initRasterizer()
{
	memset(&RasterizerData, 0, sizeof(RasterizerData));

	if(check(2, 1))
	{
		glGetIntegerv(GL_SUBPIXEL_BITS, &RasterizerData.SUBPIXEL_BITS);
		glGetFloatv(GL_MAX_VIEWPORT_DIMS, &RasterizerData.MAX_VIEWPORT_DIMS);
	}

	if(check(3, 0))
	{
		glGetIntegerv(GL_MAX_CLIP_DISTANCES, &RasterizerData.MAX_CLIP_DISTANCES);
	}

	if(check(4, 1) || (VersionData.GL.ARB_viewport_array))
	{
		glGetIntegerv(GL_MAX_VIEWPORTS, &RasterizerData.MAX_VIEWPORTS);
		glGetIntegerv(GL_VIEWPORT_SUBPIXEL_BITS, &RasterizerData.VIEWPORT_SUBPIXEL_BITS);
		glGetFloatv(GL_VIEWPORT_BOUNDS_RANGE, RasterizerData.VIEWPORT_BOUNDS_RANGE);
	}
}

void caps::initFramebuffer()
{
	memset(&FramebufferData, 0, sizeof(FramebufferData));

	if(check(3, 0) || (VersionData.GL.ARB_framebuffer_object))
	{
		glGetIntegerv(GL_MAX_COLOR_ATTACHMENTS, &FramebufferData.MAX_COLOR_ATTACHMENTS);
		glGetIntegerv(GL_MAX_FRAMEBUFFER_WIDTH, &FramebufferData.MAX_FRAMEBUFFER_WIDTH);
		glGetIntegerv(GL_MAX_FRAMEBUFFER_HEIGHT, &FramebufferData.MAX_FRAMEBUFFER_HEIGHT);
		glGetIntegerv(GL_MAX_FRAMEBUFFER_LAYERS, &FramebufferData.MAX_FRAMEBUFFER_LAYERS);
		glGetIntegerv(GL_MAX_FRAMEBUFFER_SAMPLES, &FramebufferData.MAX_FRAMEBUFFER_SAMPLES);
		glGetIntegerv(GL_MAX_RENDERBUFFER_SIZE, &FramebufferData.MAX_RENDERBUFFER_SIZE);
	}
}

void caps::initBuffer()
{
	memset(&BufferData, 0, sizeof(BufferData));

	if(check(4, 0) || (VersionData.GL.ARB_transform_feedback3))
		glGetIntegerv(GL_MAX_TRANSFORM_FEEDBACK_BUFFERS, &BufferData.MAX_TRANSFORM_FEEDBACK_BUFFERS);
	if(check(4, 2) || (VersionData.GL.ARB_map_buffer_alignment))
		glGetIntegerv(GL_MIN_MAP_BUFFER_ALIGNMENT, &BufferData.MIN_MAP_BUFFER_ALIGNMENT);
}

void caps::initTexture()
{
	memset(&TextureData, 0, sizeof(TextureData));

	if(check(2, 1))
	{
		glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &TextureData.MAX_TEXTURE_IMAGE_UNITS);
		glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &TextureData.MAX_COMBINED_TEXTURE_IMAGE_UNITS);
		glGetIntegerv(GL_MAX_TEXTURE_LOD_BIAS, &TextureData.MAX_TEXTURE_LOD_BIAS);
		glGetIntegerv(GL_MAX_TEXTURE_SIZE, &TextureData.MAX_TEXTURE_SIZE);
		glGetIntegerv(GL_MAX_3D_TEXTURE_SIZE, &TextureData.MAX_3D_TEXTURE_SIZE);
		glGetIntegerv(GL_MAX_CUBE_MAP_TEXTURE_SIZE, &TextureData.MAX_CUBE_MAP_TEXTURE_SIZE);
		glGetIntegerv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &TextureData.MAX_TEXTURE_MAX_ANISOTROPY_EXT);
	}

	if(check(3, 0) || (VersionData.GL.EXT_texture_array))
		glGetIntegerv(GL_MAX_ARRAY_TEXTURE_LAYERS, &TextureData.MAX_ARRAY_TEXTURE_LAYERS);

	if(check(3, 0) || (VersionData.GL.ARB_texture_buffer_object))
		glGetIntegerv(GL_MAX_TEXTURE_BUFFER_SIZE, &TextureData.MAX_TEXTURE_BUFFER_SIZE);

	if(check(3, 2) || (VersionData.GL.ARB_texture_multisample))
	{
		glGetIntegerv(GL_MAX_SAMPLE_MASK_WORDS, &FramebufferData.MAX_SAMPLE_MASK_WORDS);
		glGetIntegerv(GL_MAX_COLOR_TEXTURE_SAMPLES, &TextureData.MAX_COLOR_TEXTURE_SAMPLES);
		glGetIntegerv(GL_MAX_DEPTH_TEXTURE_SAMPLES, &TextureData.MAX_DEPTH_TEXTURE_SAMPLES);
		glGetIntegerv(GL_MAX_INTEGER_SAMPLES, &TextureData.MAX_INTEGER_SAMPLES);
	}

	if(check(3, 3) || (VersionData.GL.ARB_texture_rectangle))
		glGetIntegerv(GL_MAX_RECTANGLE_TEXTURE_SIZE, &TextureData.MAX_RECTANGLE_TEXTURE_SIZE);
		
	glGetIntegerv(GL_NUM_COMPRESSED_TEXTURE_FORMATS, &TextureData.NUM_COMPRESSED_TEXTURE_FORMATS);

	std::vector<GLint> Formats;
	Formats.resize(static_cast<std::size_t>(TextureData.NUM_COMPRESSED_TEXTURE_FORMATS));
	glGetIntegerv(GL_COMPRESSED_TEXTURE_FORMATS, &Formats[0]);
	for(std::size_t i = 0; i < Formats.size(); ++i)
	{
		switch(Formats[i])
		{
		case GL_COMPRESSED_RGB_S3TC_DXT1_EXT:
			TextureData.COMPRESSED_RGB_S3TC_DXT1_EXT = true;
			break;
		case GL_COMPRESSED_RGBA_S3TC_DXT1_EXT:
			TextureData.COMPRESSED_RGBA_S3TC_DXT1_EXT = true;
			break;
		case GL_COMPRESSED_RGBA_S3TC_DXT3_EXT:
			TextureData.COMPRESSED_RGBA_S3TC_DXT3_EXT = true;
			break;
		case GL_COMPRESSED_RGBA_S3TC_DXT5_EXT:
			TextureData.COMPRESSED_RGBA_S3TC_DXT5_EXT = true;
			break;
		case GL_COMPRESSED_RED_RGTC1:
			TextureData.COMPRESSED_RED_RGTC1 = true;
			break;
		case GL_COMPRESSED_SIGNED_RED_RGTC1:
			TextureData.COMPRESSED_SIGNED_RED_RGTC1 = true;
			break;
		case GL_COMPRESSED_RG_RGTC2:
			TextureData.COMPRESSED_RG_RGTC2 = true;
			break;
		case GL_COMPRESSED_SIGNED_RG_RGTC2:
			TextureData.COMPRESSED_SIGNED_RG_RGTC2 = true;
			break;
		case GL_COMPRESSED_RGBA_BPTC_UNORM:
			TextureData.COMPRESSED_RGBA_BPTC_UNORM = true;
			break;
		case GL_COMPRESSED_SRGB_ALPHA_BPTC_UNORM:
			TextureData.COMPRESSED_SRGB_ALPHA_BPTC_UNORM = true;
			break;
		case GL_COMPRESSED_RGB_BPTC_SIGNED_FLOAT:
			TextureData.COMPRESSED_RGB_BPTC_SIGNED_FLOAT = true;
			break;
		case GL_COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT:
			TextureData.COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT = true;
			break;
		case GL_COMPRESSED_RGBA_ASTC_4x4_KHR:
			TextureData.COMPRESSED_RGBA_ASTC_4x4_KHR = true;
			break;
		case GL_COMPRESSED_RGBA_ASTC_5x4_KHR:
			TextureData.COMPRESSED_RGBA_ASTC_5x4_KHR = true;
			break;
		case GL_COMPRESSED_RGBA_ASTC_5x5_KHR:
			TextureData.COMPRESSED_RGBA_ASTC_5x5_KHR = true;
			break;
		case GL_COMPRESSED_RGBA_ASTC_6x5_KHR:
			TextureData.COMPRESSED_RGBA_ASTC_6x5_KHR = true;
			break;
		case GL_COMPRESSED_RGBA_ASTC_6x6_KHR:
			TextureData.COMPRESSED_RGBA_ASTC_6x6_KHR = true;
			break;
		case GL_COMPRESSED_RGBA_ASTC_8x5_KHR:
			TextureData.COMPRESSED_RGBA_ASTC_8x5_KHR = true;
			break;
		case GL_COMPRESSED_RGBA_ASTC_8x6_KHR:
			TextureData.COMPRESSED_RGBA_ASTC_8x6_KHR = true;
			break;
		case GL_COMPRESSED_RGBA_ASTC_8x8_KHR:
			TextureData.COMPRESSED_RGBA_ASTC_8x8_KHR = true;
			break;
		case GL_COMPRESSED_RGBA_ASTC_10x5_KHR:
			TextureData.COMPRESSED_RGBA_ASTC_10x5_KHR = true;
			break;
		case GL_COMPRESSED_RGBA_ASTC_10x6_KHR:
			TextureData.COMPRESSED_RGBA_ASTC_10x6_KHR = true;
			break;
		case GL_COMPRESSED_RGBA_ASTC_10x8_KHR:
			TextureData.COMPRESSED_RGBA_ASTC_10x8_KHR = true;
			break;
		case GL_COMPRESSED_RGBA_ASTC_10x10_KHR:
			TextureData.COMPRESSED_RGBA_ASTC_10x10_KHR = true;
			break;
		case GL_COMPRESSED_RGBA_ASTC_12x10_KHR:
			TextureData.COMPRESSED_RGBA_ASTC_12x10_KHR = true;
			break;
		case GL_COMPRESSED_RGBA_ASTC_12x12_KHR:
			TextureData.COMPRESSED_RGBA_ASTC_12x12_KHR = true;
			break;
		case GL_COMPRESSED_RGB8_ETC2:
			TextureData.COMPRESSED_RGB8_ETC2 = true;
			break;
		case GL_COMPRESSED_SRGB8_ETC2:
			TextureData.COMPRESSED_SRGB8_ETC2 = true;
			break;
		case GL_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2:
			TextureData.COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 = true;
			break;
		case GL_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2:
			TextureData.COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 = true;
			break;
		case GL_COMPRESSED_RGBA8_ETC2_EAC:
			TextureData.COMPRESSED_RGBA8_ETC2_EAC = true;
			break;
		case GL_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC:
			TextureData.COMPRESSED_SRGB8_ALPHA8_ETC2_EAC = true;
			break;
		case GL_COMPRESSED_R11_EAC:
			TextureData.COMPRESSED_R11_EAC = true;
			break;
		case GL_COMPRESSED_SIGNED_R11_EAC:
			TextureData.COMPRESSED_SIGNED_R11_EAC = true;
			break;
		case GL_COMPRESSED_RG11_EAC :
			TextureData.COMPRESSED_RG11_EAC  = true;
			break;
		case GL_COMPRESSED_SIGNED_RG11_EAC:
			TextureData.COMPRESSED_SIGNED_RG11_EAC = true;
			break;
		case GL_PALETTE4_RGB8_OES:
			TextureData.PALETTE4_RGB8_OES = true;
			break;
		case GL_PALETTE4_RGBA8_OES:
			TextureData.PALETTE4_RGBA8_OES = true;
			break;
		case GL_PALETTE4_R5_G6_B5_OES:
			TextureData.PALETTE4_R5_G6_B5_OES = true;
			break;
		case GL_PALETTE4_RGBA4_OES:
			TextureData.PALETTE4_RGBA4_OES = true;
			break;
		case GL_PALETTE4_RGB5_A1_OES:
			TextureData.PALETTE4_RGB5_A1_OES = true;
			break;
		case GL_PALETTE8_RGB8_OES:
			TextureData.PALETTE8_RGB8_OES = true;
			break;
		case GL_PALETTE8_RGBA8_OES:
			TextureData.PALETTE8_RGBA8_OES = true;
			break;
		case GL_PALETTE8_R5_G6_B5_OES:
			TextureData.PALETTE8_R5_G6_B5_OES = true;
			break;
		case GL_PALETTE8_RGBA4_OES:
			TextureData.PALETTE8_RGBA4_OES = true;
			break;
		case GL_PALETTE8_RGB5_A1_OES:
			TextureData.PALETTE8_RGB5_A1_OES = true;
			break;
		case GL_ETC1_RGB8_OES:
			TextureData.ETC1_RGB8_OES = true;
			break;
		default:
			//assert(0);
			break;
		}
	}

	if(VersionData.GL.EXT_texture_compression_s3tc)
	{
		TextureData.COMPRESSED_RGB_S3TC_DXT1_EXT = true;
		TextureData.COMPRESSED_RGBA_S3TC_DXT1_EXT = true;
		TextureData.COMPRESSED_RGBA_S3TC_DXT3_EXT = true;
		TextureData.COMPRESSED_RGBA_S3TC_DXT5_EXT = true;
	}
	if(check(3, 0) || VersionData.GL.ARB_texture_compression_rgtc)
	{
		TextureData.COMPRESSED_RED_RGTC1 = true;
		TextureData.COMPRESSED_SIGNED_RED_RGTC1 = true;
		TextureData.COMPRESSED_RG_RGTC2 = true;
		TextureData.COMPRESSED_SIGNED_RG_RGTC2 = true;
	}
	if(check(4, 0) || VersionData.GL.ARB_texture_compression_bptc)
	{
		TextureData.COMPRESSED_RGBA_BPTC_UNORM = true;
		TextureData.COMPRESSED_SRGB_ALPHA_BPTC_UNORM = true;
		TextureData.COMPRESSED_RGB_BPTC_UNSIGNED_FLOAT = true;
		TextureData.COMPRESSED_RGB_BPTC_SIGNED_FLOAT = true;
	}
}

void caps::initProgram()
{
	glGetIntegerv(GL_MAX_SUBROUTINES, &ProgramData.MAX_SUBROUTINES);
	glGetIntegerv(GL_MAX_SUBROUTINE_UNIFORM_LOCATIONS, &ProgramData.MAX_SUBROUTINE_UNIFORM_LOCATIONS);
	glGetIntegerv(GL_MAX_COMBINED_ATOMIC_COUNTERS, &ProgramData.MAX_COMBINED_ATOMIC_COUNTERS);
	glGetIntegerv(GL_MAX_COMBINED_SHADER_STORAGE_BLOCKS, &ProgramData.MAX_COMBINED_SHADER_STORAGE_BLOCKS);
	glGetIntegerv(GL_MAX_PROGRAM_TEXEL_OFFSET, &ProgramData.MAX_PROGRAM_TEXEL_OFFSET);
	glGetIntegerv(GL_MIN_PROGRAM_TEXEL_OFFSET, &ProgramData.MIN_PROGRAM_TEXEL_OFFSET);
	glGetIntegerv(GL_MAX_COMBINED_UNIFORM_BLOCKS, &ProgramData.MAX_COMBINED_UNIFORM_BLOCKS);
	glGetIntegerv(GL_MAX_UNIFORM_BUFFER_BINDINGS, &ProgramData.MAX_UNIFORM_BUFFER_BINDINGS);
	glGetIntegerv(GL_MAX_UNIFORM_BLOCK_SIZE, &ProgramData.MAX_UNIFORM_BLOCK_SIZE);
	glGetIntegerv(GL_MAX_UNIFORM_LOCATIONS, &ProgramData.MAX_UNIFORM_LOCATIONS);
	glGetIntegerv(GL_MAX_VARYING_COMPONENTS, &ProgramData.MAX_VARYING_COMPONENTS);
	glGetIntegerv(GL_MAX_VARYING_VECTORS, &ProgramData.MAX_VARYING_VECTORS);
	glGetIntegerv(GL_MAX_VARYING_FLOATS, &ProgramData.MAX_VARYING_FLOATS);
	glGetIntegerv(GL_MAX_SHADER_STORAGE_BUFFER_BINDINGS, &ProgramData.MAX_SHADER_STORAGE_BUFFER_BINDINGS);
	glGetIntegerv(GL_MAX_SHADER_STORAGE_BLOCK_SIZE, &ProgramData.MAX_SHADER_STORAGE_BLOCK_SIZE);
	glGetIntegerv(GL_MAX_COMBINED_SHADER_OUTPUT_RESOURCES, &ProgramData.MAX_COMBINED_SHADER_OUTPUT_RESOURCES);
	glGetIntegerv(GL_SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT, &ProgramData.SHADER_STORAGE_BUFFER_OFFSET_ALIGNMENT);
	glGetIntegerv(GL_UNIFORM_BUFFER_OFFSET_ALIGNMENT, &ProgramData.UNIFORM_BUFFER_OFFSET_ALIGNMENT);
	glGetIntegerv(GL_NUM_PROGRAM_BINARY_FORMATS, &ProgramData.NUM_PROGRAM_BINARY_FORMATS);
	glGetIntegerv(GL_NUM_SHADER_BINARY_FORMATS, &ProgramData.NUM_SHADER_BINARY_FORMATS);
	glGetIntegerv(GL_PROGRAM_BINARY_FORMATS, &ProgramData.PROGRAM_BINARY_FORMATS);
}

caps::caps(profile const & Profile) :
	VersionData(Profile),
	Version(VersionData),
	Debug(DebugData),
	Compute(ComputeData),
	Vertex(VertexData),
	Control(ControlData),
	Evaluation(EvaluationData),
	Geometry(GeometryData),
	Fragment(FragmentData),
	Pulling(PullingData),
	Framebuffer(FramebufferData),
	Rasterizer(RasterizerData),
	Buffer(BufferData),
	Texture(TextureData),
	Program(ProgramData)
{
	this->initVersion();
	this->initDebug();
	this->initCompute();
	this->initVertex();
	this->initControl();
	this->initEvaluation();
	this->initGeometry();
	this->initFragment();
	this->initPulling();
	this->initRasterizer();
	this->initFramebuffer();
	this->initBuffer();
	this->initTexture();
	this->initProgram();
}
