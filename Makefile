.DEFAULT_GOAL := all

sistema.o: sistema.cpp sistema.h
	g++ sistema.cpp -c

executor.o: executor.cpp executor.h sistema.o
	g++ executor.cpp -c

usuario.o: usuario.cpp usuario.h
	g++ usuario.cpp -c

servidor.o: servidor.cpp servidor.h
	g++ servidor.cpp -c

objects: sistema.o executor.o usuario.o servidor.o

concordo: objects concordo.cpp
	g++ sistema.o executor.o usuario.o servidor.o concordo.cpp -o concordo

clean:
	rm *.o concordo

all: concordo

run:
	./concordo
