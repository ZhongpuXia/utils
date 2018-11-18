#include <cmath>
#include <limits>
#include "spline_segment.h"
#include "glog/logging.h"

namespace planning {
SplineSegment::SplineSegment(const std::vector<double>& params_x, const std::vector<double>& params_y):
        _func_x(params_x), _func_y(params_y){
}

SplineSegment::SplineSegment(const Polynomial& func_x, const Polynomial& func_y) :
        _func_x(func_x), _func_y(func_y) {
}

Point2D SplineSegment::operator()(double t) const {
    CHECK_GE(t, 0.0);
    CHECK_LE(t, 1.0);
    double x = _func_x(t);
    double y = _func_y(t);
    return Point2D(x, y);
}

double SplineSegment::x(double t) const {
    CHECK_GE(t, 0.0);
    CHECK_LE(t, 1.0);
    return _func_x(t);
}

double SplineSegment::y(double t) const {
    CHECK_GE(t, 0.0);
    CHECK_LE(t, 1.0);
    return _func_y(t);
}

double SplineSegment::theta(double t) const {
    CHECK_GE(t, 0.0);
    CHECK_LE(t, 1.0);
    return atan2(_func_y.derive()(t), _func_x.derive()(t));
}

double SplineSegment::kappa(double t) const {
    CHECK_GE(t, 0.0);
    CHECK_LE(t, 1.0);
    double y_d = _func_y.derive()(t);
    double y_dd = _func_y.derive().derive()(t);
    double x_d = _func_x.derive()(t);
    double x_dd = _func_x.derive().derive()(t);
    double num = std::fabs(y_d * x_dd - x_d * y_dd);
    double den = std::pow(std::hypot(x_d, y_d), 3);
    if (num < std::numeric_limits<double>::epsilon()) {
        return 0.0;
    }
    CHECK_GT(den, std::numeric_limits<double>::epsilon());
    return num / den;
}

std::size_t SplineSegment::order() const {
    return _func_x.order() > _func_y.order() ? _func_x.order() : _func_y.order();
}

const Polynomial& SplineSegment::func_x() const{
    return _func_x;
}

const Polynomial& SplineSegment::func_y() const{
    return _func_y;
}

} // end of planning
