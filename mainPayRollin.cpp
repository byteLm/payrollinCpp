/// Implementação:


// Para incluir todas as classes bases, irei incluir apenas o filho geral de menor nível.
// Cada classe contém o include do seu pai, bastanto assim incluir apenas a última.
#include "C:\Users\lucca\Documents\GitHub\payrollinCpp\classesBase\mFuncionario\motherFuncionario.h"

// Aqui serão incluídos todos os features.
//#include "features\adcFuncionario\adcFuncionario.h" 
//#include "features\aumentoSalario\aumentoSalario.h"

// Inicio da main:


int main (){

    // Criação de um objeto do tipo funcionario e cout de todos os seus atributos:
    mFuncionario funcionario = mFuncionario();
    cout << "Nome: " << funcionario.getNome() << endl;
    cout << "Salario: " << funcionario.getSalario() << endl;

}