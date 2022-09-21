DEBUG = -g
OPTS = $(DEBUG) -Wall -ansi -pedantic -std=c++17

CC=g++ $(OPTS) -c
LN=g++

OBJS = main.o

proj1: $(OBJS)
	$(LN) -o proj1 $(OBJS)

main.o: main.cpp
	$(CC) main.cpp

clean:
	/bin/rm -rf *~ $(OBJS) proj1
