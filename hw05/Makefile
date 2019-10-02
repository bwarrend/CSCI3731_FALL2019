all : hw5

hw5 : hw5.o hw5Func.o ; clear ;
	g++ -o hw5 hw5.o hw5Func.o -ljpeg

hw5.o : hw5.cc hw5Func.h
	g++ -c -Wall -Werror hw5.cc
	
hw5Func.o : hw5Func.cc
	g++ -c -Wall -Werror hw5Func.cc