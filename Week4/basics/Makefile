
all: programa

programa: programa.o
	g++ -o programa programa.o

programa.o: programa.cpp
	g++ -c programa.cpp -o programa.o

.PHONY: clean

clean:
	@rm programa programa.o

