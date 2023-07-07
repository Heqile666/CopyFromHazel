#include "hzpch.h"
#include "LayerStack.h"

namespace Hazel {
	LayerStack::LayerStack()
	{
		
	}

	LayerStack::~LayerStack()
	{
		for (Layer* layer : m_Layers )
		{
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer)
	{
		m_Layers.emplace(m_LayerInsertIndex + m_Layers.begin(), layer);
		m_LayerInsertIndex++;
	}

	void LayerStack::PushOverlay(Layer* layer)
	{
		m_Layers.emplace_back(layer);
		layer->OnAttach();
	}

	void LayerStack::PopLayer(Layer* layer)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay)
	{
		auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
		}
	}
}