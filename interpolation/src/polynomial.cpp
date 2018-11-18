#include "polynomial.h"

#include <limits>
#include <cmath>
#include "glog/logging.h"

namespace planning {

Polynomial::Polynomial() : _params(1, 0.0) {
}

Polynomial::Polynomial(const std::vector<double>& params) {
    CHECK_GT(params.size(), 0);
    _params.reserve(params.size());
    bool is_zero = true;
    for (double p : params) {
        if (is_zero) {
            is_zero = std::fabs(p) < std::numeric_limits<double>::epsilon();
            if (is_zero) {
                continue;
            }
        }
        _params.push_back(p);
    }
    if (_params.size() < 1) {
        _params.push_back(0.0);
    }
}

double Polynomial::operator()(double x) const {
    double result = 0.0;
    for (const auto& p: _params) {
        result = result * x + p;
    }
    return result;
}

double Polynomial::order() const {
    return _params.size() - 1;
}

Polynomial Polynomial::derive() const {
    std::vector<double> new_params(_params.size() - 1);
    for (std::size_t i = 0; i < _params.size() - 1; ++i) {
        new_params[i] = (_params.size() - 1 - i) * _params[i];
    }
    if (new_params.size() < 1) {
        new_params.resize(1, 0.0);
    }
    return Polynomial(new_params);
}

Polynomial Polynomial::integrate() const {
    return integrate(0.0);
}

Polynomial Polynomial::integrate(double base) const {
    std::vector<double> new_params(_params.size() + 1);
    for(std::size_t i = 0; i < _params.size(); ++i) {
        new_params[i] = 1.0 / (_params.size() - i) * _params[i];
    }
    new_params[_params.size()] = base;
    return Polynomial(new_params);
}

} // end of planning
