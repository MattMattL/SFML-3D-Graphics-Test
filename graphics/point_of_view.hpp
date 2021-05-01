#ifndef POINT_OF_VIEW_HPP
#define POINT_OF_VIEW_HPP

#include "vector_3d.hpp"

template<class T>
class PointOfView
{
public:
	PointOfView();
	PointOfView();
	~PointOfView();

private:

	Vector3D<T> vecStart, vecEnd;
};

template<class T>
PointOfView::PointOfView()
{
	
}

template<class T>
PointOfView::~PointOfView()
{

}

#endif