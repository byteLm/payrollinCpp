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
        void cadastrarOperador(mFuncionario novo);
        void cadastrarGerente(c1Gerente novo);
        void cadastrarDiretor(c2Diretor novo);
        void cadastrarPresidente(c3Presidente novo);
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
    arq.open("funcionarios.txt", ios::app);
    string operador = "O,"+novo.getCodigo()+","+novo.getNome()+","+novo.getEndereco()+","+novo.getTelefone()+","+novo.getDataIngresso()+","+to_string(novo.getSalario())+","+to_string(novo.getDesig())+"\n";
    // abrindo o arquivo:
    // escrevendo a frase no arquivo:
    arq << operador;
    // fechando o arquivo:
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
    cout << "2 - Aumentar salario\n";
    cout << "3 - Listar funcionarios\n";
    cout << "4 - Sair\n";
    int opcao;
    cin >> opcao;
    string codigo;
    string nome;
    string endereco;
    string telefone;
    string dataIngresso;
    float salario;
    int desig;
    
    if(opcao==1){
    
        cout << "Adicionar funcionario\n";
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
        cout << "Digite o codigo do desig do funcionario: \n";
        
        cin >> desig;
        GerenciaBD gerencia;
        mFuncionario temp;
        temp.setCodigo(codigo);
        temp.setNome(nome);
        temp.setEndereco(endereco);
        temp.setTelefone(telefone);
        temp.setDataIngresso(dataIngresso);
        temp.setSalario(salario);
        temp.setDesig(desig);
        gerencia.cadastrarOperador(temp);
    }

    cout << "Ok!";





}
 














