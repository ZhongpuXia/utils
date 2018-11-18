#include "point_2d.h"

#ifndef _SRC_PATH_POINT_2D_H_
#define _SRC_PATH_POINT_2D_H_

namespace planning {

class PathPoint2D : public Point2D {
public:
    PathPoint2D() = default;
    PathPoint2D(double x, double y, double theta);
    PathPoint2D(double x, double y, double theta, double kappa);

    double theta() const;
    void set_theta(double theta);
    double kappa() const;
    void set_kappa(double kappa);

private:
    double _theta = 0;
    double _kappa = 0;
};

} // end of planning
#endif //_SRC_PATH_POINT_2D_H_
