#include <iostream>
# include "loja.h"
using namespace std;

int Menu(){
        // Menu de selecao para a loja    
        int opcao;
        cout << "0 - Sair"<<endl;
        cout << "1 - Verificar produtos cadastrados"<<endl;
        cout << "2 - Cadastrar produto"<<endl;
        cout << "3 - Remover produto"<<endl;
        cin >> opcao;
        return opcao;
}

// int MostraProdutos(produto produtos){

//         for (size_t i = 0; i < produtos.size(); i++) {
        
//                 if (produtos[i].nome != ""){

//                         cout << "Produto: ";
//                         cout << produtos[i].nome;
//                         cout << "  Codigo: ";
//                         cout << produtos[i].codigo;
//                         cout << "  Preco: R$";
//                         cout << produtos[i].preco<<endl;
//                 }
//         }
// }