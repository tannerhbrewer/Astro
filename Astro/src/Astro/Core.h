#pragma once

#pragma once

#ifdef AS_PLATFORM_WINDOWS
	#ifdef AS_BUILD_DLL
		#define ASTRO_API __declspec(dllexport)
	#else
		#define ASTRO_API __declspec(dllimport)
	#endif
#else
	#error Astro only supports Windows!
#endif