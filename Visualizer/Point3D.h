#pragma once
#include<vector>

class Point3D
{
public:
	Point3D();
	Point3D(float uX, float uY, float uZ);
	~Point3D();

	float x();
	float y();
	float z();

	void setX(float uX);
	void setY(float uY);
	void setZ(float uZ);

private:
	float mX;
	float mY;
	float mZ;
};