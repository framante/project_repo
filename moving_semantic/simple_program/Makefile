SRCS=main.cpp
CXX=g++
CXXFLAGS=-std=c++17
OBJS=$(SRCS:.cpp=.o)
EXEC=main


all:$(EXEC)
$(EXEC):$(OBJS)
	$(CXX) -o $(EXEC) $(OBJS) 
$(OBJS):$(SRCS)
	$(CXX) $(CXXFLAGS) -c $(SRCS)
clean:
	$(RM) $(OBJS) $(EXEC)
