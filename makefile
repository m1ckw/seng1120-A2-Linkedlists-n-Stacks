CC=g++-10 #remove the -10 when not running on mac. 
CFLAGS=-c -Wall -std=c++98 
LDFLAGS=
SOURCES=Main.cpp 
DEPS=Node.hpp LinkedList.hpp Queue.hpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Main

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core
