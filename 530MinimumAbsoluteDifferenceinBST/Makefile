main: main.o
	g++ -fsanitize=address -g -o main main.o
main.o: main.cpp
	g++ -fsanitize=address -g -c -g main.cpp
clean:
	rm main *.o 