#include <iostream>
#include <cstdlib>
#include <string>
#include "funcionario.h"
using namespace std;


int main(){
        int opcao1, opcao2, tentativas = 3;
        Funcionario funcionario;
        Gerente gerente;
        Vendedor vendedor;
        Administrador adm;
        while (tentativas > 0){
                opcao1 = funcionario.Login();//recebe o valor correspondete à categoria do funcionário
                if(!opcao1){
                        tentativas--;
                        cout << "Tentativas restantes: " << tentativas << endl;
                }
                else{
                        tentativas = 3;
                        system("clear");
                }
                do{
                
                        switch (opcao1){
                                
                        case 0:
                                break;

                        case 1:

                                do{

                                        opcao2 = funcionario.MenuGerente();

                                        switch(opcao2){
                                
                                        case 0:
                                                system("clear");
                                                opcao1 = 0;
                                                break;

                                        case 1:
                                                gerente.MostraProdutos();
                                                break;

                                        case 2:
                                                gerente.InsereProduto();
                                                break;

                                        case 3:
                                                gerente.RemoveProduto();
                                                break;
                                        
                                        case 4:
                                                gerente.AlteraPreco();
                                                break;

                                        default:
                                                system("clear");
                                                cout << "Opcao inválida" << endl;

                                        };

                                }while(opcao2);

                                break;

                        case 2:

                                do{

                                        opcao2 = funcionario.MenuVendedor();

                                        switch(opcao2){
                                
                                        case 0:
                                                system("clear");
                                                opcao1 = 0;
                                                break;

                                        case 1:
                                                vendedor.VendeProduto();
                                                break;
                                        
                                        case 2:
                                                vendedor.AdicionaEstoque();
                                                break;

                                        default:
                                                system("clear");
                                                cout << "Opcao inválida" << endl;

                                        };

                                }while(opcao2);

                                break;

                        case 3:

                                do{

                                        opcao2 = funcionario.MenuAdm();

                                        switch(opcao2){
                                
                                        case 0:
                                                system("clear");
                                                opcao1 = 0;
                                                break;

                                        case 1:
                                                adm.ExibeFuncionarios();
                                                break;

                                        case 2:
                                                adm.AdicionaFuncionario();
                                                break;

                                        case 3:
                                                adm.RemoveFuncionario();
                                                break;

                                        default:
                                                system("clear");
                                                cout << "Opcao inválida" << endl;

                                        };

                                }while(opcao2);



                        }


                }while(opcao1);
        }
        cout << "Tentativas esgotadas, travando terminal..." << endl;   
        return 0;
}