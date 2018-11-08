CC = gcc
CFLAGS = -g
TARGET = bank
OBJS = main.o menu.o bank.o

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
main.o: main.c main.h
	$(CC) $(CFLAGS) -c main.c
menu.o: menu.c menu.h
	$(CC) $(CFLAGS) -c menu.c
bank.o: bank.c bank.h
	$(CC) $(CFLAGS) -c bank.c
clean:
	/bin/rm -f *.o $(TARGET)
