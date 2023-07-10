
#include <Hazel.h>


#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi


class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{
	
		
	
	}

	void OnUpdate() override
	{
		if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB)) {
			HZ_INFO("Tap Key is pressed");
		}
	}

	void OnEvent(Hazel::Event& event) override
	{
		if (event.GetEventType() == Hazel::EventType::KeyPressed) {
			Hazel::KeyPressedEvent& e = (Hazel::KeyPressedEvent&)event;
			HZ_TRACE("{0}", (char)e.GetKeyCode());
		}
	}
};

class Sandbox:public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		
	}

	~Sandbox()
	{
	
	}

private:

};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}