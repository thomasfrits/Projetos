
saida: main.o loja.o funcionario.o
	g++ main.o loja.o funcionario.o -o saida

main.o: main.cpp
	g++ -c main.cpp

funcionario.o: funcionario.cpp funcionario.h
	g++ -c funcionario.cpp

loja.o: loja.cpp loja.h
	g++ -c loja.cpp

clean:
	rm *.o saida

