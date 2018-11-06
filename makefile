CC = gcc
CFLAGS = -g
TARGET = bank
OBJS = main.o menu.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
menu.o: menu.c menu.h
	$(CC) $(CFLAGS) -c menu.c
clean:
	/bin/rm -f *.o $(TARGET)
