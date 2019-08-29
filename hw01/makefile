all: main

functions.o: functions.cc functions.h
	g++ -c -Wall -Werror functions.cc
	
main.o: main.cc functions.h
	g++ -c -Wall -Werror main.cc
	
main: main.o functions.o
	g++ -o hw01.exe main.o functions.o