#pragma once
#include <complex>
#include <vector>
#include <string>

class QubitState {
public:
    std::vector<std::complex<double>> state;

    QubitState();
    QubitState(std::complex<double> alpha, std::complex<double> beta);

    void normalize();
    std::string to_string(int precision = 3) const;
    void measure();
};
