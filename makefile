CC = g++
CFLAGS = -O0 -g -Wall -ansi -pedantic

all: driver.o utilities.o
	$(CC) -o dircat driver.o utilities.o
	
driver.o: driver.cpp driver.h
	$(CC) $(CFLAGS) -c driver.cpp
	
utilities.o: utilities.cpp utilities.h
	$(CC) $(CFLAGS) -c utilities.cpp
	
clean:
	rm -f *\.o
