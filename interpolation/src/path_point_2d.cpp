#include "path_point_2d.h"

namespace planning {

PathPoint2D::PathPoint2D(double x, double y, double theta) :
        Point2D(x, y), _theta(theta) {
}

PathPoint2D::PathPoint2D(double x, double y, double theta, double kappa) :
        Point2D(x, y), _theta(theta), _kappa(kappa) {
}

double PathPoint2D::theta() const {
    return _theta;
}

void PathPoint2D::set_theta(double theta) {
    theta = _theta;
}

double PathPoint2D::kappa() const {
    return _kappa;
}

void PathPoint2D::set_kappa(double kappa) {
    _kappa = kappa;
}

} //namespace planning
