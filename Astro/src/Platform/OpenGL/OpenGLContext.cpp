#include "aspch.h"

#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <gl/GL.h>

namespace Astro {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		AS_CORE_ASSERT(windowHandle, "Window handle is null.")
	}

	void OpenGLContext::Init()
	{
		AS_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		AS_CORE_ASSERT(status, "Failed to initialize Glad.")

		AS_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "Astro requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::SwapBuffers()
	{
		AS_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}

}