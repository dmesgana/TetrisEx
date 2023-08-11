CC=g++
CFLAGS=-c -DLINUX -I. -LSDL/lib
LDFLAGS=-lSDL
SOURCES=main.cpp Game.cpp board.cpp IO.cpp pieces.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=tetris

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	-rm -f $(OBJECTS) $(EXECUTABLE)