# Makefile
CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = array_project

all: $(TARGET)

$(TARGET): main.o IntArray.o
	$(CXX) -o $@ $^

main.o: main.cpp IntArray.h
	$(CXX) $(CXXFLAGS) -c main.cpp

IntArray.o: IntArray.cpp IntArray.h
	$(CXX) $(CXXFLAGS) -c IntArray.cpp

clean:
	rm -f *.o $(TARGET)