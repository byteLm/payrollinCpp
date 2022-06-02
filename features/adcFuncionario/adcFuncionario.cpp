#include "features\adcFuncionario\adcFuncionario.h"

adcFuncionario::adcFuncionario(int tipo){

    if(tipo == 1){
        mFuncionario novoOperador = mFuncionario();
    }else if(tipo == 2){
        c1Gerente novoGerente = c1Gerente();
    }else if(tipo == 3){
        c2Diretor novoDiretor = c2Diretor();
    }else if(tipo == 4){
        c3Presidente novoPresidente = c3Presidente();
    } 
}
