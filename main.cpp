#include "FolhaDePagamento.h"


void imprimeMenu(){
    cout << "O que você deseja fazer?\n";
    cout << "1 - Adicionar funcionario\n";
    cout << "2 - Remover funcionario\n";
    cout << "3 - Aumentar salario\n";
    cout << "4 - Consultar Funcionario\n";
    cout << "5 - Editar funcionario \n";
    cout << "6 - Listar Funcionarios\n";
    cout << "7 - Calcular salario liquido funcionário\n";
    cout << "8 - Calcular FOLHA DA EMPRESA MENSAL\n";
    cout << "9 - Calcular FOLHA DA EMPRESA ANUAL\n";
    cout << "10 - Sair\n";
    // Rotina Especial Escondida: case 11 ->
    // Aleatoriza todos os valores de horas trabalhadas e horas extras dos funcionários.
}
int main (){
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    int opcao, desig;
    int tipoTemp;
    string temp;
    GerenciaBD gerencia;


    while(1){ 
        imprimeMenu();
        cin >> opcao;
        
        switch(opcao){
            case 1:
                system("cls");
                cout << "Digite o tipo de funcionario que deseja cadastrar: \n";
                cout << "1 - Operador\n";
                cout << "2 - Gerente\n";
                cout << "3 - Diretor\n";
                cout << "4 - Presidente\n";
                cin >> desig;
                gerencia.cadastrarFuncionario(desig);

                break;
            case 2:
                system("cls");
                cout << "Digite o codigo do funcionario que deseja remover: \n";
                cin.ignore();
                getline(cin, temp);
                gerencia.removerFuncionario(temp);
                break;
            case 3: 
                system("cls");
                cout << "Rotina de aumento!\n";
                cout << "Voce deseja aumentar um salario especifico ou executar a rotina para todos?\n";
                cout << "1 - Especifico\n";
                cout << "2 - Todos\n";
                cin >> opcao;
                if(opcao == 1){
                    system("cls");
                    cout << "Digite o codigo do funcionario que você quer dar o aumento: \n";
                    cin.ignore();
                    getline(cin, temp);
                    gerencia.aumentaSalarioEspecifico(temp);
                }else if(opcao == 2){
                    gerencia.aumentaSalarios();
                    cout << "Rotina de aumento executada com sucesso!\n";
                }
                break;
            case 4:
                system("cls");
                cout << "Digite o código do funcionário que você deseja consultar: \n";
                cin.ignore();
                getline(cin, temp);
                tipoTemp = gerencia.retornaTipo(temp);  
                if(tipoTemp == 1){
                    system("cls");
                    cout << "Consultando operario...\n";
                    mFuncionario operario = gerencia.consultaOperario(temp);
                    operario.imprime();
                    operario.~mFuncionario();
                }else if(tipoTemp == 2){
                    system("cls");
                    cout << "Consultando gerente...\n";
                    c1Gerente gerente = gerencia.consultaGerente(temp);
                    gerente.imprime();
                    gerente.~c1Gerente();
                }else if(tipoTemp == 3){
                    system("cls");
                    cout << "Consultando diretor...\n";
                    c2Diretor diretor = gerencia.consultaDiretor(temp);
                    diretor.imprime();
                    diretor.~c2Diretor();
                }else if(tipoTemp == 4){
                    system("cls");
                    cout << "Consultando presidente...\n";
                    c3Presidente presidente = gerencia.consultaPresidente(temp);
                    presidente.imprime();
                    presidente.~c3Presidente();
                }else if(tipoTemp == -1){
                    cout << "Funcionario não encontrado!\n";
                }
                break;    
            case 5:
                system("cls");
                cout << "Digite o código do funcionário.\n";
                cin.ignore();
                getline(cin, temp);
                tipoTemp = gerencia.retornaTipo(temp);
                gerencia.editaFuncionario(temp, tipoTemp);
                break;
            case 6:
                system("cls");
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
                    cout << "Listando todos os funcionarios...\n";
                    system("pause");
                    gerencia.listarFuncionarios(0, "");
                }else if(tipoTemp == 1){
                    cout << "Listando somente os operadores...\n";
                    system("pause");
                    gerencia.listarFuncionarios(1, "");
                }else if(tipoTemp == 2){
                    cout << "Listando somente os gerentes...\n";
                    system("pause");
                    gerencia.listarFuncionarios(2, "");
                }else if(tipoTemp == 3){
                    cout << "Listando somente os diretores...\n";
                    system("pause");
                    gerencia.listarFuncionarios(3, "");
                }else if(tipoTemp == 4){
                    cout << "Listando somente os presidentes...\n";
                    system("pause");
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
                system("cls");
                cout << "Digite o codigo do funcionario.\n";
                cin.ignore();
                getline(cin, temp);
                cout << "Deseja a folha de pagamento descrita?\n";
                cout << "1 - Sim\n";
                cout << "2 - Nao\n";
                cin >> opcao;
                tipoTemp = gerencia.retornaTipo(temp);
                if(tipoTemp == -1){
                    cout << "Funcionario não encontrado!\n";
                }
                if(tipoTemp == 1){
                    mFuncionario temporario = gerencia.consultaOperario(temp);
                    FolhaDePagamento calc = FolhaDePagamento();
                    int totalHorasExtras = temporario.getTotalHorasExtras();
                    int totalDiasTrabalhados = temporario.getDiasTrabalhados();
                    cout << "Nome: " << temporario.getNome() << endl;
                    cout << "Salario Liquido: " << calc.calculaPagamentoFunc(temporario.getSalario(), totalHorasExtras, totalDiasTrabalhados) << endl;
                    if(opcao == 1){
                        cout << "Folha de Pagamento:\n";
                        calc.folhaDescritaFunc(temporario.getSalario(), totalHorasExtras, totalDiasTrabalhados, temporario.getNome(), temporario.getCodigo());
                    }
                    calc.~FolhaDePagamento();
                    temporario.~mFuncionario();
                }else if(tipoTemp == 2){
                    
                    c1Gerente temporario = gerencia.consultaGerente(temp);
                    FolhaDePagamento calc = FolhaDePagamento();
                    int totalHorasExtras = temporario.getTotalHorasExtras();
                    int totalDiasTrabalhados = temporario.getDiasTrabalhados();

                    cout << "Nome: " << temporario.getNome() << endl;
                    cout << "Salario Liquido: " << calc.calculaPagamentoFunc(temporario.getSalario(), totalHorasExtras, totalDiasTrabalhados) << endl;
                    if(opcao == 1){
                        cout << "Folha de Pagamento:\n";
                        calc.folhaDescritaFunc(temporario.getSalario(), totalHorasExtras, totalDiasTrabalhados, temporario.getNome(), temporario.getCodigo());
                    }
                    calc.~FolhaDePagamento();
                    temporario.~c1Gerente();

                }else if(tipoTemp == 3){
                    c2Diretor temporario = gerencia.consultaDiretor(temp);
                    FolhaDePagamento calc = FolhaDePagamento();
                    int totalHorasExtras = temporario.getTotalHorasExtras();
                    int totalDiasTrabalhados = temporario.getDiasTrabalhados();

                    cout << "Nome: " << temporario.getNome() << endl;
                    cout << "Salario Liquido: " << calc.calculaPagamentoFunc(temporario.getSalario(), totalHorasExtras, totalHorasExtras) << endl;
                    if(opcao == 1){
                        cout << "Folha de Pagamento:\n";
                        calc.folhaDescritaFunc(temporario.getSalario(), totalHorasExtras, totalDiasTrabalhados, temporario.getNome(), temporario.getCodigo());
                    }
                    calc.~FolhaDePagamento();
                    temporario.~c2Diretor();
                }else if(tipoTemp == 4){
                    c2Diretor temporario = gerencia.consultaDiretor(temp);
                    FolhaDePagamento calc = FolhaDePagamento();
                    int totalHorasExtras = temporario.getTotalHorasExtras();
                    int totalDiasTrabalhados = temporario.getDiasTrabalhados();
                    cout << "Nome: " << temporario.getNome() << endl;
                    cout << "Salario Liquido: " << calc.calculaPagamentoFunc(temporario.getSalario(), totalHorasExtras, totalDiasTrabalhados) << endl;
                    if(opcao == 1){
                        cout << "Folha de Pagamento:\n";
                        calc.folhaDescritaFunc(temporario.getSalario(), totalHorasExtras, totalDiasTrabalhados, temporario.getNome(), temporario.getCodigo());
                    }
                    calc.~FolhaDePagamento();
                    temporario.~c2Diretor();
                }
                break;
            case 8:
                system("cls");
                cout << "Você só poderá fazer essa emissão uma vez.\n";
                cout << "Deseja continuar?\n";
                cout << "1 - Sim\n";
                cout << "2 - Não\n";
                cin >> opcao;
                if(opcao == 1){
                    FolhaDePagamento folha = FolhaDePagamento();

                    int mesRef;
                    system("cls");
                    system("pause");
                    cout << "Por favor, digite o mes de referencia: " << endl;
                    cout << "Considere que a folha de pagamento só poderá ser gerada uma vez." << endl;
                    cout << "1 - Janeiro" << endl;
                    cout << "2 - Fevereiro" << endl;
                    cout << "3 - Março" << endl;
                    cout << "4 - Abril" << endl;
                    cout << "5 - Maio" << endl;
                    cout << "6 - Junho" << endl;
                    cout << "7 - Julho" << endl;
                    cout << "8 - Agosto" << endl;
                    cout << "9 - Setembro" << endl;
                    cout << "10 - Outubro" << endl;
                    cout << "11 - Novembro" << endl;
                    cout << "12 - Dezembro" << endl;
                    cin >> mesRef;
                    if(mesRef < 1 || mesRef > 12){
                        cout << "Mês inválido.\n";
                        continue;
                    }else{
                        folha.calculaFolhaEmpresa(mesRef);
                        folha.~FolhaDePagamento();
                    }
                    
                }else if(opcao == 2){
                    cout << "Saindo...\n";
                    continue;
                }
                break;        
            case 9:
                system("cls");
                cout << "Saindo...\n";
                return 0;
            case 11:
                gerencia.aleatorizaHD();
                cout << "Aleatorizado!\n";
                break;
            default:
                cout << "Opção inválida!\n";
                break;
            
        }
    }
}
