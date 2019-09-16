all : main

main : hw02a hw02b

hw02a : hw02a.o
	g++ -o hw02a hw02a.cc

hw02a.o : hw02a.cc
	g++ -c -Wall -Werror hw02a.cc

hw02b : hw02b.o bFunction.o
	g++ -o hw02b bFunction.o hw02b.o

hw02b.o : hw02b.cc bFunction.o bFunction.h
	g++ -c -Wall -Werror hw02b.cc

bFunction.o: bFunction.cc
	g++ -c -Wall -Werror bFunction.cc