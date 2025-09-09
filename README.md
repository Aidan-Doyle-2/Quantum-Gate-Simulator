# Quantum-Gate-Simulator
This is a little simple quantum gate simulator I have built for a single qubit, and is mainly so I start coding in C++ more often.  
It demonstrates how a quantum state can be represented, evolved, and measured using standard gates.

It represents a qubit as a 2-dimensional complex vector, Then implements some common gates (pauli-X, pauli-y, pauli-z, hadamard etc.)
Then it normalizes states, computes measurement probabilities and simulates the quantum measurement with randomness.

To build and run it:
make
./quantum_sim.exe
