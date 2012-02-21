# Compiler command.
CC=g++
# Flags.
FLAGS=-c -Wall -std=c++0x
# Includes.
INCS=-I. -Iinclude -I/usr/include
# Source files.
SOURCES=Action.cpp RandomNumbers.cpp Character.cpp Sizzlorr.cpp Throbulator.cpp main.cpp
# Object versions of sources.
OBJECTS=$(SOURCES:.cpp=.o)
#OBJECTS=RandomNumbers.o Character.o Sizzlorr.o

EXECUTABLE=engine

# Extension
EXT=.exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(INCS) $(OBJECTS) -o $@
	
clean:
	rm -rf *.o
	if test -f $(EXECUTABLE)$(EXT); then rm $(EXECUTABLE)$(EXT); fi
	
.cpp.o:
	$(CC) $(FLAGS) $(INCS) $< -o $@
	
dev: clean all
	./$(EXECUTABLE)$(EXT)