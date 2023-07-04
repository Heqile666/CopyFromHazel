#pragma once
#include"Hazel/Input.h"

namespace Hazel {
	class WindowsInput :public Input {

	protected:
		virtual bool IsMouseButtonPressedImpl(int button) override ;
		virtual std::pair<float, float> GetMousePositionImpl() override;
		virtual bool IsKeyPressedImpl(int keycode)  override;
		virtual float GetMouseXImpl() override ;
		virtual float GetMouseYImpl() override ;

	};

}