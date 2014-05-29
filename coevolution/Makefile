CFLAGS=-g -O2 -Wall -Isrc
LIBS=-ldl
OBJECTS=dynamic.o main_prisoner.o

all: main_prisoner average.py data
	./main_prisoner
	python average.py

main_prisoner: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.PHONY: clean

data:
	mkdir -p data

clean:
	rm -f main_prisoner $(OBJECTS)
	rm -rf data
