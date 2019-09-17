all : hw3

hw3 : hw3.o hw3Functions.o
	g++ -o hw3 hw3.o hw3Functions.o

hw3.o : hw3.cc hw3Functions.cc hw3Functions.h
	g++ -c -Wall -Werror hw3.cc

hw3Functions.o : hw3Functions.cc
	g++ -c -Wall -Werror hw3Functions.cc