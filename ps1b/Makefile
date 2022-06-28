CC= g++
CFLAGS= --std=c++17 -Wall -Werror -pedantic
DEPS = FibLFSR.hpp
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework


# Make both projects
all: PhotoMagic test

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

PhotoMagic: photomagic.o FibLFSR.o
	$(CC) photomagic.o FibLFSR.o -o PhotoMagic $(LIB)

test: test.o FibLFSR.o 
	$(CC) test.o FibLFSR.o -o test $(LIB)

clean:
	rm *.o
	rm PhotoMagic
	rm test