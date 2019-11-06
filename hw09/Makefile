all: hw9 ;
git : gitadd

gitadd : hw9
	git add Makefile Main.cc Angle.cc Angle.h DrunkenFish.cc DrunkenFish.h Fish.cc Fish.h FlippyFish.cc FlippyFish.h Population.cc Population.h Exception.cc Exception.h bwarrend_shortanswers_hw9.txt
	
hw9 : Main.o Fish.o DrunkenFish.o FlippyFish.o Angle.o Population.o ; reset
	g++ -o hw9 Main.o Fish.o Angle.o Population.o DrunkenFish.o FlippyFish.o

Main.o : Main.cc Fish.h Angle.h Population.h ; clear
	g++ -c -Wall -Werror Main.cc

Fish.o : Fish.cc Fish.h Angle.cc Angle.h Population.cc Population.h
	g++ -c -Wall -Werror Fish.cc
	
Angle.o : Angle.cc Angle.h
	g++ -c -Wall -Werror Angle.cc

Population.o : Population.cc Population.h
	g++ -c -Wall -Werror Population.cc

FlippyFish.o : FlippyFish.cc FlippyFish.h Fish.o
	g++ -c -Wall -Werror FlippyFish.cc

DrunkenFish.o : DrunkenFish.cc DrunkenFish.h Fish.o
	g++ -c -Wall -Werror DrunkenFish.cc

Exception.o : Exception.cc Exception.h
	g++ -c -Wall -Werror Exception.cc