CXX=g++
CXXFLAGS=-std=c++17
EXEC=main
SRCS=main.cpp
OBJS=$(SRCS:.cpp=.o)

GNEGNE=$(wildcard *.cpp~)
GNIGNI=$(wildcard *.hpp~)

all:$(EXEC)
$(EXEC):$(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)
$(OBJS):$(SRCS)
	$(CXX) $(CXXFLAGS) -c $(SRCS) 
clean:
	$(RM) $(EXEC) $(OBJS) $(GNEGNE) $(GNIGNI) 
