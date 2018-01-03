main: Ant.o printBoard.o getInt.o main.o showMenu.o
	g++ Ant.o printBoard.o getInt.o main.o showMenu.o -o main

Ant.o: Ant.h Ant.cpp
	g++ Ant.h Ant.cpp -c

printBoard.o: printBoard.h Ant.h printBoard.cpp
	g++ printBoard.h Ant.h printBoard.cpp -c

getInt.o: getInt.h getInt.cpp
	g++ getInt.h getInt.cpp -c

showMenu.o: showMenu.h showMenu.cpp getInt.h
	g++ showMenu.h showMenu.cpp getInt.h -c

main.o: Ant.h getInt.h printBoard.h showMenu.h main.cpp 
	g++ Ant.h getInt.h printBoard.h showMenu.h main.cpp -c

clean:
	rm *.o