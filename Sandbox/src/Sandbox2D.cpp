#include "Sandbox2D.h"
#include "imgui/imgui.h"
#include <glm/gtc/type_ptr.hpp>
#include <Platform/OpenGL/OpenGLShader.h>

Sandbox2D::Sandbox2D()
	:Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}
void Sandbox2D::OnUpdate(Hazel::Timestep ts)
{
	m_CameraController.OnUpdate(ts);


	Hazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Hazel::RenderCommand::Clear();


	Hazel::Renderer2D::BeginScene(m_CameraController.GetCamera());


	Hazel::Renderer2D::DrawQuad({ -1.0f,0.0f }, { 0.8f,1.0f }, { 0.8f,0.2f,0.3f,1.0f });
	//Hazel::Renderer2D::DrawQuad({ 0.5f,-0.5f }, { 0.5f,0.75f }, { 0.6f,0.8f,0.7f,1.0f });
	Hazel::Renderer2D::DrawQuad({ 0.2f,0.5f }, { 0.5f,0.5f }, m_Texture);

	Hazel::Renderer2D::EndScene();
	/*Hazel::Material material = new Hazel::Material(shader);
	material->Set("u_Color", redColor);
	squareMesh->SetMaterial(material);*/
	/*std::dynamic_pointer_cast<Hazel::OpenGLShader>(m_BlueShader)->Bind();
	std::dynamic_pointer_cast<Hazel::OpenGLShader>(m_BlueShader)->UploadUniformFloat4("u_Color", m_SquareColor);*/
	
}

void Sandbox2D::OnImGuiRender()
{

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Hazel::Event& e)
{
	m_CameraController.OnEvent(e);
}

void Sandbox2D::OnAttach()
{
	m_Texture = Hazel::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{

}
