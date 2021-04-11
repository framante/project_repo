CXX=g++
CXXFLAGS=-std=c++17
EXEC=main
SRCS=main.cpp
HEADS=Foo.cpp
HEADOBJS=$(HEADS:.cpp=.o)
OBJS=$(SRCS:.cpp=.o)
GNEGNE=$(wildcard *.cpp~)
GNIGNI=$(wildcard *.hpp~)

all:$(EXEC)
$(EXEC):$(OBJS) $(HEADOBJS)
	$(CXX) $(OBJS) $(HEADOBJS) -o $(EXEC)
$(OBJS):$(SRCS)
	$(CXX) $(CXXFLAGS) -c $(SRCS) 
$(HEADOBJS): $(HEADS)
	$(CXX) $(CXXFLAGS) -c $(HEADS)
clean:
	$(RM) $(EXEC) $(OBJS) $(GNEGNE) $(GNIGNI) $(HEADOBJS)
