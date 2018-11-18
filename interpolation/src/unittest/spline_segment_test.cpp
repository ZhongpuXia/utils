#include "spline_segment.h"

#include "gtest/gtest.h"

namespace planning {

TEST(SplineSegmentTest, zero_order) {
    SplineSegment spline_point({0.0}, {1.0});  // [0.0, 0.0]
    EXPECT_EQ(spline_point(0.0).x(), 0.0);
    EXPECT_EQ(spline_point(0.0).y(), 1.0);
    EXPECT_EQ(spline_point(1.0).x(), 0.0);
    EXPECT_EQ(spline_point(1.0).y(), 1.0);
    EXPECT_EQ(spline_point.x(0.0), 0.0);
    EXPECT_EQ(spline_point.y(0.0), 1.0);
    EXPECT_EQ(spline_point.x(1.0), 0.0);
    EXPECT_EQ(spline_point.y(1.0), 1.0);
    EXPECT_EQ(spline_point.order(), 0);
    EXPECT_EQ(spline_point.theta(0.0), 0);
    EXPECT_EQ(spline_point.theta(1.0), 0);
    EXPECT_EQ(spline_point.kappa(0.0), 0);
    EXPECT_EQ(spline_point.kappa(1.0), 0);
}

TEST(SplineSegmentTest, first_order) {
    SplineSegment spline_point({2.0, 0.0}, {1.0});  // [2t + 0, 1.0]
    EXPECT_EQ(spline_point(0.0).x(), 0.0);
    EXPECT_EQ(spline_point(0.0).y(), 1.0);
    EXPECT_EQ(spline_point(0.5).x(), 1.0);
    EXPECT_EQ(spline_point(0.5).y(), 1.0);
    EXPECT_EQ(spline_point(1.0).x(), 2.0);
    EXPECT_EQ(spline_point(1.0).y(), 1.0);

    EXPECT_EQ(spline_point.x(0.0), 0.0);
    EXPECT_EQ(spline_point.y(0.0), 1.0);
    EXPECT_EQ(spline_point.x(0.5), 1.0);
    EXPECT_EQ(spline_point.y(0.5), 1.0);
    EXPECT_EQ(spline_point.x(1.0), 2.0);
    EXPECT_EQ(spline_point.y(1.0), 1.0);
    EXPECT_EQ(spline_point.order(), 1);
    EXPECT_EQ(spline_point.theta(0.0), 0);
    EXPECT_EQ(spline_point.theta(1.0), 0);
    EXPECT_EQ(spline_point.kappa(0.0), 0);
    EXPECT_EQ(spline_point.kappa(1.0), 0);
}

TEST(SplineSegmentTest, second_order) {
    SplineSegment spline_point({1.0, 0.0, 0.0}, {1.0, 1.0, 0.0});  // [t^2,  t^2 + t]
    EXPECT_EQ(spline_point(0.0).x(), 0.0);
    EXPECT_EQ(spline_point(0.0).y(), 0.0);
    EXPECT_EQ(spline_point(0.5).x(), 0.25);
    EXPECT_EQ(spline_point(0.5).y(), 0.75);
    EXPECT_EQ(spline_point(1.0).x(), 1.0);
    EXPECT_EQ(spline_point(1.0).y(), 2.0);

    EXPECT_EQ(spline_point.x(0.0), 0.0);
    EXPECT_EQ(spline_point.y(0.0), 0.0);
    EXPECT_EQ(spline_point.x(0.5), 0.25);
    EXPECT_EQ(spline_point.y(0.5), 0.75);
    EXPECT_EQ(spline_point.x(1.0), 1.0);
    EXPECT_EQ(spline_point.y(1.0), 2.0);
    EXPECT_EQ(spline_point.order(), 2);
    EXPECT_NEAR(spline_point.theta(0.0), 1.570, 0.01);
    EXPECT_NEAR(spline_point.theta(0.5), 1.107, 0.01);
    EXPECT_NEAR(spline_point.theta(1.0), 0.983, 0.01);
    EXPECT_NEAR(spline_point.kappa(0.0), 2.000, 0.01);
    EXPECT_NEAR(spline_point.kappa(0.5), 0.179, 0.01);
    EXPECT_NEAR(spline_point.kappa(1.0), 0.0426, 0.01);
}

} // end of planning

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

