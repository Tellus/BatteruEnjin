# Compiler command.
CC=g++
# Flags.
FLAGS=-c -Wall -std=c++0x
# Includes.
INCS=-I. -Iinclude -I/usr/include
# Linkage!
#LIB=-L/usr/lib/i386-linux-gnu -lSDL -lSDLmain
LIB=-lSDL -lSDLmain -lSDL_image
# Source files.
SOURCES=BE_Ability.cpp BE_Attribute.cpp BE_Character.cpp BE_Effect.cpp BE_Engine.cpp BE_Primarch.cpp BE_Resource.cpp BE_Surface.cpp BE_Frontend.cpp Action.cpp RandomNumbers.cpp Character.cpp main.cpp BE_Primarch.cpp BE_Resource.cpp BE_Ability.cpp BE_GameState.cpp SimpleRuleSet.cpp BE_RuleSet.cpp
# Object versions of sources.
OBJECTS=$(SOURCES:.cpp=.o)
#OBJECTS=RandomNumbers.o Character.o Sizzlorr.o

EXECUTABLE=engine

# Extension
EXT=

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(INCS) $(LIB) $(OBJECTS) -o $@
	
clean:
	rm -rf *.o
	if test -f $(EXECUTABLE)$(EXT); then rm $(EXECUTABLE)$(EXT); fi
	
.cpp.o:
	$(CC) $(FLAGS) $(INCS) $(LIB) $< -o $@
	
dev: all
	./$(EXECUTABLE)$(EXT)
