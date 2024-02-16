all: compile run

compile:
	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Avl.o -c ./src/Avl.cpp
	g++ -I ./include/ -o ./lib/DynamicArray.o -c ./src/DynamicArray.cpp
	g++ -I ./include/ -o ./bin/Run ./lib/Stack.o ./lib/Node.o ./lib/Avl.o ./lib/DynamicArray.o ./src/Run.cpp

run:
	./bin/Run