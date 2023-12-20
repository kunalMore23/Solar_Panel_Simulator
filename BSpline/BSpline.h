#include "pch.h"
#include "Point3D.h"
#include<vector>

using floatList = std::vector<float>;

// This class is exported from the dll
class BSPLINE_API BSpline {
public:
    BSpline(Point3D inP0, Point3D inP1, Point3D inP2, Point3D inP3);
    ~BSpline();

    double basisFunction(int i, int k, double t);
    void   evaluate(double t, floatList& mVertices, floatList& mColors);
    void   drawCurveBspline(floatList& mVertices, floatList& mColors);

private:
    std::vector<double> knots;
    std::vector<Point3D> controlPoints;
    int degree;

    Point3D mP0;
    Point3D mP1;
    Point3D mP2;
    Point3D mP3;
};

extern BSPLINE_API int nBSpline;

BSPLINE_API int fnBSpline(void);
