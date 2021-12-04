#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED
#include <string>
using namespace std;

class Funcionario{

private:
    static string nome_adm;
    static string senha_adm;
    int opcao;

protected:
    string nome;
    string senha;
    
public:
    int Login();
    int MenuGerente();
    int MenuVendedor();
    int MenuAdm();
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
    int AdicionaEstoque();
};

class Administrador{

public:
    int ExibeFuncionarios();
    int AdicionaFuncionario();
    int RemoveFuncionario();
};

#endif //FUNCIONARIO_H_INCLUDED
