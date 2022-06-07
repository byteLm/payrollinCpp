#include "gerenciamento.h"

GerenciaBD::GerenciaBD(){
    this->arq.open("funcionarios.txt", ios::app);
    if(!arq.is_open()){
        cout << "Erro ao abrir arquivo" << endl;
    }
};
GerenciaBD::~GerenciaBD(){
    this->arq.close();
};
void GerenciaBD::listarFuncionarios(){
    //imprimindo cada linha do arquivo que começa com o caracter 'O'
    string linha;
    ifstream arq("funcionarios.txt");
    if(arq.is_open()){
        while(getline(arq, linha)){
            if(linha[0] == 'O'){
                cout << linha << endl;
            }
        }
    }
    else{
        cout << "Erro ao abrir arquivo" << endl;
    }
};
//void GerenciaBD::listarFuncionarios(int desig);
//void GerenciaBD::listarFuncionarios(string nome);
void GerenciaBD::cadastrarOperador(mFuncionario novo){
    
    string operador = "O,"+novo.getCodigo()+","+novo.getNome()+","+novo.getEndereco()+","+novo.getTelefone()+","+novo.getDataIngresso()+","+to_string(novo.getSalario())+","+to_string(novo.getDesig())+"\n";
    // abrindo o arquivo:
    this->arq.open("arquivo.txt", ios::app);
    // escrevendo a frase no arquivo:
    arq << operador;
    // fechando o arquivo:
    arq.close();
};
//void GerenciaBD::cadastrarGerente(c1Gerente novo);
//void GerenciaBD::cadastrarDiretor(c2Diretor novo);
//void GerenciaBD::cadastrarPresidente(c3Presidente novo);
//void GerenciaBD::consulta(int tipo); // 1 - codigo, 2 - nome, 3 - desig, 4 - salario, 5 - data de ingresso, 6 - area de supervisao, 7 - area de formacao, 8 - formMax

/*
// Adicionar funcionario:
            cout << "Adicionar funcionario\n";
            cout << "Digite o codigo do funcionario: ";
            string codigo;
            cin >> codigo;
            cout << "Digite o nome do funcionario: ";

            cin.ignore();

            string nome;
            getline(cin, nome);
            
            cout << "Digite o endereco do funcionario: \n";
            string endereco;
            
            getline(cin, endereco);
            cout << "Digite o telefone do funcionario: \n";
            
            string telefone;
            getline(cin, telefone);
            
            cout << "Digite a data de ingresso do funcionario: \n";
            string dataIngresso;    
            getline(cin, dataIngresso);
            cout << "Digite o salario do funcionario: \n";
            float salario;
            cin >> salario;
            cout << "Digite o codigo do desig do funcionario: \n";
            int desig;
            cin >> desig;

            // Criando um TXT para salvar os dados:
            ofstream arquivo;
            // atribuindo uma frase aleatoria nesse arquivo:
            string funcionario = "O,"+(codigo)+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+","+to_string(desig)+"\n";
            // abrindo o arquivo:
            arquivo.open("arquivo.txt", ios::app);
            // escrevendo a frase no arquivo:
            arquivo << funcionario;
            // fechando o arquivo:
            arquivo.close();
*/