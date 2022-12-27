#pragma once

#include <memory>

#include "Astro/Core/Core.h"

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Astro {

	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define AS_CORE_TRACE(...)    ::Astro::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AS_CORE_INFO(...)     ::Astro::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AS_CORE_WARN(...)     ::Astro::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AS_CORE_ERROR(...)    ::Astro::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AS_CORE_FATAL(...)    ::Astro::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define AS_TRACE(...)	      ::Astro::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AS_INFO(...)	      ::Astro::Log::GetClientLogger()->info(__VA_ARGS__)
#define AS_WARN(...)	      ::Astro::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AS_ERROR(...)	      ::Astro::Log::GetClientLogger()->error(__VA_ARGS__)
#define AS_FATAL(...)	      ::Astro::Log::GetClientLogger()->critical(__VA_ARGS__)