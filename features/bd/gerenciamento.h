#include "classesBase/c3Presidente/presidente.h"
#include <fstream>
class GerenciaBD : public c3Presidente, ofstream{

    public:
        GerenciaBD();
        virtual ~GerenciaBD();
        void listarFuncionarios();
        void listarFuncionarios(int desig);
        void listarFuncionarios(string nome);
        void cadastrarOperador(mFuncionario novo);
        void cadastrarGerente(c1Gerente novo);
        void cadastrarDiretor(c2Diretor novo);
        void cadastrarPresidente(c3Presidente novo);
        void consulta(int tipo); // 1 - codigo, 2 - nome, 3 - desig, 4 - salario, 5 - data de ingresso, 6 - area de supervisao, 7 - area de formacao, 8 - formMax
    protected:
        ofstream arq;
};