#include <iostream>
#include <cstdlib>
#include <string>
#include "loja.h"
using namespace std;


int main(){

    int opcao;
    do{

        opcao = Menu();

        switch(opcao){
    
            case 0:
                    // Saída do programa
                    cout << "Saindo..."<<endl;
                    break;

            case 1:
                    /*  Percorre os produtos que possuem valor não vazio no campo do nome
                        e exibe na tela */

                    MostraProdutos();

                    break;

            case 2:

                    InsereProduto();

                    break;

            case 3:

                    RemoveProduto();

        };

    }while(opcao);

}