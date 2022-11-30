#pragma once

#include "Astro/Layer.h"

#include "Astro/Events/ApplicationEvent.h"
#include "Astro/Events/KeyEvent.h"
#include "Astro/Events/MouseEvent.h"

namespace Astro {

	class ASTRO_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}