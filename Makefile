CXX = g++
CXXFLAGS = -std=c++17 -Iinclude

SRC = src/main.cpp src/qubit.cpp src/gates.cpp
OUT = quantum_sim.exe

all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT)

clean:
	del $(OUT)