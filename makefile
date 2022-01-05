CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp Administrador.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=final

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(EXECUTABLE) *.o 

fullclean:
	rm -rf $(EXECUTABLE) *.o 
