#include <Astro.h>

class ExampleLayer : public Astro::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
	}

	void OnEvent(Astro::Event& event) override
	{
		if (event.GetEventType() == Astro::EventType::KeyPressed)
		{
			Astro::KeyPressedEvent& e = (Astro::KeyPressedEvent&)event;

			AS_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};

class Sandbox : public Astro::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushLayer(new Astro::ImGuiLayer());
	}

	~Sandbox()
	{

	}

};

Astro::Application* Astro::CreateApplication()
{
	return new Sandbox();
}