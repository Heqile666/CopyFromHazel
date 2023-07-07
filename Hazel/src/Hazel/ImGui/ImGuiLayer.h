#pragma once

#include "Hazel/Layer.h"
#include"Hazel/Events/KeyEvent.h"
#include "Hazel/Events/MouseEvent.h"
#include "Hazel/Events/ApplicationEvent.h"
namespace Hazel {

	class HAZEL_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach()override;
		virtual void OnDetach()override;
		virtual void OnImGuiRender() override;
		void Begin();
		void End();
		
	private:

	
	private:
		float m_Time = 0.0f;
	};
}