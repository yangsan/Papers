CFLAGS=-g -O2 -Wall -Isrc
MATHLIB=-lm
PY=script/show.py
TARGET=bin/main

SOURCES=src/main.c
OBJECTS=build/simulation.o

all: build $(TARGET)
	./$(TARGET)
	python $(PY)

uniform: build $(TARGET)
	./$(TARGET) uniform
	python $(PY)

$(TARGET): $(OBJECTS) $(SOURCES)
	$(CC) $(CFLAGS) $(OBJECTS) $(SOURCES) -o $(TARGET) $(MATHLIB)

$(OBJECTS): src/simulation.c
	$(CC) $(CFLAGS) -c -o $@ $<

build:
	mkdir -p build
	mkdir -p bin
	mkdir -p data

clean:
	rm -rf bin data build
