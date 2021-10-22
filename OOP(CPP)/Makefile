
saida: projeto.o loja.o
	g++ projeto.o loja.o -o saida


projeto.o: projeto.cpp
	g++ -c projeto.cpp

loja.o: loja.cpp loja.h
	g++ -c loja.cpp

clean:
	rm *.o saida

