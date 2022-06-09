#include "gerenciamento.h"

int main (){
    // Criação de um objeto do tipo funcionario e cout de todos os seus atributos:
    /*c3Presidente presidente = c3Presidente();
    cout << "Nome: " << presidente.getNome() << endl;
    cout << "Salario: " << presidente.getSalario() << endl;
    cout << "Area Supervisao: " << presidente.getAreaSupervisao() << endl;
    cout << "TESTE DE ALTERAÇAO 2.2.55";
    */
    while(1){

        
        cout << "O que você deseja fazer?\n";
        cout << "1 - Adicionar funcionario\n";
        cout << "2 - Remover funcionario\n";
        cout << "3 - Aumentar salario\n";
        cout << "4 - Listar funcionarios\n";
        cout << "5 - Sair\n";
        int opcao, desig;
        string temp;
        cin >> opcao;
        
        
        if(opcao==1){
            GerenciaBD gerencia;
            cout << "Digite o tipo de funcionario: \n";
            cout << "1 - Operador\n";
            cout << "2 - Gerente\n";
            cout << "3 - Diretor\n";
            cout << "4 - Presidente\n";
            cin >> desig;
            gerencia.cadastrarFuncionario(desig);
        }else if(opcao == 2){
            GerenciaBD gerencia;
            cout << "Digite o codigo do funcionario: \n";
            cin.ignore();
            getline(cin, temp);
            gerencia.removerFuncionario(temp);
        }else if(opcao == 3){
            GerenciaBD gerencia;
            gerencia.listarFuncionarios();
        }else if(opcao == 4){
            GerenciaBD gerencia;
            string temp = "20210025323";
            gerencia.consulta(temp);
        }

        cout << "Ok!";
    }






}