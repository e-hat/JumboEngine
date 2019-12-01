#pragma once

#include "JumboEngine/Layer.h"
#include "JumboEngine/Events/MouseEvent.h"
#include "JumboEngine/Events/KeyEvent.h"
#include "JumboEngine/Events/ApplicationEvent.h"


namespace Jumbo
{
	class JUMBO_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
					   
	private:
		float m_Time = 0.0f;
	};
}