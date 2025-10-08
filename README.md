# Quantum Gate Simulator 🧩

A lightweight C++ program that simulates the fundamentals of quantum computation using single- and two-qubit systems.  
It lets you construct and execute simple quantum circuits directly from the command line using familiar quantum gates.

## 💡 Overview
This project was built as a practice exercise to explore how quantum logic can be implemented at a low level without external frameworks.  
Each qubit is represented as a complex vector, and gates are defined as unitary matrices. Quantum evolution is handled through matrix–vector 
multiplication with normalization and probability tracking at every step.

Example usage:

./quantum_sim.exe --circuit "H CNOT" --two-qubits

This prepares a maximally entangled Bell state by applying a Hadamard gate to the first qubit followed by a CNOT.

## ⚙️ Features
- Command-line interface for building and running circuits  
- Support for key quantum gates (X, Y, Z, H, S, T, CNOT)  
- Matrix–vector evolution with normalization  
- Modular directory structure (`src/`, `include/`, `Makefile`)  
- Clean version control setup with `.gitignore`  

## 🚀 Future Additions
- Bloch sphere visualization  
- Repeated measurements with histogram statistics  
- Unit tests using Catch2  

## 🧠 Why I Built This
This project was my way of translating my understanding of quantum information theory into efficient C++ code.  
It bridges my academic background in quantum computing with my interest in performance-oriented system design.
