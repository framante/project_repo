CXX= g++
CXXFLAGS= -std=c++17
CPPFLAGS= -I$(mkDealiiInc) -I$(mkAdolcInc) -I$(mkTrilinosInc) \
-I$(mkBoostInc) -I$(mkTbbInc) -I$(mkP4estInc)
LDFLAGS= -L$(mkDealiiLib) -L$(mkAdolcLib) -L$(mkTrilinosLib) \
-L$(mkBoostLib) -L$(mkTbbLib) -L$(mkP4estLib)
EXEC=main
SRCS=step2.cpp
OBJS=$(SRCS:.cpp=.o)

.PHONY: all clean distclean

all: $(EXEC)


$(OBJS): $(SRCS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $(SRCS)

$(EXEC): $(OBJS)
	$(CXX) $(LDFLAGS) $(OBJS) -o $(EXEC)

clean:
	$(RM) *.o

distclean: clean
	$(RM) $(EXEC)
