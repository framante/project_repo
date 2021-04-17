CXX ?= g++
CXXFLAGS ?= -std=c++17
SRCS=$(wildcard *.cpp)
OBJS=$(SRCS:.cpp=.o)
EXEC=main

all:$(EXEC)
$(OBJS):$(SRCS)
	$(CXX) $(CXXFLAGS) -c $(SRCS)
$(EXEC):$(OBJS)
	$(CXX) -o $(EXEC) $(OBJS)
clean:
	$(RM) $(EXEC) $(OBJS)
