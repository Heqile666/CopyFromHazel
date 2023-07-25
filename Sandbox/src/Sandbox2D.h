#pragma once
#include "Hazel.h"
class Sandbox2D :public Hazel::Layer {

public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;
	void OnUpdate(Hazel::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Hazel::Event& e) override;
	virtual void OnAttach() override;
	virtual void OnDetach() override;
	

private:
	Hazel::ShaderLibrary m_ShaderLibrary;
	Hazel::Ref<Hazel::Shader> m_Shader;
	Hazel::Ref<Hazel::VertexArray> m_VertexArray;

	Hazel::Ref<Hazel::Shader> m_BlueShader;

	Hazel::Ref<Hazel::VertexArray> m_SquareVA;
	Hazel::Ref<Hazel::Texture2D>m_Texture;
	Hazel::OrthographicCameraController m_CameraController;
	glm::vec3 m_CameraPosition;


	glm::vec3 m_SquarePosition;

	glm::vec4 m_SquareColor = { 0.2f,0.3f,0.8f,1.0f };



};