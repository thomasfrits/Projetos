#include <iostream>
#include <cstdlib>
#include <string>
#include "loja.h"
using namespace std;

// struct produto{
// // Struct que vai armazenar as informações sobre os produtos. Futuramente uma classe
//     string nome;
//     int codigo;
//     float preco;

// };

int main(){

    int opcao;
    produto produtos[20];
    do{
        // Menu de opções, variando com a escolha e fechando caso a escolha seja 0 
        opcao = Menu();
        // cout << "0 - Sair"<<endl;
        // cout << "1 - Verificar produtos cadastrados"<<endl;
        // cout << "2 - Cadastrar produto"<<endl;
        // cout << "3 - Remover produto"<<endl;
        // cin >> opcao;

        switch(opcao){
    
            case 0:
                    // Saída do programa
                    cout << "Saindo..."<<endl;
                    break;

            case 1:
                    /*  Percorre os produtos que possuem valor não vazio no campo do nome
                        e exibe na tela */

                    for (auto &item : produtos) {
                        
                        if (item.nome != ""){

                            cout << "Produto: ";
                            cout << item.nome;
                            cout << "  Codigo: ";
                            cout << item.codigo;
                            cout << "  Preco: R$";
                            cout << item.preco<<endl;
                        }
                    }

                    system("pause");
                    break;

            case 2:
                    //  Insere cada informação do produto no campo desejado.

                    for (auto &item : produtos) {
                        
                        if (item.nome == ""){

                            cout << "Digite o nome do produto: ";
                            cin >> item.nome;
                            cout << "Digite o codigo do produto: ";
                            cin >> item.codigo;
                            cout << "Digite o preco do produto: ";
                            cin >> item.preco;
                            break;
                        }
                    }
                    break;

            case 3:
                    // Remove o produto com base no código.
                    int codigo;

                    cout << "Digite o codigo do produto a ser removido: ";
                    cin >> codigo;

                    for (auto &item : produtos) {
                        /*  percorre toda a lista com os produtos até que encontre
                            um produto com o código equivalente ao informado para ser removido,1
                            então, altera o valor do campo "nome" para uma string vazia*/
                        if (item.codigo == codigo){

                            item.nome = "";
                            break;
                        }
                    }

                    cout << "Produto removido com sucesso!"<<endl;
                    system("pause");

        };

    }while(opcao);

}