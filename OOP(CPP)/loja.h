#ifndef LOJA_H_INCLUDED
#define LOJA_H_INCLUDED
#include <string>
#include <vector>
using namespace std;

struct produto{
    // Struct que vai armazenar as informações sobre os produtos. Futuramente uma classe
    string nome;
    // int codigo;
    float preco;

};

int Menu();
int InsereProduto();
int MostraProdutos();
int RemoveProduto();

#endif //LOJA_H_INCLUDED