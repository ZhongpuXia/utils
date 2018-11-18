#include <vector>

#include "polynomial.h"
#include "point_2d.h"

#ifndef _SRC_SPLINE_SEGMENT_H_
#define _SRC_SPLINE_SEGMENT_H_

namespace planning {
class SplineSegment {
public:
    SplineSegment() = default;
    SplineSegment(const std::vector<double>& params_x, const std::vector<double>& params_y);
    SplineSegment(const Polynomial& func_x, const Polynomial& func_y);
    ~SplineSegment() = default;

    Point2D operator()(double t) const;
    double x(double t) const;
    double y(double t) const;
    double theta(double t) const;
    double kappa(double t) const;

    std::size_t order() const;

    const Polynomial& func_x() const;
    const Polynomial& func_y() const;

private:
    Polynomial _func_x;
    Polynomial _func_y;
};
} // end of planning

#endif // _SRC_SPLINE_SEG_H_
