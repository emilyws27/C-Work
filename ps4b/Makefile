
CC= g++
CFLAGS= --std=c++17 -Wall -Werror -pedantic -g
DEPS = CircularBuffer.hpp StringSound.hpp
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

all: test KSGuitarSim

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<


KSGuitarSim:  KSGuitarSim.o StringSound.o
	$(CC) $^ -o KSGuitarSim $(LIB)

test:	test.o StringSound.o
	$(CC) $^ -o test $(LIB)

lint: 
	cpplint --filter=-runtime/references,-build/c++11 --root=. *.cpp *.hpp

clean:

	rm *.o
	rm KSGuitarSim
	rm test
	rm *.gch