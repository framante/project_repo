# get all files *.cpp
SRCS=$(wildcard *.cpp)
# get the corresponding object file
OBJS = $(SRCS:.cpp=.o)
# get all headers in the working directory
HEADERS=$(wildcard *.hpp)
# executable
EXEC=main

#========================== NEW THE DEFINITION OF THE TARGETS
.phony= all clean distclean

.DEFAULT_GOAL = all

all: $(EXEC)

clean:
	$(RM) -f $(EXEC) $(OBJS)

distclean:
	$(MAKE) clean
	$(RM) *.out *.bak *~

$(EXEC): $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS)

$(OBJS): $(SRCS)



