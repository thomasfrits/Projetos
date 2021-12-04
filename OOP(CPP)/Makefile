
saida: main.o funcionario.o
	g++ main.o funcionario.o -o saida

main.o: main.cpp
	g++ -c main.cpp

funcionario.o: funcionario.cpp funcionario.h
	g++ -c funcionario.cpp

clean:
	rm *.o saida

