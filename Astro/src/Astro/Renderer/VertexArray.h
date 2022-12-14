#pragma once

#include <memory>
#include "Astro/Renderer/Buffer.h"

namespace Astro {

	class VertexArray
	{
	public:
		virtual ~VertexArray() {}

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void AddVertexBuffer(const Astro::Ref<VertexBuffer>& vertexBuffer) = 0;
		virtual void SetIndexBuffer(const Astro::Ref<IndexBuffer>& indexBuffer) = 0;

		virtual const std::vector<Astro::Ref<VertexBuffer>>& GetVertexBuffers() const = 0;
		virtual const Astro::Ref<IndexBuffer>& GetIndexBuffer() const = 0;

		static VertexArray* Create();
	};
}