#include "motherFuncionario.h"
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
