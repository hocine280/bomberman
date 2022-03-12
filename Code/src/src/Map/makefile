CC = g++
CFLAGS = -Wall
REP_PERSO= ../Persos
EXEC_NAME = program
OBJ_FILES = Wall.cpp Position.cpp Tile.cpp Map.cpp $(REP_PERSO)/Bomberman.cpp $(REP_PERSO)/Personnage.cpp $(REP_PERSO)/Ghost.cpp $(REP_PERSO)/Ennemy.cpp testAffichageMap.o

all : $(EXEC_NAME)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES)

%.o : %.cpp
	$(CC) -o $@ -c $<