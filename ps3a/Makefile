
CC= g++
CFLAGS= --std=c++17 -Wall -Werror -pedantic
DEPS = CelestialBody.hpp Universe.hpp
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

all: NBody

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

NBody:	Universe.o CelestialBody.o main.o
	$(CC) Universe.o CelestialBody.o main.o -o NBody $(LIB)

lint: 
	cpplint --filter=-runtime/references,-build/c++11 --root=. *.cpp *.hpp

clean:
	rm *.o
	rm NBody
	rm *.gch