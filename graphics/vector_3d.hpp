#ifndef VECTOR_3D_HPP
#define VECTOR_3D_HPP

#include <cmath>

template<class T>
class Vector3D
{
public:
	Vector3D();
	Vector3D(T, T, T);
	~Vector3D();

	T dot(Vector3D<T>);
	Vector3D<T> cross(Vector3D<T>);
	Vector3D norm();

private:

public: // temp
	T x, y, z;
};

template<class T>
Vector3D<T>::Vector3D()
{
	x = 0;
	y = 0;
	z = 0;
}

template<class T>
Vector3D<T>::Vector3D(T xIn, T yIn, T zIn)
{
	x = xIn;
	y = yIn;
	z = zIn;
}

template<class T>
Vector3D<T>::~Vector3D()
{

}

template<class T>
T Vector3D<T>::dot(Vector3D<T> v)
{
	return x * v.x + y * v.y + z * v.z;
}

template<class T>
Vector3D<T> Vector3D<T>::cross(Vector3D<T> v)
{
	Vector3D result(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);

	return result;
}

template<class T>
Vector3D<T> Vector3D<T>::norm()
{
	Vector3D result;

	T magnitude = sqrt(x * x + y * y + z * z);

	result.x = x / magnitude;
	result.y = y / magnitude;
	result.z = z / magnitude;

	return result;
}

#endif