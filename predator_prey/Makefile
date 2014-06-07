CFLAGS=-g -O2 -Wall -Isrc
MATHLIB=-lm
PY=script/show.py
TARGET=bin/main

SOURCES=src/main.c
OBJECTS=build/simulation.o

help:
	@echo "make average."

average: data/afteraverage.out
	python script/averageshow.py

data/afteraverage.out: build $(TARGET)
	./$(TARGET)
	python script/average.py

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
	mkdir -p data/timeseries
	mkdir -p data/average

clean:
	rm -rf bin data build
