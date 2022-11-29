#include "aspch.h"
#include "Application.h"

#include "Astro/Events/ApplicationEvent.h"
#include "Astro/Log.h"

#include <GLFW/glfw3.h>

namespace Astro {

	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (m_Running)
		{
			glClearColor(0.2f, 0.2f, 0.2f, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

}