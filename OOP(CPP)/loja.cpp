#include <iostream>
#include <fstream>
#include <string>
#include "loja.h"
using namespace std;

int Loja::MenuGerente(){
  
        cout << "0 - Sair" << endl;
        cout << "1 - Verificar produtos cadastrados" << endl;
        cout << "2 - Cadastrar produto" << endl;
        cout << "3 - Remover produto" << endl;
        cout << "4 - Alterar preco de algum produto" << endl;
        cin >> opcao;
        return opcao;
}

int Loja::MenuVendedor(){
   
        cout << "0 - Sair"<<endl;
        cout << "1 - Cadastrar uma venda" << endl;
        // cout << "2 - Adicionar estoque" << endl;
        cin >> opcao;
        return opcao;
}

int Loja::MenuAdm(){
   
        cout << "0 - Sair"<<endl;
        cout << "1 - Verificar funcionarios cadastrados" << endl;
        cout << "2 - Cadastrar funcionario" << endl;
        cout << "3 - Remover funcionario" << endl;
        cin >> opcao;
        return opcao;
}