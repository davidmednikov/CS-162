main: getInt.o showMenu.o Ball.o Player.o IvicaZubac.o KobeBryant.o LebronJames.o StephCurry.o Shaq.o LonzoBall.o Square.o _2Ptr.o _3Ptr.o OutOfBounds.o Court.o Game.o main.o
	g++ getInt.o showMenu.o Ball.o Player.o IvicaZubac.o KobeBryant.o LebronJames.o StephCurry.o Shaq.o LonzoBall.o Square.o _2Ptr.o _3Ptr.o OutOfBounds.o Court.o Game.o main.o -o main

getInt.o: getInt.cpp
	g++ getInt.cpp -c -g
	
showMenu.o: showMenu.cpp
	g++ showMenu.cpp -c -g
    
Ball.o: Ball.cpp
	g++ Ball.cpp -c -g -std=c++11 

Player.o: Player.cpp
	g++ Player.cpp -c -g
	
IvicaZubac.o: IvicaZubac.cpp
	g++ IvicaZubac.cpp -c -g
	
KobeBryant.o: KobeBryant.cpp
	g++ KobeBryant.cpp -c -g
	
LebronJames.o: LebronJames.cpp
	g++ LebronJames.cpp -c -g
	
StephCurry.o: StephCurry.cpp
	g++ StephCurry.cpp -c -g
	
Shaq.o: Shaq.cpp
	g++ Shaq.cpp -c -g
	
LonzoBall.o: LonzoBall.cpp
	g++ LonzoBall.cpp -c -g

Square.o: Square.cpp
	g++ Square.cpp -c -g -std=c++11 
    
_2Ptr.o: _2Ptr.cpp
	g++ _2Ptr.cpp -c -g

_3Ptr.o: _3Ptr.cpp
	g++ _3Ptr.cpp -c -g
    
OutOfBounds.o: OutOfBounds.cpp
	g++ OutOfBounds.cpp -c -g
    
Court.o: Court.cpp
	g++ Court.cpp -c -g -std=c++11 
	
Game.o: Game.cpp
	g++ Game.cpp -c -g
    
main.o: main.cpp
	g++ main.cpp -c -g -std=c++0x
    
clean:
	rm *.o main