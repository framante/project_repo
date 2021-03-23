CCX=g++ -std=c++17
EXEC=main


$(EXEC): main.o Composer.o
	$(CXX) main.o Composer.o -o $(EXEC)
main.o Compser.o: main.cpp Composer.cpp
	$(CXX) -c main.cpp Composer.cpp
all: $(EXEC)
clean:
	rm main.o Composer.o $(EXEC)
