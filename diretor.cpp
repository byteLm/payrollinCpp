


#include "diretor.h"


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
void c2Diretor::imprime(){
    cout << "----------------------------------------------------" << endl;
    cout << "Diretor ("+this->getCodigo()+")" << endl;
    cout << "Nome: " << this->getNome() << endl;
    cout << "Salario: " << this->getSalario() << endl;
    cout << "Telefone: " << this->getTelefone() << endl;
    cout << "Endereco: " << this->getEndereco() << endl;
    cout << "Data de ingresso: " << this->getDataIngresso() << endl;
    cout << "Area de supervisao: " << this->getAreaSupervisao() << endl;
    cout << "Area de formacao: " << this->getAreaFormacao() << endl;
    cout << "----------------------------------------------------" << endl;
};

