CFLAGS=-g -O2 -Wall -Isrc
LIBS=-ldl
PY=script/show.py
TARGET=bin/main
OBJECTS=build/main.o

all: bin build datafile $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $<

$(OBJECTS): src/main.c
	$(CC) $(CFLAGS) -c  -o $@ $<

bin:
	mkdir -p bin

datafile:
	mkdir -p data

build:
	mkdir -p build

clean:
	rm -rf bin
	rm -rf build
	rm -rf data
