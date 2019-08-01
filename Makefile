CXX      = clang++-7
CXXFLAGS = -g -O3

SRCS = \
	InputParser.cpp test-DFA.cpp test-main.cpp
OBJS = $(subst .cpp,.o,$(SRCS))

all: test

test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o test $(OBJS)

test-main.o: test-main.cpp catch.hpp
test-DFA.o: test-DFA.cpp catch.hpp DFA.hpp
InputParser.o: InputParser.cpp InputParser.hpp
