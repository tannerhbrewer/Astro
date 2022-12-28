#pragma once
#include "Astro/Core/Core.h"

#ifdef AS_PLATFORM_WINDOWS

extern Astro::Application* Astro::CreateApplication();

int main(int argc, char** argv)
{
	Astro::Log::Init();
	
	AS_PROFILE_BEGIN_SESSION("Startup", "Astro-Profile-Startup.json");
	auto app = Astro::CreateApplication();
	AS_PROFILE_END_SESSION();

	AS_PROFILE_BEGIN_SESSION("Runtime", "Astro-Profile-Runtime.json");
	app->Run();
	AS_PROFILE_END_SESSION();

	AS_PROFILE_BEGIN_SESSION("Startup", "Astro-Profile-Shutdown.json");
	delete app;
	AS_PROFILE_END_SESSION();
}

#endif