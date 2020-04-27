main: main.o
	g++ -o main main.o -fsanitize=address -fno-omit-frame-pointer -Wno-format-security
main.o: main.cpp
	g++ -c -fsanitize=address -fno-omit-frame-pointer -Wno-format-security main.cpp
clean:
	rm main *.o