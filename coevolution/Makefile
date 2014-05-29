CFLAGS=-g -O2 -Wall -Isrc
LIBS=-ldl
OBJECTS=dynamic.o main_prisoner.o
PY=resultl.py

all: main_prisoner $(PY) data
	./main_prisoner
	python $(PY)

main_prisoner: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.PHONY: clean

data:
	mkdir -p data

clean:
	rm -f main_prisoner $(OBJECTS)
	rm -rf data
