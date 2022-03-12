CC = g++
CFLAGS = -Wall
REP_PERSO= ../Persos
REP_ITEM = ../Items
EXEC_NAME = program
OBJ_FILES = *.cpp $(REP_ITEM)/Item.cpp $(REP_PERSO)/Bomberman.cpp $(REP_PERSO)/Personnage.cpp $(REP_PERSO)/Ghost.cpp $(REP_PERSO)/Ennemy.cpp 

all : $(EXEC_NAME)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES)

%.o : %.cpp
	$(CC) -o $@ -c $<

clean:
	rm -rf *.o