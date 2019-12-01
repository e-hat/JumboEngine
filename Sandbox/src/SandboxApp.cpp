#include <Jumbo.h>

#include <imgui.h>

class ExampleLayer : public Jumbo::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
	}

	virtual void OnUpdate() override
	{
		//JB_INFO("ExampleLayer::Update");
	}

	virtual void OnEvent(Jumbo::Event& event) override
	{
		//JB_TRACE("{0}", event);
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World!");
		ImGui::End();
	}
};

class Sandbox : public Jumbo::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Jumbo::Application* Jumbo::CreateApplication()
{
	return new Sandbox();
}