#include <iostream>
#include <cstdlib>
#include <string>
#include "loja.h"
#include "funcionario.h"
using namespace std;


int main(){
        Loja mercadinho;
        int opcao1, opcao2, tentativas = 3;
        Funcionario funcionario;
        Gerente gerente;
        Vendedor vendedor;
        Administrador adm;
        while (tentativas > 0){
                opcao1 = funcionario.Login();
                if(!opcao1){
                        tentativas--;
                        cout << "Tentativas restantes: " << tentativas << endl;
                }
                else{
                        tentativas = 3;
                }
                do{
                
                        switch (opcao1){
                                
                        case 0:

                                break; 
                        case 1:

                                do{

                                        opcao2 = mercadinho.MenuGerente();

                                        switch(opcao2){
                                
                                        case 0:

                                                cout << "Saindo..."<<endl;
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

                                        };

                                }while(opcao2);

                                break;

                        case 2:

                                do{

                                        opcao2 = mercadinho.MenuVendedor();

                                        switch(opcao2){
                                
                                        case 0:

                                                cout << "Saindo..."<<endl;
                                                opcao1 = 0;
                                                break;

                                        case 1:

                                                vendedor.VendeProduto();

                                        };

                                }while(opcao2);

                                break;

                        case 3:

                                do{

                                        opcao2 = mercadinho.MenuAdm();

                                        switch(opcao2){
                                
                                        case 0:

                                                cout << "Saindo..."<<endl;
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

                                        };

                                }while(opcao2);



                        }


                }while(opcao1);
        }       
        return 0;
}