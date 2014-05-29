CFLAGS=-g -O2 -Wall -Isrc
LIBS=-ldl
OBJECTS=dynamic.o main_prisoner.o
PY=result.py

all: main_prisoner datafile
	./main_prisoner

main_prisoner: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $@


datafile:
	mkdir -p data/prisoner_moran
	mkdir -p data/prisoner_local

show: all
	python $(PY)

help:
	@echo "make help	:	Get this help list."
	@echo "make       	:	Compile the main program, run to get all the data needed."
	@echo "make show    :   Show result plot."
	@echo "make clean  	:	Clean all object files, compiled files and data."

.PHONY: clean

clean:
	rm -f main_prisoner $(OBJECTS)
	rm -rf data
