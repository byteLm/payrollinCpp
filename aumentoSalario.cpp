#include "aumentoSalario.h"


aumentoSalario::aumentoSalario(mFuncionario operador){
    float salario = operador.getSalario();
    operador.setSalario(salario*(1+percentuaLOperador));

};
aumentoSalario::aumentoSalario(c1Gerente gerente){
    float salario = gerente.getSalario();
    gerente.setSalario(salario*(1+percentualGerente));
};
aumentoSalario::aumentoSalario(c2Diretor diretor){
    float salario = diretor.getSalario();
    diretor.setSalario(salario*(1+percentualDiretor));
};
aumentoSalario::aumentoSalario(c3Presidente presidente){
    float salario = presidente.getSalario();
    presidente.setSalario(salario*(1+percentualPresidente));
};