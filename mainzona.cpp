/*
O sistema deve possuir os tipos Operador, Gerente, Diretor e Presidente. Todos devem possuir
os atributos: número do código do funcionário, nome, endereço, telefone, data de ingresso,
designação (indica se é operador, gerente, diretor ou presidente) e salário.
*/

/*
Designação são de acordo com a tabela abaixo:
1 - Operador
2 - Gerente
3 - Diretor 
4 - Presidente
*/


#include <iostream>
#include <string.h>

using namespace std;

class mFuncionario
{
    public:
        mFuncionario();
        mFuncionario(string codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig);

        
        //Getters
        string getCodigo();
        int getDesig();
        string getNome();
        string getEndereco();
        string getTelefone();
        string getDataIngresso();
        float getSalario();

        //Setters
        void setCodigo(string codigo);
        void setDesig(int desig);
        void setNome(string nome);
        void setEndereco(string endereco);
        void setTelefone(string telefone);
        void setDataIngresso(string dataIngresso);
        void setSalario(float salario);

    protected:
        string codigo;
        int desig;

        string nome;
        string endereco;
        string telefone;
        string dataIngresso;
        float salario;

};
mFuncionario::mFuncionario(){
    codigo = "0";
    desig = 0;
    nome = "";
    endereco = "";
    telefone = "";
    dataIngresso = "";
    salario = 0;
}
mFuncionario::mFuncionario(string codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig){
    this->codigo = codigo;
    this->desig = desig;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataIngresso = dataIngresso;
    this->salario = salario;
};
string mFuncionario::getCodigo(){
    return this->codigo;
};
int mFuncionario::getDesig(){
    return this->desig;
};
string mFuncionario::getNome(){
    return this->nome;
};
string mFuncionario::getEndereco(){
    return this->endereco;
};
string mFuncionario::getTelefone(){
    return this->telefone;
};
string mFuncionario::getDataIngresso(){
    return this->dataIngresso;
};
float mFuncionario::getSalario(){
    return this->salario;
};

//Setters
void mFuncionario::setCodigo(string codigo){
    this->codigo = codigo;
};
void mFuncionario::setDesig(int desig){
    this->desig = desig;
};
void mFuncionario::setNome(string nome){
    this->nome = nome;
};
void mFuncionario::setEndereco(string endereco){
    this->endereco = endereco;
};
void mFuncionario::setTelefone(string telefone){
    this->telefone = telefone;
};
void mFuncionario::setDataIngresso(string dataIngresso){
    this->dataIngresso = dataIngresso;
};
void mFuncionario::setSalario(float salario){
    this->salario = salario;
};


//Classe gerente herda de mFuncionario
class c1Gerente : public mFuncionario{

    public:
        c1Gerente();
        c1Gerente(int codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig, string AreaSupervisao);
        void setAreaSupervisao(string areaSuperfisao);
        string getAreaSupervisao();
    protected:
        string areaSupervisao;



};
c1Gerente::c1Gerente(){
    this->areaSupervisao = "";
}
c1Gerente::c1Gerente(int codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig, string AreaSupervisao){
    this->codigo = codigo;
    this->desig = desig;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataIngresso = dataIngresso;
    this->salario = salario;
    this->areaSupervisao = AreaSupervisao;

}
void c1Gerente::setAreaSupervisao(string areaSuperfisao){
    this->areaSupervisao = areaSuperfisao;
}
string c1Gerente::getAreaSupervisao(){
    return areaSupervisao;
}
class c2Diretor : public c1Gerente{

    public:
        c2Diretor();
        c2Diretor(int codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig, string AreaSupervisao, string areaFormacao);
        void setAreaFormacao(string areaFormacao);
        string getAreaFormacao();

    protected:
        string areaFormacao;
    
    


};
c2Diretor::c2Diretor(){
    this->areaFormacao = "";
    this->codigo = codigo;
    this->desig = desig;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataIngresso = dataIngresso;
    this->salario = salario;
    this->areaSupervisao = "";
};
c2Diretor::c2Diretor(int codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig, string AreaSupervisao, string areaFormacao){
    this->areaFormacao = areaFormacao;
    this->codigo = codigo;
    this->desig = desig;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataIngresso = dataIngresso;
    this->salario = salario;
    this->areaSupervisao = AreaSupervisao;
    this->areaFormacao = areaFormacao;
};
void c2Diretor::setAreaFormacao(string areaFormacao){
    this->areaFormacao = areaFormacao;
};
string c2Diretor::getAreaFormacao(){
    return areaFormacao;
};
class c3Presidente : public c2Diretor{
    
    public:
        c3Presidente();
        c3Presidente(int codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig, string AreaSupervisao, string areaFormacao, string formMax);
        void setFormacaoMax(string FormacaoMax);
        string getFormacaoMax();
        
    protected:
        string FormacaoMax;
    
    
    
};
c3Presidente::c3Presidente(){
    this->FormacaoMax = "";
    this->codigo = codigo;
    this->desig = desig;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataIngresso = dataIngresso;
    this->salario = salario;
    this->areaSupervisao = "";
};
c3Presidente::c3Presidente(int codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig, string AreaSupervisao, string areaFormacao, string formMax){
    this->FormacaoMax = formMax;
    this->codigo = codigo;
    this->desig = desig;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataIngresso = dataIngresso;
    this->salario = salario;
    this->areaSupervisao = AreaSupervisao;
    this->areaFormacao = areaFormacao;
};
void c3Presidente::setFormacaoMax(string FormacaoMax){
    this->FormacaoMax = FormacaoMax;
};
string c3Presidente::getFormacaoMax(){
    return FormacaoMax;
};


#include <fstream>
class GerenciaBD : public c3Presidente, ofstream{

    public:
        GerenciaBD();
        virtual ~GerenciaBD();
        void listarFuncionarios();
        void listarFuncionarios(int desig);
        void listarFuncionarios(string nome);
        void cadastrarFuncionario(int tipo);
        void cadastrarGerente(c1Gerente novo);
        void cadastrarDiretor(c2Diretor novo);
        void cadastrarPresidente(c3Presidente novo);
        void removerFuncionario(int codigo);
        void consulta(int tipo); // 1 - codigo, 2 - nome, 3 - desig, 4 - salario, 5 - data de ingresso, 6 - area de supervisao, 7 - area de formacao, 8 - formMax
    protected:
        ofstream arq;
};


GerenciaBD::GerenciaBD(){
};
GerenciaBD::~GerenciaBD(){

};
void GerenciaBD::listarFuncionarios(){
    //imprimindo cada linha do arquivo que começa com o caracter 'O'
    string linha;
    ifstream arq("funcionarios.txt");
    if(arq.is_open()){
        while(getline(arq, linha)){
            if(linha[0]=='1'){
                cout << linha << endl;
            }
            
        };
    }
    else{
        cout << "Erro ao abrir arquivo" << endl;
    }
};
//void GerenciaBD::listarFuncionarios(int desig);
//void GerenciaBD::listarFuncionarios(string nome);
/*void GerenciaBD::cadastrarOperador(mFuncionario novo){
    arq.open("funcionarios.txt", ios::app);
    string operador = "O,"+novo.getCodigo()+","+novo.getNome()+","+novo.getEndereco()+","+novo.getTelefone()+","+novo.getDataIngresso()+","+to_string(novo.getSalario())+","+to_string(novo.getDesig())+"\n";
    // abrindo o arquivo:
    // escrevendo a frase no arquivo:
    arq << operador;
    // fechando o arquivo:
    arq.close();
};*/


/*
● Gerente: nome da área de supervisão
● Diretor: nome da área de supervisão e área de formação
● Presidente: área de formação e qual formação acadêmica máxima (por exemplo,
especialista, mestre, doutor...)
*/
void GerenciaBD::cadastrarFuncionario(int tipo){
    arq.open("funcionarios.txt", ios::app);
    string funcionario;
    string codigo;
    float salario;
    string nome, endereco, telefone, dataIngresso, areaSupervisao, areaFormacao, formMax;
    switch(tipo){
        case 1:
            cout << "Adicionando Operador...\n";
            cout << "Digite o codigo do funcionario: ";
            cin >> codigo;
            cout << "Digite o nome do funcionario: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Digite o endereco do funcionario: \n";
            getline(cin, endereco);
            cout << "Digite o telefone do funcionario: \n";
            getline(cin, telefone);
            cout << "Digite a data de ingresso do funcionario: \n";
            getline(cin, dataIngresso);
            cout << "Digite o salario do funcionario: \n";
            cin >> salario;
            // Para o arquivo:
            funcionario = to_string(tipo)+","+codigo+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+","+"\n";            
            arq << funcionario;
            arq.close();
            break;
        case 2:
            cout << "Adicionando Gerente...\n";
            cout << "Digite o codigo do gerente: ";
            cin >> codigo;
            cout << "Digite o nome do gerente: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Digite o endereco do gerente: \n";
            getline(cin, endereco);
            cout << "Digite o telefone do gerente: \n";
            getline(cin, telefone);
            cout << "Digite a data de ingresso do gerente: \n";
            getline(cin, dataIngresso);
            cout << "Digite a área de supervisão do gerente: \n";
            cin >> areaSupervisao;
            cout << "Digite o salario do gerente: \n";
            cin >> salario;
            // Para o arquivo:
            funcionario = to_string(tipo)+","+codigo+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+","+areaSupervisao+"\n";            
            arq << funcionario;
            arq.close();
            break;
        case 3:
            cout << "Adicionando Diretor...\n";
            cout << "Digite o codigo do diretor: ";
            cin >> codigo;
            cout << "Digite o nome do diretor: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Digite o endereco do diretor: \n";
            getline(cin, endereco);
            cout << "Digite o telefone do diretor: \n";
            getline(cin, telefone);
            cout << "Digite a data de ingresso do diretor: \n";
            getline(cin, dataIngresso);
            cout << "Digite a área de supervisão do diretor: \n";
            cin >> areaSupervisao;
            cout << "Digite a área de formação do diretor: \n";
            cin >> areaFormacao;
            cout << "Digite o salario do diretor: \n";
            cin >> salario;
            // Para o arquivo:
            funcionario = to_string(tipo)+","+codigo+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+","+areaSupervisao+","+areaFormacao+"\n";            
            arq << funcionario;
            arq.close();
            break;
        case 4:
            cout << "Adicionando Presidente...\n";
            cout << "Digite o codigo do presidente: ";
            cin >> codigo;
            cout << "Digite o nome do presidente: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Digite o endereco do presidente: \n";
            getline(cin, endereco);
            cout << "Digite o telefone do presidente: \n";
            getline(cin, telefone);
            cout << "Digite a data de ingresso do presidente: \n";
            getline(cin, dataIngresso);
            cout << "Digite a área de formação do presidente: \n";
            cin >> areaFormacao;
            cout << "Digite a formação acadêmica máxima do presidente: \n";
            cin >> formMax;
            cout << "Digite o salario do presidente: \n";
            cin >> salario;
            // Para o arquivo:
            funcionario = to_string(tipo)+","+codigo+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+","+areaFormacao+","+formMax+"\n";            
            arq << funcionario;
            arq.close();
            break;
    }
    

    };
void GerenciaBD::removerFuncionario(int codigo){
    arq.open("funcionarios.txt", ios::in);
    string codigo1;
    codigo1 = to_string(codigo);

    string linha;
    ifstream arq("funcionarios.txt");
    if(arq.is_open()){
        while(getline(arq, linha)){
            if(linha.find(codigo1) != string::npos){
                cout << "Removendo funcionario...\n";
                cout << "Você tem certeza?";
                char opcao;
                cin >> opcao;
                if(opcao == 's'){
                    linha = "REMOVIDO";
                }
                cout << "Funcionario removido com sucesso!\n";
            }
            else{
                cout << "Funcionario nao encontrado!\n";
            }
            
        }
    }
    else{
        cout << "Erro ao abrir arquivo" << endl;
    }
    arq.close();
};







/// Implementação:


// Para incluir todas as classes bases, irei incluir apenas o filho geral de menor nível.
// Cada classe contém o include do seu pai, bastanto assim incluir apenas a última.

// Aqui serão incluídos todos os features.
//#include "features\adcFuncionario\adcFuncionario.h" 
//#include "features\aumentoSalario\aumentoSalario.h"

// Inicio da main:

/*

Tipos para trabalhar com arquivos:
– ofstream – para escrever em um arquivo
– ifstream – para ler dados de um arquivo
– fstream – pode ser utilizada tanto para leitura quanto para
escrita em arquivos

*/


/*
OPERADOR: Func, ID, nome, end, tel,dIngresso, salario
(O,20000,Cleitim da Silva,sargentoAdait,83988-88,DD-MM-AAAA,1231241)
*/

int main (){
    // Criação de um objeto do tipo funcionario e cout de todos os seus atributos:
    /*c3Presidente presidente = c3Presidente();
    cout << "Nome: " << presidente.getNome() << endl;
    cout << "Salario: " << presidente.getSalario() << endl;
    cout << "Area Supervisao: " << presidente.getAreaSupervisao() << endl;
    cout << "TESTE DE ALTERAÇAO 2.2.55";
    */

    cout << "O que você deseja fazer?\n";
    cout << "1 - Adicionar funcionario\n";
    cout << "2 - Remover funcionario\n";
    cout << "3 - Aumentar salario\n";
    cout << "4 - Listar funcionarios\n";
    cout << "5 - Sair\n";
    int opcao, desig;

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
        cin >> desig;
        gerencia.removerFuncionario(desig);
    }else if(opcao == 3){
        GerenciaBD gerencia;
        gerencia.listarFuncionarios();
    }

    cout << "Ok!";





}
 














