//Classe gerente herda de mFuncionario
#include "gerente.h"

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