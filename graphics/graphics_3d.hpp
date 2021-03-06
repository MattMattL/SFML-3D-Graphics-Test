#ifndef GRAPHICS_3D_HPP
#define GRAPHICS_3D_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "object_3d.hpp"
#include "vector_3d.hpp"

class Graphics3D
{
public:
	Graphics3D();
	~Graphics3D();

	void addObject(Object3D);

	void runScreen();

private:
	float screenWidth, screenHeight;
	float cameraX, cameraY, cameraZ;
	float screenDistance;

	vector<Object3D> objects;

	ConvexShape getTranslatedComponent(Component3D component);
};

Graphics3D::Graphics3D()
{
	screenWidth = 1080;
	screenHeight = 720;
	cameraX = 0;
	cameraY = 0;
	cameraZ = 0;
	screenDistance = 300;
}

Graphics3D::~Graphics3D()
{

}

void Graphics3D::addObject(Object3D obj)
{
	objects.push_back(obj);
}

void Graphics3D::runScreen()
{
	RenderWindow window(VideoMode(1080, 720), "Graphics3D :: runScreen() - test");
	
	while(window.isOpen())
	{
		Event event;

		while(window.pollEvent(event))
		{
			switch(event.type)
			{
				case Event::Closed:
					window.close();
					break;

				case Event::Resized:
					cout << event.size.width << " x " << event.size.height << endl;
					break;

				case Event::TextEntered:
					switch(event.text.unicode)
					{
						case 'w': cameraX -= 10; break;
						case 's': cameraX += 10; break;
						case 'a': cameraY -= 10; break;
						case 'd': cameraY += 10; break;
						case 'q': cameraZ += 10; break;
						case 'e': cameraZ -= 10; break;
					}

					window.clear();

					for(int i=0; i<objects.size(); ++i)
					{
						for(int j=0; j<objects.at(i).size(); j++)
						{
							window.draw(getTranslatedComponent(objects.at(i).at(j)));	
						}
					}

					window.display();

					break;

				default:
					break;
			}
		}
	}
}

ConvexShape Graphics3D::getTranslatedComponent(Component3D component)
{
	ConvexShape polygon(4);

	int index = 0;

	for(int i=0; i<component.size(); ++i)
	{
		float a = component.at(i).x;
		float b = component.at(i).y;
		float c = component.at(i).z;
		float p = cameraX;
		float q = cameraY;
		float r = cameraZ;
		float z = screenDistance;

		float t = (z - r) / (c - r);
		float x = t * (b - q) + q + screenWidth / 2;
		float y = t * (a - p) + p + screenHeight / 2;

		Vector2f screenVec(x, y);

		polygon.setPoint(index++, screenVec);
	}

	polygon.setFillColor(component.getColour());

	return polygon;
}

#endif