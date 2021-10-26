#ifndef LOJA_H_INCLUDED
#define LOJA_H_INCLUDED
#include <string>
using namespace std;

class Loja{

    private:
    string base_produtos;
    
    public:
    int Menu();
    int InsereProduto();
    int MostraProdutos();
    int RemoveProduto();

};


#endif //LOJA_H_INCLUDED