#pragma once

#include "Core.h"

#include "LayerStack.h"
#include "Events/Event.h"
#include "Window.h"
#include "JumboEngine/Events/ApplicationEvent.h"

namespace Jumbo
{

	class JUMBO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};
	// TO BE DEFINED IN CLIENT
	Application* CreateApplication();

}

