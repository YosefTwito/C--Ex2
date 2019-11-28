# -*- Makefile -*-

all: main

main: libmyBank.a main.o
	gcc -Wall -o main main.o libmyBank.a

libmyBank.a: myBank.o
	ar -rcs libmyBank.a myBank.o

main.o: main.c myBank.h
	gcc -Wall -c main.c

myBank.o: myBank.c myBank.h
	gcc -Wall -fPIC -c myBank.c 

.PHONY: clean all 

clean:
	rm -f *.o *.a  main
