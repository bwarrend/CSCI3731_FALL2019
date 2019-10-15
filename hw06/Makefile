all : hw6

hw6 : Main.o Angle.o; clear
	g++ -o hw6 Main.o Angle.o

Main.o : Main.cc Angle.o Angle.h ; clear
	g++ -c -Wall -Werror Main.cc

Angle.o : Angle.cc Angle.h ; clear
	g++ -c -Wall -Werror Angle.cc