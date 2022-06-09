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

