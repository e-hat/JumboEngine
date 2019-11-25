#pragma once

#ifdef JB_PLATFORM_WINDOWS

extern Jumbo::Application* Jumbo::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Jumbo::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#endif