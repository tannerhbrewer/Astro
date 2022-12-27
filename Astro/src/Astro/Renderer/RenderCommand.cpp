#include "aspch.h"

#include "Astro/Renderer/RenderCommand.h"

namespace Astro {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}