CXX=g++
CXXFLAGS=-std=c++17
EXEC=main

all: $(EXEC)


main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp
$(EXEC): main.o
	$(CXX) main.o -o $(EXEC)
clean:
	rm -f main.o $(EXEC)
