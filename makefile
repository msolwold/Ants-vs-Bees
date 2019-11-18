

game.out: main.o Game.o Player.o Board.o Bee.o Ant.o Throwers.o Ant_Thrower.o Ant_ShortThrower.o Ant_LongThrower.o Ant_Harvester.o Ant_Fire.o Ant_Wall.o Ant_Ninja.o Ant_Bodyguard.o
	$(CXX) $(CXXFLAGS) -o game.out main.o Game.o Player.o Board.o Bee.o Ant.o Throwers.o Ant_Thrower.o Ant_ShortThrower.o Ant_LongThrower.o Ant_Harvester.o Ant_Fire.o Ant_Wall.o Ant_Ninja.o Ant_Bodyguard.o

main.o: Main.cpp Core/Game.h
	$(CXX) $(CXXFLAGS) -c Main.cpp

Game.o: Core/Game.cpp Core/Game.h Core/Player.h Core/Board.h Core/Bee.h Ants/Ant.h Ants/Ant_Harvester.h Ants/Ant_Fire.h Ants/Ant_Ninja.h Ants/Ant_Wall.h Ants/Ant_Bodyguard.h Ants/Throwers/Ant_Thrower.h Ants/Throwers/Ant_ShortThrower.h Ants/Throwers/Ant_LongThrower.h
	$(CXX) $(CXXFLAGS) -c Core/Game.cpp

Player.o: Core/Player.cpp Core/Player.h
	$(CXX) $(CXXFLAGS) -c Core/Player.cpp

Board.o: Core/Board.cpp Core/Board.h Core/Bee.h Ants/Ant.h
	$(CXX) $(CXXFLAGS) -c Core/Board.cpp

Bee.o: Core/Bee.cpp Core/Bee.h
	$(CXX) $(CXXFLAGS) -c Core/Bee.cpp

Ant.o: Ants/Ant.cpp Ants/Ant.h
	$(CXX) $(CXXFLAGS) -c Ants/Ant.cpp

Throwers.o: Ants/Throwers/Throwers.cpp Ants/Throwers/Throwers.h Ants/Ant.h Core/Board.h
	$(CXX) $(CXXFLAGS) -c Ants/Throwers/Throwers.cpp

Ant_Thrower.o: Ants/Throwers/Ant_Thrower.cpp Ants/Throwers/Ant_Thrower.h Ants/Throwers/Throwers.h
	$(CXX) $(CXXFLAGS) -c Ants/Throwers/Ant_Thrower.cpp

Ant_ShortThrower.o: Ants/Throwers/Ant_ShortThrower.cpp Ants/Throwers/Ant_ShortThrower.h Ants/Throwers/Throwers.h
	$(CXX) $(CXXFLAGS) -c Ants/Throwers/Ant_ShortThrower.cpp

Ant_LongThrower.o: Ants/Throwers/Ant_LongThrower.cpp Ants/Throwers/Ant_LongThrower.h Ants/Throwers/Throwers.h
	$(CXX) $(CXXFLAGS) -c Ants/Throwers/Ant_LongThrower.cpp

Ant_Harvester.o: Ants/Ant_Harvester.cpp Ants/Ant_Harvester.h Ants/Ant.h
	$(CXX) $(CXXFLAGS) -c Ants/Ant_Harvester.cpp

Ant_Fire.o: Ants/Ant_Fire.cpp Ants/Ant_Fire.h Ants/Ant.h
	$(CXX) $(CXXFLAGS) -c Ants/Ant_Fire.cpp

Ant_Wall.o: Ants/Ant_Wall.cpp Ants/Ant_Wall.h Ants/Ant.h
	$(CXX) $(CXXFLAGS) -c Ants/Ant_Wall.cpp

Ant_Ninja.o: Ants/Ant_Ninja.cpp Ants/Ant_Ninja.h Ants/Ant.h
	$(CXX) $(CXXFLAGS) -c Ants/Ant_Ninja.cpp

Ant_Bodyguard.o: Ants/Ant_Bodyguard.cpp Ants/Ant_Bodyguard.h Ants/Ant.h
	$(CXX) $(CXXFLAGS) -c Ants/Ant_Bodyguard.cpp

yeet:
	rm *.o