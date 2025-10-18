CXX = g++
CXXFLAGS = -g -Wall -std=c++11

SRC = $(wildcard SourceFiles/*.cpp)



TARGET = main


main:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

out: clean compile execute

compile: main.cpp
	g++ -g -Wall -std=c++11 SourceFiles/* -o mainexe

execute: mainexe
	./mainexe

clean:
	rm -f mainexe