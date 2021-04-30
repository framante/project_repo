CXX ?= g++
CXXFLAGS ?= -std=c++17
EXEC = main
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

PHONY = all clean distclean
all:$(EXEC)
$(OBJS):$(SRCS)
	$(CXX) $(CXXFLAGS) -c $(SRCS)
$(EXEC):$(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) 
clean:
	$(RM) $(OBJS) 
distclean:clean
	$(RM) $(EXEC)
