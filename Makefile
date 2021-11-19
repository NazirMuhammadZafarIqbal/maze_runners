main.o: main.cpp
	g++ -c main.cpp
#-c means we'll just make a .o file

GameManager.o: src\GameManager.cpp
	g++ -c src\GameManager.cpp

output: main.o GameManager.o
	g++ main.o GameManager.o -o output
#whenever main.o or GameManager.o changes we compile them

clean-win:
	erase *.o output

clean:
	rm *.o output
#rm on linux | erase on windows
#all other .o and output files
