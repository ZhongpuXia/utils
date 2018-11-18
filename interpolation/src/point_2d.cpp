#include "point_2d.h"

namespace planning {
Point2D::Point2D(double x, double y) : _x(x), _y(y) {
}

double Point2D::x() const {
    return _x;
}

void Point2D::set_x(double x) {
    x = _x;
}

double Point2D::y() const {
    return _y;
}

void Point2D::set_y(double y) {
    _y = y;
}
} //namespace planning
