main: main.o coordinate.o
	g++ -o main main.o coordinate.o -std=c++11
main.o: main.cpp
	g++ -c main.cpp -std=c++11
coordinate.o: coordinate.cpp
	g++ -c coordinate.cpp -std=c++11
