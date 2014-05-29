CFLAGS=-g -O2 -Wall -Isrc
LIBS=-ldl
OBJECTS=dynamic.o main_prisoner.o

all: main_prisoner show.py
	./main_prisoner
	python show.py

main_prisoner: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@

.PHONY: clean

clean:
	rm -f main_prisoner $(OBJECTS)

