main: main.o
	g++ -g -o main main.o -fsanitize=address
main.o: main.cpp
	g++ -g -c main.cpp -fsanitize=address
clean:
	rm main *.o