#include "stdafx.h"
#include "Circle.h"
#include<QVector>

Circle::Circle()
{

}

Circle::Circle(Point3D gCenter, float gRadius) 
	:	center(gCenter),
		radius(gRadius)
{
	makeCircle();
}

Circle::~Circle()
{

}

void Circle::makeCircle()
{
	mPoints.push_back(center);

	for (int i = 0; i < sSegments; ++i)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(sSegments);
		float x = radius * cosf(theta);
		float y = radius * sinf(theta);

		mPoints.push_back(Point3D(center.x() + x, center.y() + y, 0.0));
	}
}

void Circle::colorCicle(QVector<float>& mVertices, QVector<float>& mColors, Point3D uColor)
{
	mVertices.clear();
	mColors.clear();
	color = uColor;
		for (auto point : mPoints)
		{
			mVertices << point.x() << point.y();
			mColors << color.x() / 255.0f << color.y() / 255.0f << color.z() / 255.0f;

			mVertices << center.x() << center.y();
			mColors << color.x() / 255.0f << color.y() / 255.0f << color.z() / 255.0f;
		}
}