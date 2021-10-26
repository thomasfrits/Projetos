#include <iostream>
#include <cstdlib>
#include <string>
#include "loja.h"
using namespace std;


int main(){
    Loja mercadinho;
    int opcao;
    do{

        opcao = mercadinho.Menu();

        switch(opcao){
    
            case 0:

                    cout << "Saindo..."<<endl;

                    break;

            case 1:

                    mercadinho.MostraProdutos();

                    break;

            case 2:

                    mercadinho.InsereProduto();

                    break;

            case 3:

                    mercadinho.RemoveProduto();

        };

    }while(opcao);

}