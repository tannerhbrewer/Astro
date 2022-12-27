#pragma once

#include "Astro/Core/Layer.h"

#include "Astro/Events/ApplicationEvent.h"
#include "Astro/Events/KeyEvent.h"
#include "Astro/Events/MouseEvent.h"

namespace Astro {

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}