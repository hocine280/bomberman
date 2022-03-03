CC = g++
CFLAGS = -Wall
REP_ENGINE= ../engine
REP_MAP= ../Map
EXEC_NAME = program
OBJ_FILES = Personnage.cpp Bomberman.cpp $(REP_MAP)/Position.cpp $(REP_ENGINE)/utilities.cpp main.o

all : $(EXEC_NAME)

$(EXEC_NAME) : $(OBJ_FILES)
	$(CC) -o $(EXEC_NAME) $(OBJ_FILES)

%.o : %.cpp
	$(CC) -o $@ -c $<

clean:
	rm -rf *.o

mrproper:
	rm -rf $(EXEC_NAME)