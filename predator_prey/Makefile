CFLAGS=-g -O2 -Wall -Isrc
MATHLIB=-lm
TARGET=bin/main

SOURCES=src/main.c
OBJECTS=build/simulation.o

help:
	@echo "Usage:"
	@echo "make timeseries: Show time series in Gillespie algorithm."
	@echo "make uniform: Show time series in uniform time intervals."
	@echo "make average: Show time series under Gillespie algorithm over 100 average."

timeseries: build $(TARGET)
	./$(TARGET) 1
	python script/show.py


uniform: build $(TARGET)
	./$(TARGET) 2
	python script/show.py

average: data/afteraverage.out
	python script/averageshow.py

data/afteraverage.out: build $(TARGET)
	./$(TARGET) 3
	python script/average.py

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
