#include "gerenciamento.h"

void imprimeMenu(){
    cout << "O que você deseja fazer?\n";
    cout << "1 - Adicionar funcionario\n";
    cout << "2 - Remover funcionario\n";
    cout << "3 - Aumentar salario\n";
    cout << "4 - Consultar Funcionario\n";
    cout << "5 - Editar funcionario \n";
    cout << "6 - Listar Funcionarios\n";
    cout << "7 - Sair\n";
}
int main (){
    int opcao, desig;
    int tipoTemp;
    string temp;
    GerenciaBD gerencia;

    while(1){ 
        
        imprimeMenu();
        cin >> opcao;
        
        switch(opcao){
            case 1:
                cout << "Digite o tipo de funcionario: \n";
                cout << "1 - Operador\n";
                cout << "2 - Gerente\n";
                cout << "3 - Diretor\n";
                cout << "4 - Presidente\n";
                cin >> desig;
                gerencia.cadastrarFuncionario(desig);
                break;
            case 2:
                cout << "Digite o codigo do funcionario: \n";
                cin.ignore();
                getline(cin, temp);
                gerencia.removerFuncionario(temp);
                break;
            case 3: 
                cout << "Rotina de aumento!\n";
                cout << "Voce deseja aumentar um salario especifico ou executar a rotina para todos?\n";
                cout << "1 - Especifico\n";
                cout << "2 - Todos\n";
                cin >> tipoTemp;
                if(tipoTemp == 1){
                    cout << "Digite o codigo do funcionario: \n";
                    cin.ignore();
                    getline(cin, temp);
                    tipoTemp = gerencia.retornaTipo(temp);
                    if(tipoTemp == 1){
                        cout << "Consultando operario...\n";
                        mFuncionario operario = gerencia.consultaOperario(temp);
                        cout << "Operario." << endl;
                        cout << "Codigo: " << operario.getCodigo() << endl;
                        cout << "Nome: " << operario.getNome() << endl;
                        cout << "Salario: " << operario.getSalario() << endl;
                        
                        cout << "Deseja aumentar o salario?\n";
                        cout << "1 - Sim\n";
                        cout << "2 - Nao\n";
                        cin >> tipoTemp;
                        if(tipoTemp == 1){
                            cout << "Aumentando salario...\n";
                            aumentoSalario aumento = aumentoSalario();
                            operario.setSalario(aumento.aumentaSalario(tipoTemp, operario.getSalario()));
                            cout << "Salario atualizado: " << operario.getSalario() << endl;
                            cout << "Você confirma o aumento?\n";
                            cout << "1 - Sim\n";
                            cout << "2 - Nao\n";
                            cin >> tipoTemp;
                            if(tipoTemp == 1){
                                gerencia.atualizaOperario(operario);
                                cout << "Salario atualizado com sucesso!\n";
                                aumento.~aumentoSalario();
                            }else{
                                cout << "Salario não foi atualizado!\n";
                            }
                        }
                    };
                }else if(tipoTemp == 2){
                    gerencia.aumentaSalarios();
                }

                break;
            case 4:
                cout << "Digite o código do funcionário.\n";
                cin.ignore();
                getline(cin, temp);
                tipoTemp = gerencia.retornaTipo(temp);  
                if(tipoTemp == 1){
                    cout << "Consultando operario...\n";
                    mFuncionario operario = gerencia.consultaOperario(temp);
                    operario.imprime();
                    operario.~mFuncionario();
                }else if(tipoTemp == 2){
                    cout << "Consultando gerente...\n";
                    mFuncionario gerente = gerencia.consultaGerente(temp);
                    gerente.imprime();
                    gerente.~mFuncionario();
                }else if(tipoTemp == 3){
                    cout << "Consultando diretor...\n";
                    mFuncionario diretor = gerencia.consultaDiretor(temp);
                    diretor.imprime();
                    diretor.~mFuncionario();
                }else if(tipoTemp == 4){
                    cout << "Consultando presidente...\n";
                    mFuncionario presidente = gerencia.consultaPresidente(temp);
                    presidente.imprime();
                    presidente.~mFuncionario();
                }
                break;    
            case 5:
                cout << "Digite o código do funcionário.\n";
                cin.ignore();
                getline(cin, temp);
                tipoTemp = gerencia.retornaTipo(temp);
                gerencia.editaFuncionario(temp, tipoTemp);
                break;
            case 6:
                cout << "Listando funcionarios!" << endl;
                cout << "Listar todos os funcionarios ou deseja filtrar por cargo?\n";
                cout << "0 - Todos\n";
                cout << "1 - Somente Operadores.\n";
                cout << "2 - Somente Gerentes.\n";
                cout << "3 - Somente Diretores.\n";
                cout << "4 - Somente Presidentes.\n";
                cout << "5 - Filtrar por parâmetro parcial (busca ampla).\n";
                cout << "6 - Sair\n";
                tipoTemp = 0;
                cin >> tipoTemp;
                if(tipoTemp == 0){
                    gerencia.listarFuncionarios(0, "");
                }else if(tipoTemp == 1){
                    gerencia.listarFuncionarios(1, "");
                }else if(tipoTemp == 2){
                    gerencia.listarFuncionarios(2, "");
                }else if(tipoTemp == 3){
                    gerencia.listarFuncionarios(3, "");
                }else if(tipoTemp == 4){
                    gerencia.listarFuncionarios(4, "");
                }else if(tipoTemp == 5){
                    cout << "Digite a palavra-chave desejada: \n";
                    cin.ignore();
                    getline(cin, temp);
                    gerencia.listarFuncionarios(100, temp);
                }else if(tipoTemp == 6){
                    cout << "Saindo...\n";
                    continue;
                } else{
                    cout << "Opção inválida.\n";
                }
                break;
            case 7:
                cout << "Saindo...\n";
                return 0;
            cout << "Ok!";
            default:
                cout << "Opção inválida!\n";
                break;
        }
    }
}
