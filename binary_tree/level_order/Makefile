CC = gcc
CFLAGS = -g -Wall -Werror -I.

TARGET = levelOrderTraversal

OBJECTS =  binaryTree.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET)  $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	@echo clean...
	rm $(TARGET) 
	rm $(OBJECTS)
