#include "aspch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Astro {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();

}