CFLAGS=-g -O2 -Wall -Isrc
LIBS=-ldl
PY=script/show.py
NAME=gillespie
TARGET=bin/$(NAME)
OBJECTS=build/$(NAME).o

all: bin build datafile $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $< -lm

$(OBJECTS): src/$(NAME).c
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
