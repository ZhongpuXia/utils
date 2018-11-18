#include "spline_solver.h"

#include <cmath>
#include <vector>
#include "polynomial.h"

namespace planning {
SplineSegment SplineSolver::solve(const PathPoint2D& start, const PathPoint2D& end) const {
    double x0 = start.x();
    double y0 = start.y();
    double theta0 = start.theta();

    double x1 = end.x();
    double y1 = end.y();
    double theta1 = end.theta();

    double length = 2.5 * std::hypot(x1 - x0, y1 - y0);
    double s0 = sin(theta0) * length;
    double c0 = cos(theta0) * length;
    double s1 = sin(theta1) * length;
    double c1 = cos(theta1) * length;

    Polynomial func_x = hermite_interpolate(x0, x1, c0, c1);
    Polynomial func_y = hermite_interpolate(y0, y1, s0, s1);
    return SplineSegment(func_x, func_y);
}

Polynomial SplineSolver::hermite_interpolate(double x0, double x1, double x0_dot, double x1_dot) const {
    double a = x0_dot + x1_dot + 2.0 * x0 - 2.0 * x1;
    double b = -2.0 * x0_dot - x1_dot - 3.0 * x0 + 3.0 * x1;
    double c = x0_dot;
    double d = x0;
    return Polynomial({a, b, c, d});
}

} // end of planning
