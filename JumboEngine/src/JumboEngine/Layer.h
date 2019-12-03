#pragma once

#include "JumboEngine/Core.h"
#include "JumboEngine/Events/Event.h"

namespace Jumbo
{
	class  Layer
	{
	public:
		Layer(const std::string& debugName = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
			
	protected:
		std::string m_DebugName;
	};
}