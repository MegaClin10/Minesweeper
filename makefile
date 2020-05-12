
play: main.o board.o cell.o
	g++ -std=c++11 main.o board.o cell.o -o play

main.o: main.cpp board.o
	g++ -std=c++11 -c main.cpp

board.o: board.cpp board.h cell.o
	g++ -std=c++11 -c board.cpp

cell.o: cell.cpp cell.h
	g++ -std=c++11 -c cell.cpp

clean:
	rm *.o play