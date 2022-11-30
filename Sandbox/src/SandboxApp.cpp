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
		//AS_INFO("ExampleLayer::Update");
	}

	void OnEvent(Astro::Event& event) override
	{
		//AS_TRACE("{0}", event);
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