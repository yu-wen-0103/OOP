SHELL = /bin/bash
CC = g++
CFLAGS1 = -c
CLFAGS2 = -o
SRC1 = $(wildcard *.cpp)
SRC2 = $(wildcard *.o)
EXE = $(patsubst %.cpp, %, $(SRC))

all:
	${CC} ${CFLAGS1} *.cpp
	${CC} ${CFLAGS2} -o main Shape.o Circle.o Rectangle.o Triangle.o main.o
	javac -d . Shape.java Circle.java Rectangle.java Triangle.java hw6_main.java

clean:
	rm -f main Shape.o Circle.o Rectangle.o Triangle.o main.o
