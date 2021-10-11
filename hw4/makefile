SHELL = /bin/bash
CC = g++
CFLAGS1 = -c
CLFAGS2 = -o
SRC1 = $(wildcard *.cpp)
SRC2 = $(wildcard *.o)
EXE = $(patsubst %.cpp, %, $(SRC))

all:
	${CC} ${CFLAGS1} *.cpp
	${CC} ${CFLAGS2} -o main Point.o Line.o ConvexHull.o main.o

clean:
	rm -f main Point.0 Line.0 ConvexHull.o main.o
