#include "qubit.hpp"
#include <sstream>
#include <iomanip>
#include <cmath>
#include <random>
#include <iostream>

QubitState::QubitState() {
    state = {1.0, 0.0}; // |0>
}

QubitState::QubitState(std::complex<double> alpha, std::complex<double> beta) {
    state = {alpha, beta};
    normalize();
}

void QubitState::normalize() {
    double norm = std::sqrt(std::norm(state[0]) + std::norm(state[1]));
    if (norm > 0) {
        state[0] /= norm;
        state[1] /= norm;
    }
}

std::string QubitState::to_string(int precision) const {
    std::ostringstream out;
    out << std::fixed << std::setprecision(precision);
    out << state[0].real() << "|0⟩ + " << state[1].real() << "|1⟩";
    return out.str();
}

void QubitState::measure() {
    double p0 = std::norm(state[0]);
    double p1 = std::norm(state[1]);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::bernoulli_distribution d(p1);

    int result = d(gen);
    if (result == 0) {
        state = {1.0, 0.0};
        std::cout << "Measured: |0⟩ (p=" << p0 << ")\n";
    } else {
        state = {0.0, 1.0};
        std::cout << "Measured: |1⟩ (p=" << p1 << ")\n";
    }
}
