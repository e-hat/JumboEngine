#include <Jumbo.h>

class ExampleLayer : public Jumbo::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
	}

	void OnUpdate() override
	{
		JB_INFO("ExampleLayer::Update");
	}

	void OnEvent(Jumbo::Event& event) override
	{
		JB_TRACE("{0}", event);
	}
};

class Sandbox : public Jumbo::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Jumbo::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

Jumbo::Application* Jumbo::CreateApplication()
{
	return new Sandbox();
}