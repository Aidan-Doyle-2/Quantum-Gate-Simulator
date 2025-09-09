#include <iostream>
#include "qubit.hpp"
#include "gates.hpp"

int main() {
    QubitState q;
    std::cout << "Initial state: " << q.to_string() << "\n";

    q.state = Gates::apply(Gates::H, q.state);
    q.normalize();
    std::cout << "After H: " << q.to_string() << "\n";

    q.state = Gates::apply(Gates::X, q.state);
    q.normalize();
    std::cout << "After X: " << q.to_string() << "\n";

    q.state = Gates::apply(Gates::Z, q.state);
    q.normalize();
    std::cout << "After Z: " << q.to_string() << "\n";

    q.state = Gates::apply(Gates::T, q.state);
    q.normalize();
    std::cout << "After T: " << q.to_string() << "\n";

    double p0 = std::norm(q.state[0]);
    double p1 = std::norm(q.state[1]);
    std::cout << "Probabilities: |0⟩=" << p0 << ", |1⟩=" << p1 << "\n";

    q.measure();
}
