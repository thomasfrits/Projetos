#ifndef LOJA_H_INCLUDED
#define LOJA_H_INCLUDED
#include <string>
using namespace std;

struct produto{
    // Struct que vai armazenar as informações sobre os produtos. Futuramente uma classe
    string nome;
    int codigo;
    float preco;

};

int Menu();
int MostraProdutos();

#endif //LOJA_H_INCLUDED