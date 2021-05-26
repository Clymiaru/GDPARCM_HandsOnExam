#pragma once
class AComponent;
class Event;

class Entity
{
public:
	explicit Entity(StringRef name);

	template <class Component, typename ...Args>
	Component& BindComponent(Args&& ... args);

	template <class Component>
    Component* GetComponent();
	
	StringRef GetName() const;
	void SetName(StringRef name);

private:
	String m_Name;
	List<AComponent*> m_ComponentList;
	HashTable<String, AComponent*> m_ComponentTable;
};

template <class Component, typename ...Args>
Component& Entity::BindComponent(Args&& ...args)
{
	Component* component = new Component(*this, std::forward<Args>(args) ...);
	m_ComponentList.push_back(component);
	m_ComponentTable[Component::GetComponentName()] = component;

	return *component;
}

template <class Component>
Component* Entity::GetComponent()
{
	return static_cast<Component*>(m_ComponentTable[Component::GetComponentName()]);
}
