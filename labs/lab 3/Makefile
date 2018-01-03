main: Game.o Player.o Die.o LoadedDie.o getInt.o main.o
	g++ Game.o Player.o Die.o LoadedDie.o getInt.o main.o -o main

Game.o: Game.h Player.h Game.cpp
	g++ Game.h Player.h Game.cpp -c

Player.o: Player.h Die.h LoadedDie.h Player.cpp
	g++ Player.h Die.h LoadedDie.h Player.cpp -c

Die.o: Die.h Die.cpp
	g++ Die.h Die.cpp -c
    
LoadedDie.o: Die.h LoadedDie.h LoadedDie.cpp
	g++ Die.h LoadedDie.h LoadedDie.cpp -c
    
getInt.o: getInt.h getInt.cpp
	g++ getInt.h getInt.cpp -c

main.o: Game.h main.cpp
	g++ Game.h main.cpp -c

clean:
	rm *.o *.gch main