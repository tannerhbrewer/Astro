#include "aspch.h"
#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Astro {

	Application::Application()
	{
	}


	Application::~Application()
	{
	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			AS_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			AS_TRACE(e);
		}

		while (true);
	}

}