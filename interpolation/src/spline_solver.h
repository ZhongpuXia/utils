#include "spline_segment.h"

#include <vector>
#include "path_point_2d.h"

#ifndef _SRC_SPLINE_SOLVER_H_
#define _SRC_SPLINE_SOLVER_H_

namespace planning {
class SplineSolver {
public:
    SplineSolver() = default;
    ~SplineSolver() = default;

    SplineSegment solve(const PathPoint2D& start, const PathPoint2D& end) const;

private:
    Polynomial hermite_interpolate(double x0, double x1, double x0_dot, double x1_dot) const;
};
} // end of planning
#endif // _SRC_SPLINE_SOLVER_H_
