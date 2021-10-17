#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

struct produto{
// Struct que vai armazenar as informações sobre os produtos. Futuramente uma classe
string nome;
int codigo;
float preco;

};

int main(){

    int opcao;
    int contador = 0;
    int aux;
    produto produtos[20];
    do{
        // Menu de opções, variando com a escolha e fechando caso a escolha seja 0 
        cout << "0 - Sair"<<endl;
        cout << "1 - Verificar produtos cadastrados"<<endl;
        cout << "2 - Cadastrar produto"<<endl;
        cout << "3 - Remover produto"<<endl;
        cin >> opcao;

        switch(opcao){
    
            case 0:
                    // Saída do programa
                    cout << "Saindo..."<<endl;
                    break;

            case 1:
                    /*  Percorre os produtos que possuem valor não vazio no campo do nome
                        e exibe na tela */
                    aux = 0;

                    while (produtos[aux].nome != ""){

                        cout << "Produto: ";
                        cout << produtos[aux].nome;
                        cout << "  Codigo: ";
                        cout << produtos[aux].codigo;
                        cout << "  Preco: R$";
                        cout << produtos[aux].preco<<endl;
                        aux++;
                    }
                    system("pause");
                    break;

            case 2:
                    /*  Insere cada informação do produto no campo desejado.
                        Futuras modificações serão feitas para funcionar de forma dinâmica*/
                    cout << "Digite o nome do produto: ";
                    cin >> produtos[contador].nome;
                    cout << "Digite o codigo do produto: ";
                    cin >> produtos[contador].codigo;
                    cout << "Digite o preco do produto: ";
                    cin >> produtos[contador].preco;

                    contador++;
                    break;

            case 3:
                    // Remove o produto com base no código.
                    int codigo;
                    aux = 0;

                    cout << "Digite o codigo do produto a ser removido: ";
                    cin >> codigo;

                    while (true){
                        /*  percorre toda a lista com os produtos até que encontre
                            um produto com o código equivalente ao informado para ser removido,1
                            então, faz a "remoção" */
                        if (produtos[aux].codigo == codigo){

                            produtos[aux].nome = "Produto removido";
                            produtos[aux].codigo = 0;
                            produtos[aux].preco = 0;

                            break;

                        }

                        aux++;

                    }

                    cout << "Produto removido com sucesso!"<<endl;
                    system("pause");

        };

    }while(opcao);

}