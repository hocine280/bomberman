CC = g++
CFLAGS = -Wall
REP_SOURE=
EXEC_NAME = program
OBJ_FILES = Personnage.cpp Bomberman.cpp ../Map/Position.cpp ../engine/utilities.cpp main.o

all : $(EXEC_NAME)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES)

%.o : %.cpp
	$(CC) -o $@ -c $<