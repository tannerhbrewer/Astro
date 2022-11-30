#pragma once

#include "Core.h"

#include "Window.h"
#include "Astro/LayerStack.h"
#include "Astro/Events/Event.h"
#include "Astro/Events/ApplicationEvent.h"


namespace Astro {

	class ASTRO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}