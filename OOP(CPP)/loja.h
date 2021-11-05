#ifndef LOJA_H_INCLUDED
#define LOJA_H_INCLUDED
#include <string>
using namespace std;

class Loja{

    private:
        int opcao;

    public:
        int MenuGerente();
        int MenuVendedor();
        int MenuAdm();
};

#endif //LOJA_H_INCLUDED