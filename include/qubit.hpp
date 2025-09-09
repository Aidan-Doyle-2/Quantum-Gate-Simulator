#pragma once
#include <complex>
#include <vector>
#include <string>

class QubitState {
public:
    std::vector<std::complex<double>> state;  // 2 for 1 qubit, 4 for 2 qubits

    // Constructors
    QubitState();  // default |0>
    QubitState(std::complex<double> alpha, std::complex<double> beta); // single qubit
    QubitState(const QubitState &q1, const QubitState &q2); // tensor product

    void normalize();
    std::string to_string(int precision = 3) const;
    void measure();
};
