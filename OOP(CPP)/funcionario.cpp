#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <termios.h>
#include <unistd.h>
#include "funcionario.h"
using namespace std;

string Funcionario::nome_adm = "adm";
string Funcionario::senha_adm = "adm";

int Funcionario::Login(){

    string campo1, campo2, campo3;
    bool credencial_nao_encontrada;
    int retorno = 0;

    cout << "Digite seu nome: ";
    cin >> this->nome;
    
    termios oldt;
    tcgetattr(STDIN_FILENO, &oldt);
    termios newt = oldt;
    newt.c_lflag &= ~ECHO;
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    if (this->nome == nome_adm){//Login do adm
        
        cout << "Digite sua senha: ";
        cin >> senha;

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        if (senha == senha_adm){
            retorno = 3;
        }
        else{
            cout << "Credenciais incorretas" << endl;
        }

    }
    else{
        ifstream base_logins;
        base_logins.open("base_funcionarios.csv");

        while(getline(base_logins, campo1, ',')){
            
            credencial_nao_encontrada = false;
            if (campo1 == ""){

                credencial_nao_encontrada = true;
                break;
            }
            getline(base_logins, campo2, ',');

            if (campo2 == this->nome){

                getline(base_logins, campo3, '\n');
                break;
            }
            getline(base_logins, campo3, '\n');
            credencial_nao_encontrada = true;
        }
        if (credencial_nao_encontrada){
            retorno = 0;
            cout << "Credencial não encontrada" << endl;
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

        }
        else{

            cout << "Digite sua senha: ";
            cin >> senha;
            tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
            
            if (campo3 == senha){
                
                if (campo1 == "Gerente"){
                    retorno = 1;
                }
                else{
                    retorno = 2;
                }
            
            }
            else{

                cout << "Credenciais incorretas" << endl;
            }

        }
        base_logins.close();    
    }
    return retorno;
}

int Funcionario::MenuGerente(){
        
        cout << "Olá, " << this->nome << endl;
        cout << "Escolha uma opção" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Verificar produtos cadastrados" << endl;
        cout << "2 - Cadastrar produto" << endl;
        cout << "3 - Remover produto" << endl;
        cout << "4 - Alterar preco de algum produto" << endl;
        cin >> opcao;
        return opcao;
}

int Funcionario::MenuVendedor(){
        
        cout << "Olá, " << this->nome << endl;
        cout << "Escolha uma opção" << endl;
        cout << "0 - Sair" << endl;
        cout << "1 - Cadastrar uma venda" << endl;
        cout << "2 - Adicionar estoque" << endl;
        cin >> opcao;
        return opcao;
}

int Funcionario::MenuAdm(){

        cout << "Olá, administrador" << endl;
        cout << "Escolha uma opção" << endl;
        cout << "0 - Sair"<<endl;
        cout << "1 - Verificar funcionarios cadastrados" << endl;
        cout << "2 - Cadastrar funcionario" << endl;
        cout << "3 - Remover funcionario" << endl;
        cin >> opcao;
        return opcao;
}

int Gerente::MostraProdutos(){
    
    system("clear");
    int contador = 1;
    string nome_do_produto, preco_do_produto, estoque_do_produto;

    ifstream base_produtos;
    base_produtos.open("base_produtos.csv");


    while(getline(base_produtos, nome_do_produto, ',')){

        if (nome_do_produto == ""){
            break;
        }
        getline(base_produtos, preco_do_produto, ',');
        getline(base_produtos, estoque_do_produto, '\n');
        cout << "Nome do produto: " << nome_do_produto << " | Preco: R$" << preco_do_produto << " | Codigo: " << contador << endl;
        contador++;
    } 

    base_produtos.close();

    return 0;

}

int Gerente::InsereProduto(){
    
    system("clear");
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
                arq1.close();
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
                    
                base_produtos << nome_do_produto << "," << preco_do_produto << ",0" << endl;
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
        base_produtos << nome_do_produto << "," << preco_do_produto << ",0" << endl;
        base_produtos.close();
    }
    cout<< nome_do_produto << " adicionado com sucesso" << endl;
            
    return 0;
}

int Gerente::RemoveProduto(){

    int codigo;
    string linha;

    cout << "Digite o código do produto a ser removido: ";
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
    arq2 << "Produto removido,0.00,0" << endl;
    
    while (!arq1.eof()){

        getline(arq1, linha, '\n' );
        if (linha == ""){
            break;
        }
        arq2 << linha << endl;
    }
    remove("base_produtos.csv");
    rename("novo.csv", "base_produtos.csv");
    system("clear");
    cout << "Produto removido com sucesso" << endl;

    return 0;
}

int Gerente::AlteraPreco(){

    int codigo;
    string linha, preco_novo, campo1, campo2, campo3;

    cout << "Digite o código do produto que terá o preco alterado: ";
    cin >> codigo;
    cout << "Digite o novo preco do produto: ";
    cin >> preco_novo;

    ifstream arq1;
    ofstream arq2;
    arq1.open("base_produtos.csv");
    arq2.open("novo.csv");

    for (int i = 1; i < codigo; i++){

        getline(arq1, linha, '\n' );
        arq2 << linha << endl;
    }

    getline(arq1, campo1, ',' );
    getline(arq1, campo2, ',' ); 
    getline(arq1, campo3, '\n');
    arq2 << campo1 << "," << preco_novo << "," << campo3 << endl;
    
    while (!arq1.eof()){

        getline(arq1, linha, '\n' );
        if (linha == ""){
            break;
        }
        arq2 << linha << endl;
    }
    remove("base_produtos.csv");
    rename("novo.csv", "base_produtos.csv");
    system("clear");
    cout << "Preco modificado com sucesso" << endl;

    return 0;
}

int Vendedor::VendeProduto(){
    system("clear");
    int quantidade_entrada, codigo_entrada, contador = 1;
    string nome_do_produto, preco_do_produto, estoque_atual, linha, campo1, campo2, campo3;
    float preco_total;

    ifstream base_produtos;
    base_produtos.open("base_produtos.csv");

    while(getline(base_produtos, nome_do_produto, ',')){

        if (nome_do_produto == ""){

            break;
        }
        getline(base_produtos, preco_do_produto, ',');
        getline(base_produtos, estoque_atual, '\n');
        cout << "Nome do produto: " << nome_do_produto << " | Preco: R$" << preco_do_produto << " | Quantidade disponível: " << estoque_atual << " | Codigo: " << contador << endl;
        contador++;
    } 

    base_produtos.close();

    cout << "Digite o código do produto que será vendido: " << endl;
    cin >> codigo_entrada;
    cout << "Digite a quantidade que será vendida do produto: " << endl;
    cin >> quantidade_entrada;

    base_produtos.open("base_produtos.csv");

    for (int i = 1; i < codigo_entrada; i++){

        getline(base_produtos, linha, '\n' );
    }

    getline(base_produtos, nome_do_produto, ',');
    getline(base_produtos, preco_do_produto, ',');
    getline(base_produtos, estoque_atual, '\n');

    base_produtos.close();

    if (quantidade_entrada > stoi(estoque_atual) || quantidade_entrada < 0){
        cout << "Quantia inválida" << endl;
    }
    else{

        ifstream arq1;
        ofstream arq2;
        arq1.open("base_produtos.csv");
        arq2.open("novo.csv");

        for (int i = 1; i < codigo_entrada; i++){

            getline(arq1, linha, '\n' );
            arq2 << linha << endl;
        }

        getline(arq1, campo1, ',' );
        getline(arq1, campo2, ',' ); 
        getline(arq1, campo3, '\n');
        arq2 << campo1 << "," << campo2 << "," << to_string(stoi(campo3) - quantidade_entrada) << endl;
        
        while (!arq1.eof()){

            getline(arq1, linha, '\n' );
            if (linha == ""){
                break;
            }
            arq2 << linha << endl;
        }
        remove("base_produtos.csv");
        rename("novo.csv", "base_produtos.csv");

        preco_total = (stof(preco_do_produto) * quantidade_entrada);
        system("clear");
        cout << fixed << setprecision(2) << "O total deu: R$" << preco_total << endl;

    }


    return 0;
}

int Vendedor::AdicionaEstoque(){

    system("clear");
    int codigo, contador = 1;
    string linha, novo_estoque, campo1, campo2, campo3, nome_do_produto, preco_do_produto, estoque_do_produto;

    ifstream base_produtos;
    base_produtos.open("base_produtos.csv");

    while(getline(base_produtos, nome_do_produto, ',')){

        if (nome_do_produto == ""){
            break;
        }
        getline(base_produtos, preco_do_produto, ',');
        getline(base_produtos, estoque_do_produto, '\n');
        cout << "Nome do produto: " << nome_do_produto << " Codigo: " << contador << endl;
        contador++;
    } 

    base_produtos.close();

    cout << "Digite o código do produto que terá o estoque incrementado: ";
    cin >> codigo;
    cout << "Digite a quantidade a ser adicionada: ";
    cin >> novo_estoque;

    if(stoi(novo_estoque) < 0){
        system("clear");
        cout << "Valor inválido..." << endl;
        return 0;
    }
    else{

        ifstream arq1;
        ofstream arq2;
        arq1.open("base_produtos.csv");
        arq2.open("novo.csv");

        for (int i = 1; i < codigo; i++){

            getline(arq1, linha, '\n' );
            arq2 << linha << endl;
        }

        getline(arq1, campo1, ',' );
        getline(arq1, campo2, ',' ); 
        getline(arq1, campo3, '\n');
        arq2 << campo1 << "," << campo2 << "," << to_string(stoi(campo3) + stoi(novo_estoque)) << endl;
        
        while (!arq1.eof()){

            getline(arq1, linha, '\n' );
            if (linha == ""){
                break;
            }
            arq2 << linha << endl;
        }
        remove("base_produtos.csv");
        rename("novo.csv", "base_produtos.csv");
        system("clear");
        cout << "Estoque adicionado com sucesso" << endl;

        return 0;
    }

}

int Administrador::ExibeFuncionarios(){

    system("clear");
    string campo1, campo2, campo3;

    ifstream base_funcionarios;
    base_funcionarios.open("base_funcionarios.csv");


    while(getline(base_funcionarios, campo1, ',')){

        if (campo1 == ""){
            break;
        }
        getline(base_funcionarios, campo2, ',');
        cout << "Nome do funcionario: " << campo2 << " Funcao: " << campo1 << endl;
        getline(base_funcionarios, campo3, '\n');

    } 

    base_funcionarios.close();

    return 0;
}

int Administrador::AdicionaFuncionario(){

    string nome_do_funcionario, senha_do_funcionario;
    int funcao_do_funcionario;
    ofstream base_funcionarios;
    
    cout << "Escolha a funcao do funcionario" << endl;
    cout << "0 - Gerente" << endl;
    cout << "1 - Vendedor" << endl;
    cin >> funcao_do_funcionario;
    cout << "Digite o nome do funcionario: " << endl;
    cin >> nome_do_funcionario;
    cout << "Digite a senha do funcionario: " << endl;
    cin >> senha_do_funcionario;

    base_funcionarios.open("base_funcionarios.csv", ios_base::app);
    if (!funcao_do_funcionario){
        base_funcionarios << "Gerente," << nome_do_funcionario << "," << senha_do_funcionario << endl;
    }
    else{
        base_funcionarios << "Vendedor," << nome_do_funcionario << "," << senha_do_funcionario << endl;
    }
    base_funcionarios.close();

    return 0;
}

int Administrador::RemoveFuncionario(){

    int codigo;
    string linha, campo1, campo2, campo3, nome_a_remover;

    cout << "Digite o nome do funcionario a ser desligado: ";
    cin >> nome_a_remover;

    ifstream arq1;
    ofstream arq2;
    arq1.open("base_funcionarios.csv");
    arq2.open("novo.csv");

    while (!arq1.eof()){

        getline(arq1, campo1, ',' );
        getline(arq1, campo2, ',' );
        getline(arq1, campo3, '\n' );
        if (campo2 == nome_a_remover){
            break;
        }
        arq2 << campo1 << "," << campo2 << "," << campo3 << endl;
    }
    while (!arq1.eof()){
        
        getline(arq1, linha, '\n');
        if (linha == ""){
            break;
        }
        arq2 << linha << endl;
    }

    remove("base_funcionarios.csv");
    rename("novo.csv", "base_funcionarios.csv");
    cout << "Funcionario desligado." << endl;

    return 0;
}