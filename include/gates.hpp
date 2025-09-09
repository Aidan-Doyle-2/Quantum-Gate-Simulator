#pragma once
#include <complex>
#include <vector>

using Matrix2x2 = std::vector<std::vector<std::complex<double>>>;
using Matrix4x4 = std::vector<std::vector<std::complex<double>>>;

namespace Gates {
    extern const Matrix2x2 X;
    extern const Matrix2x2 Y;
    extern const Matrix2x2 Z;
    extern const Matrix2x2 H;
    extern const Matrix2x2 S;
    extern const Matrix2x2 T;

    extern const Matrix4x4 CNOT;

    // Single-qubit gates
    std::vector<std::complex<double>> apply2(
        const Matrix2x2 &gate,
        const std::vector<std::complex<double>> &state);

    // Two-qubit gates
    std::vector<std::complex<double>> apply4(
        const Matrix4x4 &gate,
        const std::vector<std::complex<double>> &state);
}
