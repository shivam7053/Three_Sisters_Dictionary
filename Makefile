CC = g++
CFLAGS = -Wall -std=c++11
TARGET = dictionary

all: $(TARGET)

$(TARGET): src/ThreeSistersDictionary.o main.o
	$(CC) $(CFLAGS) -o $(TARGET) src/ThreeSistersDictionary.o main.o

src/ThreeSistersDictionary.o: src/ThreeSistersDictionary.cpp
	$(CC) $(CFLAGS) -c src/ThreeSistersDictionary.cpp -o src/ThreeSistersDictionary.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

clean:
	rm -f src/*.o main.o $(TARGET)
