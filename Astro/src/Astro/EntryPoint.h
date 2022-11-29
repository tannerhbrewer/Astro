#pragma once

#ifdef AS_PLATFORM_WINDOWS

extern Astro::Application* Astro::CreateApplication();

int main(int argc, char** argv)
{
	Astro::Log::Init();
	AS_CORE_WARN("Initialized Log!");
	int a = 5;
	AS_INFO("Hello! Var={0}", a);
	
	auto app = Astro::CreateApplication();
	app->Run();
	delete app;
}

#endif