all : hw4

hw4 : hw4.o hw4Functions.o ; clear
	g++ -o hw4 hw4.o hw4Functions.o

hw4.o : hw4.cc hw4Functions.cc hw4Functions.h
	g++ -c -Wall -Werror hw4.cc

hw4Functions.o : hw4Functions.cc
	g++ -c -Wall -Werror hw4Functions.cc