# BSpline Curve Drawing

This project provides a dynamic link library (DLL) for a 3D B-spline curve using OpenGL and Qt. The DLL includes a `BSpline` class that allows the creation and evaluation of a B-spline curve based on control points.

## Contents

- [BSpline.h](#bsplineh)
- [BSpline.cpp](#bsplinecpp)

## BSpline.h

This header file defines the `BSpline` class, which encapsulates the functionality for creating and evaluating a 3D B-spline curve. Key functionalities include:

- Initializing the B-spline with control points.
- Computing B-spline basis functions.
- Evaluating the B-spline curve at a given parameter.
- Drawing the B-spline curve.

## BSpline.cpp

This source file contains the implementation of the `BSpline` class. It includes functions for:

- Initializing the B-spline with control points and generating a simple knot vector.
- Computing B-spline basis functions using the Cox-de Boor recursion formula.
- Evaluating the 3D B-spline curve at a specified parameter.
- Drawing the B-spline curve by evaluating it at various parameter values.

## Usage

To use the BSpline DLL, follow these steps:

1. **Include the necessary files**: Include the `BSpline.h` header file in your project.

```cpp
#include "BSpline.h"
```
2. **Create an instance of the BSpline class:**
```cpp
Point3D p0(0.0, 0.0, 0.0);
Point3D p1(1.0, 1.0, 0.0);
Point3D p2(2.0, 0.0, 0.0);
Point3D p3(3.0, 1.0, 0.0);
BSpline bspline(p0, p1, p2, p3);
```
3. **Initialize and render the B-spline curve in OpenGLWIndow.cpp:**
```cpp
floatList vertices;
floatList colors;
bspline.drawCurveBspline(vertices, colors);
// Render the vertices and colors using OpenGL
```
