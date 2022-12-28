#include "Sandbox2D.h"

#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	m_CheckerboardTexture = Astro::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Astro::Timestep ts)
{
	AS_PROFILE_FUNCTION();

	// Update
	{
		AS_PROFILE_SCOPE("CameraController::OnUpdate");
		m_CameraController.OnUpdate(ts);
	}

	// Render
	{
		AS_PROFILE_SCOPE("Renderer Prep");
		Astro::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Astro::RenderCommand::Clear();
	}

	{
		AS_PROFILE_SCOPE("Renderer Draw");
		Astro::Renderer2D::BeginScene(m_CameraController.GetCamera());
		Astro::Renderer2D::DrawQuad(m_SquarePosition, { 0.8f, 0.8f }, m_SquareColor);
		Astro::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 1.0f, 0.3f, 0.8f, 1.0f });
		Astro::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
		Astro::Renderer2D::EndScene();
	}
}

void Sandbox2D::OnImGuiRender()
{
	AS_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::SliderFloat3("Square Position", glm::value_ptr(m_SquarePosition), 0.0f, 5.0f);
	ImGui::End();
}

void Sandbox2D::OnEvent(Astro::Event& e)
{
	m_CameraController.OnEvent(e);
}