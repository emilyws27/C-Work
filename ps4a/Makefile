
CC= g++
CFLAGS= --std=c++17 -Wall -Werror -pedantic -g
DEPS = CircularBuffer.hpp
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

all: test

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

test:	test.o
	$(CC) $^ -o test $(LIB)

lint: 
	cpplint --filter=-runtime/references,-build/c++11 --root=. *.cpp *.hpp

clean:
	rm *.o
	rm test
	rm *.gch