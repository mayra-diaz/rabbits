EXECUTABLES= lrabbit
CC=gcc
CFLAGS=-g3 -Wall -std=gnu99

.PHONY: all clean

all: $(EXECUTABLES)

lrabbit: main.o rabbit.o rabbit_helper.o list.o debug.o

$(EXECUTABLES):
	$(CC) $^ -o $@

rabbit.o: rabbit.c
rabbit_helper.o: rabbit_helper.c

rabbit.o:
	$(CC) $(CFLAGS) -DPINTOS_LIST -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.ONESHELL:
clean:
	rm -f $(EXECUTABLES) *.o
