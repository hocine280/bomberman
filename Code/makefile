CC = g++
CFLAGS = -Wall
REP_SOURE= src/src
EXEC_NAME = program
OBJ_FILES = $(REP_SOURE)/engine/*.cpp $(REP_SOURE)/Map/*.cpp $(REP_SOURE)/Persos/*.cpp $(REP_SOURE)/Items/*.cpp ProgBomberman.cpp

all : $(EXEC_NAME)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES)

%.o : %.cpp
	$(CC) -o $@ -c $<