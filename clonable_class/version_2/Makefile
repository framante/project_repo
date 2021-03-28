CCX= g++
CXXFLAGS=-std=c++17
EXEC= main


$(EXEC): main.o Composer.o
	$(CXX) $(CXXFLAGS) main.o Composer.o -o $(EXEC)
main.o Compser.o: main.cpp Composer.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp Composer.cpp
all: $(EXEC)
clean:
	rm -f main.o Composer.o $(EXEC)
