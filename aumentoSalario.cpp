#include "aumentoSalario.h"


aumentoSalario::aumentoSalario(){
};


aumentoSalario::~aumentoSalario(){
};

float aumentoSalario::aumentaSalario(int tipo, float salario){
    switch(tipo){
        case 1:
            return salario * (1+this->percentuaLOperador);
            break;
        case 2:
            return salario * (1+this->percentualGerente);
            break;
        case 3:
            return salario * (1+this->percentualDiretor);
            break;
        case 4:
            return salario * (1+this->percentualPresidente);
            break;
        default:
            return salario;
            break;
    }
}
