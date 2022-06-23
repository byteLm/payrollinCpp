/**/
#include "motherFuncionario.h"
mFuncionario::mFuncionario(){
    codigo = "0";
    desig = 0;
    nome = "";
    endereco = "";
    telefone = "";
    dataIngresso = "";
    salario = 0;
    totalHorasExtras = 0;
    diasTrabalhados = 0;

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

void mFuncionario::imprime(){
    cout << "----------------------------------------------------" << endl;
    cout << "Operario ("+this->getCodigo()+")" << endl;
    cout << "Nome: " << this->getNome() << endl;
    cout << "Salario: " << this->getSalario() << endl;
    cout << "Telefone: " << this->getTelefone() << endl;
    cout << "Endereco: " << this->getEndereco() << endl;
    cout << "Data de ingresso: " << this->getDataIngresso() << endl;
    cout << "Dias Trabalhados: " << this->getDiasTrabalhados() << endl;
    cout << "Horas extras: " << this->getTotalHorasExtras() << endl;
    cout << "----------------------------------------------------" << endl;
}
void mFuncionario::setTotalHorasExtras(float totalHorasExtras){
    this->totalHorasExtras = totalHorasExtras;
}
int mFuncionario::getTotalHorasExtras(){
    return this->totalHorasExtras;
}
int mFuncionario::getDiasTrabalhados(){
    return this->diasTrabalhados;
}
/*
Essa função atribui dias trabalhados aleatorios ao funcionário, bem como
atribui o valor de horas extras ao funcionário.
*/
void mFuncionario::aleatorio(){
    int diasTrabalhados = rand() % 30;
    this->setDiasTrabalhados(diasTrabalhados);
    float horasExtras = rand() % 10;
    this->setTotalHorasExtras(horasExtras);
    
};
void mFuncionario::setDiasTrabalhados(int diasTrabalhados){
    this->diasTrabalhados = diasTrabalhados;
}
