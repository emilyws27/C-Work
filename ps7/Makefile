CC = g++
CFLAGS = -std=c++11 -c -g -O1 -Wall -Werror -pedantic
LIBS = -lboost_regex -lboost_date_time
OBJS = kronos.o

all : ps7

ps7 : $(OBJS)
	$(CC) -o ps7 $(OBJS) $(LIBS)

%.o : %.cpp
	$(CC) $(CFLAGS) -o $@ $<

lint: 
	cpplint --filter=-runtime/references,-build/c++11 --root=. *.cpp *.hpp

clean :
	rm *.o
	rm ps7