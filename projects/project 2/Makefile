main: Item.o List.o getInt.o getDouble.o showMenu.o main.o
	g++ Item.o List.o getInt.o getDouble.o showMenu.o main.o -o main

List.o: List.h Item.h List.cpp
	g++ List.h Item.h List.cpp -c

Item.o: Item.h Item.cpp
	g++ Item.h Item.cpp -c

getInt.o: getInt.h getInt.cpp
	g++ getInt.h getInt.cpp -c
    
getDouble.o: getDouble.h getDouble.cpp
	g++ getDouble.h getDouble.cpp -c

showMenu.o: showMenu.h showMenu.cpp getInt.h
	g++ showMenu.h showMenu.cpp getInt.h -c

main.o: Item.h List.h getInt.h getDouble.h showMenu.h main.cpp
	g++ Item.h List.h getInt.h getDouble.h showMenu.h main.cpp -c -std=c++0x

clean:
	rm *.o *.gch main