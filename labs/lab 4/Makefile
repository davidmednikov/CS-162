main: Person.o Student.o Instructor.o Building.o University.o getInt.o getDouble.o showMenu.o main.o
	g++ Person.o Student.o Instructor.o Building.o University.o getInt.o getDouble.o showMenu.o main.o -o main

Person.o: Person.h Person.cpp
	g++ Person.h Person.cpp -c

Student.o: Person.h Student.h Student.cpp
	g++ Person.h Student.h Student.cpp -c

Instructor.o: Person.h Instructor.h Instructor.cpp
	g++ Person.h Instructor.h Instructor.cpp -c
    
Building.o: Building.h Building.cpp
	g++ Building.h Building.cpp -c
    
University.o: Person.h Building.h University.h getInt.h getDouble.h showMenu.h University.cpp
	g++ Person.h Building.h University.h getInt.h getDouble.h showMenu.h University.cpp -c -std=c++11
    
getInt.o: getInt.h getInt.cpp
	g++ getInt.h getInt.cpp -c
    
getDouble.o: getDouble.h getDouble.cpp
	g++ getDouble.h getDouble.cpp -c
    
showMenu.o: showMenu.h showMenu.cpp getInt.h
	g++ showMenu.h showMenu.cpp getInt.h -c

main.o: Student.h Instructor.h Building.h University.h getInt.h getDouble.h showMenu.h main.cpp
	g++ Student.h Instructor.h Building.h University.h getInt.h getDouble.h showMenu.h main.cpp -c -std=c++0x

clean:
	rm *.o *.gch main