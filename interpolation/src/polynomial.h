#include <vector>

#ifndef _SRC_POLYNOMIAL_H_
#define _SRC_POLYNOMIAL_H_

namespace planning {
class Polynomial {
public:
    Polynomial();
    explicit Polynomial(const std::vector<double>& params);
    ~Polynomial() = default;

    double operator()(double x) const;
    double order() const;
    Polynomial derive() const;
    Polynomial integrate() const;
    Polynomial integrate(double base) const;

    std::vector<double> params() const;
    void set_params(std::vector<double> params);

private:
    std::vector<double> _params;
};
} //end of planning

#endif // _SRC_POLYNOMIAL_H_
