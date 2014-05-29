CFLAGS=-g -O2 -Wall -Isrc
LIBS=-ldl
OBJECTS=dynamic.o main_prisoner.o
#PY=resultl.py

all: main_prisoner datafile
	./main_prisoner

main_prisoner: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.PHONY: clean datafile

datafile:
	mkdir -p data/prisoner_moran
	mkdir -p data/prisoner_local

clean:
	rm -f main_prisoner $(OBJECTS)
	rm -rf data
