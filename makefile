CC=g++-10 #remove the -10 when not running on mac. 
CFLAGS=-c -Wall -std=c++98 
LDFLAGS=
SOURCES=Node.h LinkedList.h LStack.h GamePiece.cpp GameplayStack.h Connect4DemoTemplate.cpp
#DEPS=
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Main

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
