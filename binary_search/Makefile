CC = gcc
CFLAGS = -g -Wall -Werror -I.

TARGET = binarySearch 

OBJECTS = sort.o  binarySearch.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET)  $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	@echo clean...
	rm $(TARGET) 
	rm $(OBJECTS)
