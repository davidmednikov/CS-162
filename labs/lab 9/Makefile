main: getInt.o showMenu.o main.o
	g++ getInt.o showMenu.o main.o -o main

getInt.o: getInt.cpp
	g++ getInt.cpp -c
	
showMenu.o: showMenu.cpp
	g++ showMenu.cpp -c
    
main.o: main.cpp
	g++ main.cpp -c -std=c++0x
    
clean:
	rm *.o main