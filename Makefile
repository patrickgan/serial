CC=gcc
CFLAGS=-std=c99

all: findcom
.PHONY: all
findcom:
	$(CC) $(CFLAGS) -o findcom findcom.c
.PHONY: clean
clean:
	rm -f findcom
