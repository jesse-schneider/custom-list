build:
	 g++ list.cpp -c -o list.o

	 g++ main.cpp -c -o main.o

	 g++ main.o list.o -o run

	 ./run

