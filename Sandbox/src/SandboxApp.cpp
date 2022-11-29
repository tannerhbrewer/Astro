#include <Astro.h>

class Sandbox : public Astro::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Astro::Application* Astro::CreateApplication()
{
	return new Sandbox();
}