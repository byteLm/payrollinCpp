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
        mFuncionario(int codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig);

        
        //Getters
        int getCodigo();
        int getDesig();
        string getNome();
        string getEndereco();
        string getTelefone();
        string getDataIngresso();
        float getSalario();

        //Setters
        void setCodigo(int codigo);
        void setDesig(int desig);
        void setNome(string nome);
        void setEndereco(string endereco);
        void setTelefone(string telefone);
        void setDataIngresso(string dataIngresso);
        void setSalario(float salario);

    protected:
        int codigo;
        int desig;

        string nome;
        string endereco;
        string telefone;
        string dataIngresso;
        float salario;

};
mFuncionario::mFuncionario(){
    codigo = 0;
    desig = 0;
    nome = "";
    endereco = "";
    telefone = "";
    dataIngresso = "";
    salario = 0;
}
mFuncionario::mFuncionario(int codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig){
    this->codigo = codigo;
    this->desig = desig;
    this->nome = nome;
    this->endereco = endereco;
    this->telefone = telefone;
    this->dataIngresso = dataIngresso;
    this->salario = salario;
};
int mFuncionario::getCodigo(){
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
void mFuncionario::setCodigo(int codigo){
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
/// Implementação:


// Para incluir todas as classes bases, irei incluir apenas o filho geral de menor nível.
// Cada classe contém o include do seu pai, bastanto assim incluir apenas a última.

// Aqui serão incluídos todos os features.
//#include "features\adcFuncionario\adcFuncionario.h" 
//#include "features\aumentoSalario\aumentoSalario.h"

// Inicio da main:


int main (){
    // Criação de um objeto do tipo funcionario e cout de todos os seus atributos:
    c3Presidente presidente = c3Presidente();
    cout << "Nome: " << presidente.getNome() << endl;
    cout << "Salario: " << presidente.getSalario() << endl;
    cout << "Area Supervisao: " << presidente.getAreaSupervisao() << endl;
    cout << "TESTE DE ALTERAÇAO";

}
 














