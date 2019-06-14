TARGET=generator
CXX=g++
LFLAGS=
CFLAGS=

all: main

main: PerlinNoise.o MapGenerator.o main.o
	$(CXX) PerlinNoise.o MapGenerator.o main.o -o $(TARGET) $(LFLAGS)

main.o: main.cpp
	$(CXX) main.cpp -c -o main.o $(CFLAGS)

MapGenerator.o: MapGenerator.cpp
	$(CXX) MapGenerator.cpp -c -o MapGenerator.o $(CFLAGS)

PerlinNoise.o: PerlinNoise.cpp
	$(CXX) PerlinNoise.cpp -c -o PerlinNoise.o $(CFLAGS)

clean:
	rm -rf *.o *.out $(TARGET)
