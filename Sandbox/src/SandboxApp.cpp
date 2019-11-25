#include <Jumbo.h>

class Sandbox : public Jumbo::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Jumbo::Application* Jumbo::CreateApplication()
{
	return new Sandbox();
}