#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "loja.h"
using namespace std;

int Loja::Menu(){
// Mostra um menu de acoes para a loja    
        int opcao;
        cout << "0 - Sair"<<endl;
        cout << "1 - Verificar produtos cadastrados"<<endl;
        cout << "2 - Cadastrar produto"<<endl;
        cout << "3 - Remover produto"<<endl;
        cin >> opcao;
        return opcao;
}

int Loja::InsereProduto(){
// Recebe os valores de nome e preço e insere os valores informados na base
        
        string nome_do_produto, preco_do_produto, campo1, campo2;
        ofstream base_produtos;
        ifstream arq1;
        bool possui_produto_removido = false;
        
        cout << "Digite o nome do produto: ";
        cin >> nome_do_produto;
        cout << "Digite o preco do produto: ";
        cin >> preco_do_produto;

        arq1.open("base_produtos.csv");
        while (!arq1.eof()){

                getline(arq1, campo1, ',' );
                if (campo1 == "Produto removido"){

                        possui_produto_removido = true;
                        base_produtos.close();
                        break;
                }
                getline(arq1, campo2, '\n');
        }
        arq1.close();
        
        if (possui_produto_removido){
                
                arq1.open("base_produtos.csv");
                base_produtos.open("novo.csv");
                
                while (!arq1.eof()){

                        getline(arq1, campo1, ',');
                        getline(arq1, campo2, '\n');
                        if (campo1 == "Produto removido"){
                                
                                base_produtos << nome_do_produto << "," << preco_do_produto << endl;
                                break;
                        }
                        base_produtos << campo1 << "," << campo2 << endl;
                }
                while (!arq1.eof()){

                        getline(arq1, campo1, ',');
                        getline(arq1, campo2, '\n');
                        
                        if (campo1 == ""){
                                
                                break;
                        }
                        base_produtos << campo1 << "," << campo2 << endl;
                }
                
                remove("base_produtos.csv");
                rename("novo.csv", "base_produtos.csv");        
        }
        
        else{
                
                base_produtos.open("base_produtos.csv", ios_base::app);
                base_produtos << nome_do_produto << "," << preco_do_produto << endl;
                base_produtos.close();
        }
                
        return 0;
}

int Loja::MostraProdutos(){
// Exibe todos os produtos cadastrados na base
        int contador = 1;
        string nome_do_produto, preco_do_produto;

        ifstream base_produtos;
        base_produtos.open("base_produtos.csv");


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

int Loja::RemoveProduto(){
// Remove um produto com base no código especificado na funcao MostraProdutos
        int codigo;
        string linha;

        cout << "Digite o código do produto a ser removido:";
        cin >> codigo;

        ifstream arq1;
        ofstream arq2;
        arq1.open("base_produtos.csv");
        arq2.open("novo.csv");

        for (int i = 1; i < codigo; i++){

                getline(arq1, linha, '\n' );
                arq2 << linha << endl;
        }

        getline(arq1, linha, '\n' );
        arq2 << "Produto removido,0.00" << endl;
        
        while (!arq1.eof()){

                getline(arq1, linha, '\n' );
                if (linha == ""){
                        break;
                }
                arq2 << linha << endl;
        }
        remove("base_produtos.csv");
        rename("novo.csv", "base_produtos.csv");
        cout << "Produto removido com sucesso" << endl;

        return 0;
}
