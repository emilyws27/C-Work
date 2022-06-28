CC = g++
CFLAGS = --std=c++14 -Wall -Werror -pedantic
LIB = -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lboost_unit_test_framework

all: sfml-app

%.o: %.cpp $(DEPS)
	$(CC) $(CFLAGS) -c $<

sfml-app: main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm *.o sfml-app
