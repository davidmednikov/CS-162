main: getInt.o showMenu.o reverseString.o sumArray.o triangularNum.o main.o
	g++ getInt.o showMenu.o reverseString.o sumArray.o triangularNum.o main.o -o main

getInt.o: getInt.h getInt.cpp
	g++ getInt.h getInt.cpp -c

showMenu.o: getInt.h showMenu.h showMenu.cpp
	g++ getInt.h showMenu.h showMenu.cpp -c

reverseString.o: reverseString.h reverseString.cpp
	g++ reverseString.h reverseString.cpp -c
    
sumArray.o: sumArray.h sumArray.cpp
	g++ sumArray.h sumArray.cpp -c

triangularNum.o: triangularNum.h triangularNum.cpp
	g++ triangularNum.h triangularNum.cpp -c
    
main.o: getInt.h showMenu.h reverseString.h sumArray.h triangularNum.h main.cpp
	g++ getInt.h showMenu.h reverseString.h sumArray.h triangularNum.h main.cpp -c -std=c++0x
    
clean:
	rm *.o *.gch main