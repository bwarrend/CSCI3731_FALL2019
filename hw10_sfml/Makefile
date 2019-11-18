all: hw10
git : gitadd

gitadd : hw10
	git add Makefile Main.cc Angle.h DrunkenFish.cc DrunkenFish.h Fish.cc Fish.h FlippyFish.cc FlippyFish.h Exception.cc Exception.h
	
hw10 : Main.o Fish.o Angle.h DrunkenFish.o FlippyFish.o Exception.o ; reset
	g++ -o hw10 Main.o Fish.o DrunkenFish.o FlippyFish.o Exception.o -lsfml-graphics -lsfml-window -lsfml-system

Main.o : Main.cc Fish.h Angle.h
	g++ -c -Wall -Werror Main.cc

Fish.o : Fish.cc Fish.h Angle.h
	g++ -c -Wall -Werror Fish.cc

FlippyFish.o : FlippyFish.cc FlippyFish.h Fish.o
	g++ -c -Wall -Werror FlippyFish.cc

DrunkenFish.o : DrunkenFish.cc DrunkenFish.h Fish.o
	g++ -c -Wall -Werror DrunkenFish.cc

Exception.o : Exception.cc Exception.h
	g++ -c -Wall -Werror Exception.cc