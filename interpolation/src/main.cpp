#include <iostream>
#include <fstream>
#include <vector>

#include "path_point_2d.h"
#include "spline_solver.h"
#include "glog/logging.h"

int main(int argc, char* argv[]) {
    ::google::InitGoogleLogging(argv[0]);
    FLAGS_colorlogtostderr=true;
    FLAGS_minloglevel = google::GLOG_INFO;
    google::SetLogDestination(google::GLOG_INFO, "./log");
    google::ParseCommandLineFlags(&argc, &argv, true);

    planning::PathPoint2D point_0(0.0, 0.0, 0.0);
    planning::PathPoint2D point_1(0.0, 10.0, 3.1415926);
    planning::SplineSolver solver;
    planning::SplineSegment spline = solver.solve(point_0, point_1);

    std::ofstream ofs("results.txt", std::ofstream::out);
    if (!ofs.is_open()) {
        std::cout << "Fail to open file";
        return 1;
    }

    double unit_t = 0.01;
    std::size_t length = static_cast<std::size_t>(1.0 / unit_t) + 1;
    std::vector<double> x_vec;
    x_vec.reserve(length);
    std::vector<double> y_vec;
    y_vec.reserve(length);
    std::vector<double> theta_vec;
    theta_vec.reserve(length);
    std::vector<double> kappa_vec;
    kappa_vec.reserve(length);

    ofs << "start point: " << point_0.x() << ", " << point_0.y() << ", " << point_0.theta() << std::endl;
    ofs << "end point: " << point_1.x() << ", " << point_1.y() << ", " << point_1.theta() << std::endl;
    for (double t = 0.0; t <= 1.0; t += unit_t) {
        x_vec.push_back(spline.x(t));
        y_vec.push_back(spline.y(t));
        theta_vec.push_back(spline.theta(t));
        kappa_vec.push_back(spline.kappa(t));
        ofs << t << ", " << x_vec.back() << ", " << y_vec.back() << ", ";
        ofs << theta_vec.back() << ", " << kappa_vec.back() << std::endl;
    }
    ofs << 1.0 << ", " << spline.x(1.0) << ", " << spline.y(1.0) << ", ";
    ofs << spline.theta(1.0) << ", " << spline.kappa(1.0) << std::endl;
    ofs.close();
    return 0;
}
