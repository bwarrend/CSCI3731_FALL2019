all: hw7

hw7 : Main.o Fish.o Angle.o Population.o
	g++ -o hw7 Main.o Fish.o Angle.o Population.o

Main.o : Main.cc Fish.h Angle.h Population.h
	g++ -c -Wall -Werror Main.cc

Fish.o : Fish.cc Fish.h Angle.cc Angle.h Population.cc Population.h
	g++ -c -Wall -Werror Fish.cc
	
Angle.o : Angle.cc Angle.h
	g++ -c -Wall -Werror Angle.cc

Population.o : Population.cc Population.h
	g++ -c -Wall -Werror Population.cc