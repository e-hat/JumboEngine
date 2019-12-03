#include "jbpch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <gl/GL.h>

namespace Jumbo
{
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		JB_CORE_ASSERT(windowHandle, "Window handle is null!");
	}

	void OpenGLContext::Init()
	{ 
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		JB_CORE_ASSERT(status, "Failed to initialize Glad!");

		JB_CORE_INFO("OpenGL Info:");
		JB_CORE_INFO("	Vendor: {0}", glGetString(GL_VENDOR));
		JB_CORE_INFO("	Renderer: {0}", glGetString(GL_RENDERER));
		JB_CORE_INFO("	Version: {0}", glGetString(GL_VERSION));

	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}
