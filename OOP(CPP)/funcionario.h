#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED
#include <string>
using namespace std;

class Funcionario{

private:
    static string nome_adm;
    static string senha_adm;

protected:
    string funcao;
    string nome;
    string senha;
    
public:
    int Login();
};

class Gerente: private Funcionario{

public:
    int InsereProduto();
    int MostraProdutos();
    int RemoveProduto();
    int AlteraPreco();
};

class Vendedor: private Funcionario{

public:
    int VendeProduto();
};

class Administrador{

public:
    int ExibeFuncionarios();
    int AdicionaFuncionario();
    int RemoveFuncionario();
};

#endif //FUNCIONARIO_H_INCLUDED
