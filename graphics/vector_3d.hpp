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

	void set(T, T, T);
	void setSpherical(T, T, T);

	T dot(Vector3D<T>);
	Vector3D<T> cross(Vector3D<T>);
	Vector3D normalise();

	Vector3D<T> operator + (Vector3D);
	Vector3D<T> operator - (Vector3D);
	Vector3D<T> operator * (T);
	Vector3D<T> operator / (T);

	void toSpherical();
	void toCartesian();

private:

public: // temp
	T x, y, z;
	T rho, phi, theta;
};

template<class T>
Vector3D<T>::Vector3D()
{
	set(0, 0, 0);
	setSpherical(1, 0, 0);
}

template<class T>
Vector3D<T>::Vector3D(T xIn, T yIn, T zIn)
{
	set(xIn, yIn, zIn);
}

template<class T>
Vector3D<T>::~Vector3D()
{

}

template<class T>
void Vector3D<T>::set(T xIn, T yIn, T zIn)
{
	x = xIn;
	y = yIn;
	z = zIn;
}

template<class T>
void Vector3D<T>::setSpherical(T rhoIn, T phiIn, T thetaIn)
{
	rho = rhoIn;
	phi = phiIn;
	theta = thetaIn;
}

template<class T>
T Vector3D<T>::dot(Vector3D<T> v)
{
	return x * v.x + y * v.y + z * v.z;
}

template<class T>
Vector3D<T> Vector3D<T>::cross(Vector3D<T> v)
{
	Vector3D<T> result(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);

	return result;
}

template<class T>
Vector3D<T> Vector3D<T>::normalise()
{
	Vector3D<T> result;

	T magnitude = sqrt(x * x + y * y + z * z);

	result.x = x / magnitude;
	result.y = y / magnitude;
	result.z = z / magnitude;

	return result;
}

template<class T>
Vector3D<T> Vector3D<T>::operator + (Vector3D<T> v)
{
	Vector3D<T> result;

	result.x = x + v.x;
	result.y = y + v.y;
	result.z = z + v.z;

	result.rho = rho + v.rho;
	result.phi = phi + v.phi;
	result.theta = theta + v.theta;

	return result;
}

template<class T>
Vector3D<T> Vector3D<T>::operator - (Vector3D<T> v)
{
	Vector3D<T> result;

	result.x = x - v.x;
	result.y = y - v.y;
	result.z = z - v.z;

	result.rho = rho - v.rho;
	result.phi = phi - v.phi;
	result.theta = theta - v.theta;

	return result;
}

template<class T>
Vector3D<T> Vector3D<T>::operator * (T scalar)
{
	Vector3D<T> result;

	result.x = x * scalar;
	result.y = y * scalar;
	result.z = z * scalar;

	return result;
}

template<class T>
Vector3D<T> Vector3D<T>::operator / (T scalar)
{
	Vector3D<T> result;

	result.x = x / scalar;
	result.y = y / scalar;
	result.z = z / scalar;

	return result;
}

template<class T>
void Vector3D<T>::toSpherical()
{
	rho = sqrt(x * x + y * y + z * z);
	phi = atan(y / z);
	theta = atan(sqrt(z * z + y * y) / -x);
}

template<class T>
void Vector3D<T>::toCartesian()
{
	z = rho * sin(theta) * cos(phi);
	y = rho * sin(theta) * sin(phi);
	x = -rho * cos(theta);
}

/*template<class T>
void Vector3D<T>::toSpherical()
{
	rho = sqrt(x * x + y * y + z * z);
	phi = atan(y / x);
	theta = atan(sqrt(x * x + y * y) / z);
}

template<class T>
void Vector3D<T>::toCartesian()
{
	x = rho * sin(theta) * cos(phi);
	y = rho * sin(theta) * sin(phi);
	z = rho * cos(theta);
}*/

#endif