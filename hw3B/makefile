SHELL = /bin/bash
CC = g++
CFLAGS1 = -c
CLFAGS2 = -o
SRC1 = $(wildcard *.cpp)
SRC2 = $(wildcard *.o)
EXE = $(patsubst %.cpp, %, $(SRC))

all:
	${CC} ${CFLAGS1} *.cpp
	${CC} ${CFLAGS2} -o main LinkedList.o Polygon.o main.o

clean:
	rm -f main
