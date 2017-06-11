main: main.o stringiterator.o
	g++ -o main main.o stringiterator.o
main.o: main.cpp stringiterator.h
	g++ -c main.cpp
stringiterator.o: stringiterator.cpp stringiterator.h
	g++ -c stringiterator.cpp
clean:
	rm main *.o
