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
	float screenDistance;
	Vector3D<float> cameraPos, cameraAngle;

	vector<Object3D> objects;

	ConvexShape getTranslatedComponent(Component3D component);
};

Graphics3D::Graphics3D()
{
	screenWidth = 1080;
	screenHeight = 720;
	cameraPos.set(0, 0, -200);
	cameraAngle.setSpherical(1, 0, 0);
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
					cout << event.text.unicode << endl;
					switch(event.text.unicode)
					{
						case 'w': cameraPos.y -= 10; break;
						case 's': cameraPos.y += 10; break;
						case 'a': cameraPos.x -= 10; break;
						case 'd': cameraPos.x += 10; break;
						case 'r': cameraPos.z += 10; break;
						case 'f': cameraPos.z -= 10; break;

						// case 'i': cameraAngle.theta += 0.1; break;
						// case 'k': cameraAngle.theta -= 0.1; break;
						// case 'j': cameraAngle.phi += 0.1; break;
						// case 'l': cameraAngle.phi -= 0.1; break;
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
		float p = cameraPos.x;
		float q = cameraPos.y;
		float r = cameraPos.z;
		float z = screenDistance;

		// apply camera rotation
		// Vector3D<float> translated = component.at(i) - cameraPos;

		// printf("tran: %6.1f, %6.1f, %6.1f\n", translated.x, translated.y, translated.z);
		
		// translated.toSpherical();
		// translated = translated + cameraAngle;
		
		// translated.toCartesian();
		// translated = translated + cameraPos;

		// a = translated.x;
		// b = translated.y;
		// c = translated.z;

		// printf("comp: %6.1f, %6.1f, %6.1f\n", component.at(i).x, component.at(i).y, component.at(i).z);
		// printf("tran: %6.1f, %6.1f, %6.1f\n", translated.x, translated.y, translated.z);

		// calculate projected coordinates
		float t = (z - r) / (c - r);
		float x = t * (a - p) + p + screenWidth / 2;
		float y = t * (b - q) + q + screenHeight / 2;
		

		// register translated coordinates
		Vector2f screenVec(x, y);

		polygon.setPoint(index++, screenVec);
	}

	polygon.setFillColor(component.getColour());

	return polygon;
}

#endif