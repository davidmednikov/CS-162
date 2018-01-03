main: getInt.o Die.o Creature.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o main.o
	g++ getInt.o Die.o Creature.o Vampire.o Barbarian.o BlueMen.o Medusa.o HarryPotter.o main.o -o main

getInt.o: getInt.cpp
	g++ getInt.cpp -c
    
Die.o: Die.cpp
	g++ Die.cpp -c

Creature.o: Creature.cpp
	g++ Creature.cpp -c

Vampire.o: Vampire.cpp
	g++ Vampire.cpp -c
    
Barbarian.o: Barbarian.cpp
	g++ Barbarian.cpp -c

BlueMen.o: BlueMen.cpp
	g++ BlueMen.cpp -c
    
Medusa.o: Medusa.cpp
	g++ Medusa.cpp -c
    
HarryPotter.o: HarryPotter.cpp
	g++ HarryPotter.cpp -c
    
main.o: main.cpp
	g++ main.cpp -c
    
clean:
	rm *.o main