#pragma once

#ifdef JB_PLATFORM_WINDOWS

extern Jumbo::Application* Jumbo::CreateApplication();

int main(int argc, char** argv)
{
	Jumbo::Log::Init();
	JB_CORE_INFO("Initialized log.");
	JB_INFO("Initialized log.");

	auto app = Jumbo::CreateApplication();
	app->Run();
	delete app;
}

#endif