#ifndef OBJECT_3D_HPP
#define OBJECT_3D_HPP

#include <SFML/Graphics.hpp>
#include <vector>
#include "component_3d.hpp"

using namespace std;
using namespace sf;

class Object3D
{
public:
	Object3D();
	~Object3D();

	Component3D at(int);
	int size();

	void add(Component3D);
	Component3D& createComponent();

private:
	vector<Component3D> components;
};

Object3D::Object3D()
{
	
}

Object3D::~Object3D()
{

}

Component3D Object3D::at(int index)
{
	return components.at(index);
}

int Object3D::size()
{
	return components.size();
}

void Object3D::add(Component3D component)
{
	components.push_back(component);
}

Component3D& Object3D::createComponent()
{
	Component3D newComponent;

	components.push_back(newComponent);

	return components.at(components.size() - 1);
}


#endif