CC = gcc
CFLAGS = -g -Wall -Werror -I.

TARGET = graph

OBJECTS = queue.o graph.o main.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET)  $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	@echo clean...
	rm $(TARGET) 
	rm $(OBJECTS)
