#pragma once

#include "Core.h"

namespace Jumbo
{

	class JUMBO_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};
	// TO BE DEFINED IN CLIENT
	Application* CreateApplication();

}

