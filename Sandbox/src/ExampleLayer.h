#pragma once

#include "Astro.h"

class ExampleLayer : public Astro::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Astro::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Astro::Event& e) override;
private:
	Astro::ShaderLibrary m_ShaderLibrary;

	Astro::Ref<Astro::Shader> m_Shader;
	Astro::Ref<Astro::VertexArray> m_VertexArray;

	Astro::Ref<Astro::Shader> m_FlatColorShader;
	Astro::Ref<Astro::VertexArray> m_SquareVA;

	Astro::Ref<Astro::Texture2D> m_Texture, m_Logo;

	glm::vec3 m_SquarePosition;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };

	Astro::OrthographicCameraController m_CameraController;
};