CC= g++
CFLAGS= --std=c++17 -Wall -Werror -pedantic
Boost= -lboost_unit_test_framework
DEPS = FibLFSR.hpp

# Make both projects
all: ps1 test

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

ps1: test.o FibLFSR.o
	$(CC) test.o FibLFSR.o -o ps1 $(Boost)

test: test.o FibLFSR.o
	$(CC) test.o FibLFSR.o -o test $(Boost)

clean:
	rm *.o
	rm ps1
	rm test