#pragma once

#include "Astro/Renderer/VertexArray.h"

namespace Astro {

	class OpenGLVertexArray : public VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void Unbind() const override;

		virtual void AddVertexBuffer(const Astro::Ref<VertexBuffer>& vertexBuffer) override;
		virtual void SetIndexBuffer(const Astro::Ref<IndexBuffer>& indexBuffer) override;

		virtual const std::vector<Astro::Ref<VertexBuffer>>& GetVertexBuffers() const { return m_VertexBuffers; }
		virtual const Astro::Ref<IndexBuffer>& GetIndexBuffer() const { return m_IndexBuffer; }
	private:
		uint32_t m_RendererID;
		std::vector<Astro::Ref<VertexBuffer>> m_VertexBuffers;
		Astro::Ref<IndexBuffer> m_IndexBuffer;
	};

}