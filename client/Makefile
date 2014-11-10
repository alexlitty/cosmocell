PROJECT=client
SOURCES=layer_world.cpp main.cpp
LIBRARY=
INCPATHS=../depend/irrlicht/include ../depend/zmq/include ../
LIBPATHS=../depend/irrlicht/lib/Linux ../depend/zmq/lib/
OBJPATH=.obj/
BINPATH=.bin/
#LDFLAGS=-lzmq -lIrrlicht -lGL -lGLU -lXrandr -lXext -lX11 -lXxf86vm
LDFLAGS=-lzmq -lIrrlicht -lGL -lGLU -lXext -lX11 -lXxf86vm
CFLAGS=-Wall -std=c++11
CC=g++

# Background colors
BG_WHITE=$$(tput setab 7)

# Foreground colors
FG_RED=$$(tput setaf 1)
FG_GREEN=$$(tput setaf 2)
FG_YELLOW=$$(tput setaf 3)
FG_BLUE=$$(tput setaf 4)
FG_MAGENTA=$$(tput setaf 5)
FG_CYAN=$$(tput setaf 6)

# Other colors
COLOR_RESET=$$(tput sgr 0)
 
# Other variables
OBJECTS=$(SOURCES:%.cpp=$(OBJPATH)%.o)
INCFLAGS=$(foreach TMP,$(INCPATHS),-I$(TMP))
LIBFLAGS=$(foreach TMP,$(LIBPATHS),-L$(TMP))
BINARY=$(PROJECT)

# Clear screen, compile and link
all: clearscreen $(SOURCES) $(BINARY)
	@echo "$(BG_WHITE)$(FG_MAGENTA) Executing $(BINARY) $(COLOR_RESET)"
	(cd $(BINPATH) && ./$(BINARY))
	@echo ""

# Link objects into binary
$(BINARY): $(OBJECTS)
	@echo "$(BG_WHITE)$(FG_GREEN) Linking $(COLOR_RESET)"
	$(CC) $(OBJECTS) $(LIBFLAGS) $(LDFLAGS) -o $(BINPATH)$@
	@echo ""

# Compile source into objects
$(OBJPATH)%.o: %.cpp
	@echo "$(BG_WHITE)$(FG_BLUE) Compiling $< $(COLOR_RESET)"
	$(CC) $(INCFLAGS) -c $< $(LIBFLAGS) $(LDFLAGS) $(CFLAGS) -o $@
	@echo ""

# Distclean
distclean: clean
	rm -f $(BINARY)

# Clean
clean:
	rm -f $(OBJECTS)

# Clear screen
.PHONY: clearscreen
clearscreen:
	clear
