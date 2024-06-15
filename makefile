CC=g++
CFLAGS=-Wall -g
LDFLAGS=
SOURCES=node.h linked_list.h browser.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=Browser

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o $(EXECUTABLE)
