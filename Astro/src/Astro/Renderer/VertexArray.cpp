#include "aspch.h"

#include "Astro/Renderer/VertexArray.h"
#include "Astro/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace Astro {

	Ref<VertexArray> VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    AS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateRef<OpenGLVertexArray>();
		}

		AS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}