#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

int InsereProduto(){
        //insere os valores informados na base
        string nome_do_produto, preco_do_produto;
        cout << "Digite o nome do produto: ";
        cin >> nome_do_produto;
        cout << "Digite o preco do produto: ";
        cin >> preco_do_produto;

        ofstream base_produtos;
        base_produtos.open("base_produtos.csv", ios_base::app);
        base_produtos << nome_do_produto << "," << preco_do_produto << endl;
        base_produtos.close();
        
        return 0;
}

int MostraProdutos(){

        int contador = 1;

        ifstream base_produtos;
        base_produtos.open("base_produtos.csv");

        string nome_do_produto;
        string preco_do_produto;

        while(getline(base_produtos, nome_do_produto, ',')){

                if (nome_do_produto == ""){
                        break;
                }
                getline(base_produtos, preco_do_produto, '\n');
                cout << "Nome do produto: " << nome_do_produto << " Preco: R$" << preco_do_produto << " Codigo: " << contador << endl;
                contador++;
        }

        base_produtos.close();

        return 0;

}
int RemoveProduto(){

        int codigo;
        cout << "Digite o código do produto a ser removido:";
        cin >> codigo;

        string linha;
        ifstream arq1;
        arq1.open("base_produtos.csv");
        ofstream arq2;
        arq2.open("novo.csv");

        for (int i = 1; i < codigo; i++){

                getline(arq1, linha, '\n' );
                arq2 << linha << endl;
        }

        getline(arq1, linha, '\n' );
        cout << "Produto removido com sucesso" << endl;
        arq2 << "Produto removido,0" << endl;
        
        while (!arq1.eof()){

                getline(arq1, linha, '\n' );
                if (linha == ""){
                        break;
                }
                arq2 << linha << endl;
        }
        remove("base_produtos.csv");
        rename("novo.csv", "base_produtos.csv");

        return 0;
}
