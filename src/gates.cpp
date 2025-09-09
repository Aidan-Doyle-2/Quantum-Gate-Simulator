#include "gates.hpp"
#include <cmath>

// Define PI
const double PI = 3.14159265358979323846;

const Matrix2x2 Gates::X = {{0, 1}, {1, 0}};
const Matrix2x2 Gates::Y = {{0, {-0.0, 1.0}}, {{0.0, -1.0}, 0}};
const Matrix2x2 Gates::Z = {{1, 0}, {0, -1}};
const Matrix2x2 Gates::H = {
    {1/std::sqrt(2), 1/std::sqrt(2)},
    {1/std::sqrt(2), -1/std::sqrt(2)}
};
const Matrix2x2 Gates::S = {{1, 0}, {0, {0.0, 1.0}}};
const Matrix2x2 Gates::T = {
    {1, 0},
    {0, {std::cos(PI/4), std::sin(PI/4)}}
};

// CNOT gate (control = qubit 0, target = qubit 1)
const Matrix4x4 Gates::CNOT = {
    {1,0,0,0},
    {0,1,0,0},
    {0,0,0,1},
    {0,0,1,0}
};

// Apply 2x2 gate
std::vector<std::complex<double>> Gates::apply2(
    const Matrix2x2 &gate,
    const std::vector<std::complex<double>> &state)
{
    std::vector<std::complex<double>> result(2, 0);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            result[i] += gate[i][j] * state[j];
        }
    }
    return result;
}

// Apply 4x4 gate
std::vector<std::complex<double>> Gates::apply4(
    const Matrix4x4 &gate,
    const std::vector<std::complex<double>> &state)
{
    std::vector<std::complex<double>> result(4, 0);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i] += gate[i][j] * state[j];
        }
    }
    return result;
}
