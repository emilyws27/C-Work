CC = g++
CFLAGS = -g -Wall -Werror -std=c++17 -pedantic
DEPS = RandWriter.hpp
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

all: TextWriter test

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

test: test.o RandWriter.o
	$(CC) $^ -o test  $(LIB)

TextWriter:  TextWriter.o RandWriter.o
	$(CC) $^ -o TextWriter $(LIB)

lint: 
	cpplint --filter=-runtime/references,-build/c++11 --root=. *.cpp *.hpp


clean:
	rm *.o
	rm TextWriter
	rm test
	rm lint