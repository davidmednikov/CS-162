main: getInt.o tool.o rock.o paper.o scissors.o RPSGame.o play_game.o
	g++ getInt.o tool.o rock.o paper.o scissors.o RPSGame.o play_game.o -o main

getInt.o: getInt.cpp
	g++ getInt.cpp -c
    
tool.o: tool.cpp
	g++ tool.cpp -c
    
rock.o: rock.cpp
	g++ rock.cpp -c
    
paper.o: paper.cpp
	g++ paper.cpp -c
    
scissors.o: scissors.cpp
	g++ scissors.cpp -c
   
RPSGame.o: RPSGame.cpp
	g++ RPSGame.cpp -c
    
play_game.o: play_game.cpp
	g++ play_game.cpp -c
    
clean:
	rm *.o main