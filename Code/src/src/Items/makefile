CC = g++
CFLAGS = -Wall
REP_PERSO= ../Persos
REP_MAP = ../Map
EXEC_NAME = program
OBJ_FILES = *.cpp $(REP_MAP)/Position.cpp $(REP_PERSO)/Bomberman.cpp $(REP_PERSO)/Personnage.cpp ../engine/utilities.cpp

all : $(EXEC_NAME)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES)

%.o : %.cpp
	$(CC) -o $@ -c $<

clean:
	rm -rf *.o