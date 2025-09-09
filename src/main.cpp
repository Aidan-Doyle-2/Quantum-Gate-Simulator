#include <iostream>
#include "qubit.hpp"
#include "gates.hpp"

int main() {
    // Single qubit tests
    QubitState q;
    std::cout << "Initial state: " << q.to_string() << "\n";

    q.state = Gates::apply2(Gates::H, q.state);
    q.normalize();
    std::cout << "After H: " << q.to_string() << "\n";

    // Two-qubit test: entanglement
    QubitState q1; // |0>
    QubitState q2; // |0>
    QubitState twoQubit(q1, q2); // |00>
    std::cout << "Initial 2-qubit: " << twoQubit.to_string() << "\n";

    // Apply H on first qubit manually: just modify q1 before tensor product
    q1.state = Gates::apply2(Gates::H, q1.state);
    q1.normalize();
    QubitState entangled(q1, q2);
    entangled.state = Gates::apply4(Gates::CNOT, entangled.state);
    entangled.normalize();

    std::cout << "After H ⊗ I then CNOT: " << entangled.to_string() << "\n";

    return 0;
}
