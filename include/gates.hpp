#pragma once
#include <complex>
#include <vector>

using Matrix2x2 = std::vector<std::vector<std::complex<double>>>;

namespace Gates {
    extern const Matrix2x2 X;
    extern const Matrix2x2 Y;
    extern const Matrix2x2 Z;
    extern const Matrix2x2 H;
    extern const Matrix2x2 S;
    extern const Matrix2x2 T;

    std::vector<std::complex<double>> apply(const Matrix2x2 &gate,
                                            const std::vector<std::complex<double>> &state);
}
