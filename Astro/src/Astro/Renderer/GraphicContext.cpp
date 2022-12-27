#include "aspch.h"
#include "Astro/Renderer/GraphicsContext.h"

#include "Astro/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace Astro {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    AS_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		AS_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}