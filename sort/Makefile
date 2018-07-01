main: main.o bubble.o insert.o heap.o quick.o combine.o
	g++ -o main main.o bubble.o insert.o heap.o quick.o combine.o
main.o: main.cpp bubble.hpp insert.hpp heap.hpp quick.hpp combine.hpp
	g++ -c main.cpp
bubble.o: bubble.cpp bubble.hpp
	g++ -c bubble.cpp
insert.o: insert.cpp insert.hpp
	g++ -c insert.cpp
heap.o: heap.cpp heap.hpp
	g++ -c heap.cpp
quick.o: quick.cpp quick.hpp
	g++ -c quick.cpp
combine.o: combine.cpp combine.hpp
	g++ -c combine.cpp
clean:
	rm main *.o