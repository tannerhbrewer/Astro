#pragma once

#include "Astro.h"

class Sandbox2D : public Astro::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Astro::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Astro::Event& e) override;
private:
	Astro::OrthographicCameraController m_CameraController;

	// Temp
	Astro::Ref<Astro::VertexArray> m_SquareVA;
	Astro::Ref<Astro::Shader> m_FlatColorShader;

	Astro::Ref<Astro::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
	glm::vec3 m_SquarePosition = { 0.0f, 0.0f, 0.0f};
};