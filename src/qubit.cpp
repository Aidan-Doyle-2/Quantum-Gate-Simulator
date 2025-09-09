#include "qubit.hpp"
#include <sstream>
#include <iomanip>
#include <cmath>
#include <random>
#include <iostream>
#include <bitset>

// Single qubit default |0>
QubitState::QubitState() {
    state = {1.0, 0.0};
}

// Single qubit with amplitudes
QubitState::QubitState(std::complex<double> alpha, std::complex<double> beta) {
    state = {alpha, beta};
    normalize();
}

// Two-qubit tensor product
QubitState::QubitState(const QubitState &q1, const QubitState &q2) {
    state.resize(q1.state.size() * q2.state.size());
    int k = 0;
    for (auto a : q1.state) {
        for (auto b : q2.state) {
            state[k++] = a * b;
        }
    }
    normalize();
}

void QubitState::normalize() {
    double norm = 0.0;
    for (auto &amp : state) {
        norm += std::norm(amp);
    }
    norm = std::sqrt(norm);
    if (norm > 0) {
        for (auto &amp : state) {
            amp /= norm;
        }
    }
}

std::string QubitState::to_string(int precision) const {
    std::ostringstream out;
    out << std::fixed << std::setprecision(precision);

    if (state.size() == 2) { // single qubit
        out << state[0].real() << "|0> + " << state[1].real() << "|1>";
    } else if (state.size() == 4) { // two qubits
        out << state[0].real() << "|00> + "
            << state[1].real() << "|01> + "
            << state[2].real() << "|10> + "
            << state[3].real() << "|11>";
    }
    return out.str();
}

void QubitState::measure() {
    std::vector<double> probs;
    for (auto &amp : state) {
        probs.push_back(std::norm(amp));
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::discrete_distribution<> dist(probs.begin(), probs.end());

    int result = dist(gen);

    // Collapse state
    state.assign(state.size(), 0.0);
    state[result] = 1.0;

    std::cout << "Measured: |" << std::bitset<2>(result) << "> (p=" << probs[result] << ")\n";
}
