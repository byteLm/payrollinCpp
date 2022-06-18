#include "presidente.h"

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
void c3Presidente::imprime(){
    cout << "----------------------------------------------------" << endl;
    cout << "Presidente ("+this->getCodigo()+")" << endl;
    cout << "Nome: " << this->getNome() << endl;
    cout << "Salario: " << this->getSalario() << endl;
    cout << "Telefone: " << this->getTelefone() << endl;
    cout << "Endereco: " << this->getEndereco() << endl;
    cout << "Data de ingresso: " << this->getDataIngresso() << endl;
    cout << "Area de supervisao: " << this->getAreaSupervisao() << endl;
    cout << "Area de formacao: " << this->getAreaFormacao() << endl;
    cout << "Formacao maxima: " << this->getFormacaoMax() << endl;
    cout << "----------------------------------------------------" << endl;
};
