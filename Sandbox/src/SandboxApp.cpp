#include <Astro.h>

class ExampleLayer : public Astro::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_Camera(-1.6f, 1.6f, -0.9f, 0.9f), m_CameraPosition(0.0f, 0.0f, 0.0f)
	{
		m_VertexArray.reset(Astro::VertexArray::Create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		std::shared_ptr<Astro::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Astro::VertexBuffer::Create(vertices, sizeof(vertices)));
		Astro::BufferLayout layout = {
			{ Astro::ShaderDataType::Float3, "a_Position" },
			{ Astro::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		std::shared_ptr<Astro::IndexBuffer> indexBuffer;
		indexBuffer.reset(Astro::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(indexBuffer);

		m_SquareVA.reset(Astro::VertexArray::Create());

		float squareVertices[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f,
			 0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f
		};

		std::shared_ptr<Astro::VertexBuffer> squareVB;
		squareVB.reset(Astro::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Astro::ShaderDataType::Float3, "a_Position" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<Astro::IndexBuffer> squareIB;
		squareIB.reset(Astro::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;
			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);	
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;
			void main()
			{
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader.reset(new Astro::Shader(vertexSrc, fragmentSrc));

		std::string blueShaderVertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Position;
			out vec3 v_Position;

			uniform mat4 u_ViewProjection;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);	
			}
		)";

		std::string blueShaderFragmentSrc = R"(
			#version 330 core
			
			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			void main()
			{
				color = vec4(0.2, 0.3, 0.8, 1.0);
			}
		)";

		m_BlueShader.reset(new Astro::Shader(blueShaderVertexSrc, blueShaderFragmentSrc));
	}

	void OnUpdate() override
	{
		if (Astro::Input::IsKeyPressed(AS_KEY_W))
			m_CameraPosition.y += m_CameraSpeed;
		else if (Astro::Input::IsKeyPressed(AS_KEY_S))
			m_CameraPosition.y -= m_CameraSpeed;

		if (Astro::Input::IsKeyPressed(AS_KEY_A))
			m_CameraPosition.x -= m_CameraSpeed;
		else if (Astro::Input::IsKeyPressed(AS_KEY_D))
			m_CameraPosition.x += m_CameraSpeed;

		if (Astro::Input::IsKeyPressed(AS_KEY_Q))
			m_CameraRotation += m_CameraSpeedRotation;
		else if (Astro::Input::IsKeyPressed(AS_KEY_E))
			m_CameraRotation -= m_CameraSpeedRotation;


		Astro::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Astro::RenderCommand::Clear();

		m_Camera.SetPosition(m_CameraPosition);
		m_Camera.SetRotation(m_CameraRotation);

		Astro::Renderer::BeginScene(m_Camera);

		Astro::Renderer::Submit(m_BlueShader, m_SquareVA);
		Astro::Renderer::Submit(m_Shader, m_VertexArray);

		Astro::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
	}

	void OnEvent(Astro::Event& event) override
	{
		Astro::EventDispatcher dispatcher(event);
		//dispatcher.Dispatch<Astro::KeyPressedEvent>(AS_BIND_EVENT_FN(ExampleLayer::OnKeyPressedEvent));
	}

	bool OnKeyPressedEvent(Astro::KeyPressedEvent& event)
	{
		if (event.GetKeyCode() == AS_KEY_LEFT)
			m_CameraPosition.x += m_CameraSpeed;

		if (event.GetKeyCode() == AS_KEY_RIGHT)
			m_CameraPosition.x -= m_CameraSpeed;

		if (event.GetKeyCode() == AS_KEY_UP)
			m_CameraPosition.y -= m_CameraSpeed;

		if (event.GetKeyCode() == AS_KEY_DOWN)
			m_CameraPosition.y += m_CameraSpeed;

		return false;
	}
private:
	std::shared_ptr<Astro::Shader> m_Shader;
	std::shared_ptr<Astro::VertexArray> m_VertexArray;

	std::shared_ptr<Astro::Shader> m_BlueShader;
	std::shared_ptr<Astro::VertexArray> m_SquareVA;

	Astro::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraSpeed = 0.1f;

	float m_CameraRotation = 0.0f;
	float m_CameraSpeedRotation = 2.0f;
};

class Sandbox : public Astro::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}

};

Astro::Application* Astro::CreateApplication()
{
	return new Sandbox();
}