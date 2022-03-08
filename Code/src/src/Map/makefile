CC = g++
CFLAGS = -Wall
REP_SOURE= src/src/
EXEC_NAME = program
OBJ_FILES = Wall.cpp Position.cpp Tile.cpp Map.cpp testAffichageMap.o

all : $(EXEC_NAME)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES)

%.o : %.cpp
	$(CC) -o $@ -c $<