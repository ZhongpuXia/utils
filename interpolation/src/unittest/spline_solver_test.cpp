#include "spline_solver.h"

#include "gtest/gtest.h"

namespace planning {

TEST(SplineSolverTest, solve_0_pi) {
    planning::PathPoint2D point_0(0.0, 0.0, 0.0);
    planning::PathPoint2D point_1(0.0, 10.0, 3.1415926);
    planning::SplineSolver solver;
    planning::SplineSegment spline = solver.solve(point_0, point_1);

    EXPECT_FLOAT_EQ(spline(0).x(), 0.0);
    EXPECT_FLOAT_EQ(spline(0).y(), 0.0);
    EXPECT_FLOAT_EQ(spline.theta(0), 0.0);
    EXPECT_FLOAT_EQ(spline(1).x(), 0.0);
    EXPECT_FLOAT_EQ(spline(1).y(), 10.0);
    EXPECT_FLOAT_EQ(spline.theta(1), 3.1415926);
}

TEST(SplineSolverTest, solve_pi2_pi2) {
    planning::PathPoint2D point_0(0.0, 0.0, 1.5708);
    planning::PathPoint2D point_1(10.0, 0.0, -1.5708);
    planning::SplineSolver solver;
    planning::SplineSegment spline = solver.solve(point_0, point_1);

    EXPECT_FLOAT_EQ(spline(0).x(), 0.0);
    EXPECT_FLOAT_EQ(spline(0).y(), 0.0);
    EXPECT_FLOAT_EQ(spline.theta(0), 1.5708);
    EXPECT_FLOAT_EQ(spline(1).x(), 10.0);
    EXPECT_FLOAT_EQ(spline(1).y(), 0.0);
    EXPECT_FLOAT_EQ(spline.theta(1), -1.5708);
}

} // end of planning

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

