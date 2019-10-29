all : hw8

hw8 : Main.o Image.o ; clear ;
	g++ -o hw8 Main.o Image.o -ljpeg

Main.o : Main.cc Image.h
	g++ -c -Wall -Werror Main.cc
	
Image.o : Image.cc
	g++ -c -Wall -Werror Image.cc