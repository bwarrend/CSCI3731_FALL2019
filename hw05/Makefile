all : main

main : test.o
	g++ -o test test.o -ljpeg

test.o : test.cc
	g++ -c -Wall -Werror test.cc
