CFLAGS=-g -O2 -Wall -Isrc
LIBS=-ldl
TARGET=main_sexbattle
PY=show.py

all: $(TARGET)
	./$(TARGET)
	python $(PY)


datafile:
	mkdir -p data/prisoner_moran
	mkdir -p data/prisoner_local

show: timeseries.out
	python $(PY)

timeseries.out: $(TARGET)
	./$(TARGET)

help:
	@echo "make help	:	Get this help list."
	@echo "make       	:	Compile the main program, run to get all the data needed."
	@echo "make show   	:	Show result plot."
	@echo "make clean  	:	Clean all object files, compiled files and data."

.PHONY: clean

clean:
	rm -f $(TARGET) *.o
