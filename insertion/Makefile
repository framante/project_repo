CXX=g++
CXXFLAGS=-std=c++17
EXEC=main
SRCS=main.cpp
OBJS=$(SRCS:.cpp=.o)

all: $(EXEC)


$(OBJS): $(SRCS)
	$(CXX) $(CXXFLAGS) -c $(SRCS)
$(EXEC): main.o
	$(CXX) $(OBJS) -o $(EXEC)
clean:
	$(RM) $(EXEC) $(OBJS)
