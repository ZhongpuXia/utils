
#ifndef _SRC_POINT_2D_H_
#define _SRC_POINT_2D_H_

namespace planning {
class Point2D {
public:
    Point2D() = default;
    Point2D(double x, double y);
    ~Point2D() = default;

    double x() const;
    void set_x(double x);
    double y() const;
    void set_y(double y);

private:
    double _x = 0;
    double _y = 0;
};

} // end of planning
#endif //_SRC_POINT_2D_H_
