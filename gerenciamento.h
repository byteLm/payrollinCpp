
#include "aumentoSalario.h"

#include <fstream>
class GerenciaBD : public c3Presidente, ofstream{

    public:
        GerenciaBD();
        virtual ~GerenciaBD();
        
        void listarFuncionarios();
        void listarFuncionarios(int desig);

        void cadastrarFuncionario(int tipo);
        void cadastrarOperario(mFuncionario novo);
        void cadastrarGerente(c1Gerente novo);
        void cadastrarDiretor(c2Diretor novo);
        void cadastrarPresidente(c3Presidente novo);
        void removerFuncionario(string codigo1);
        void editaFuncionario(string codigo1, int tipo);

        mFuncionario consultaOperario(string codigo);
        c1Gerente consultaGerente(string codigo);
        c2Diretor consultaDiretor(string codigo);
        c3Presidente consultaPresidente(string codigo);
        int retornaTipo(string codigo);


        
    protected:
        ofstream arq;
        mFuncionario tempOperario;
        c1Gerente tempGerente;
        c2Diretor tempDiretor;
        c3Presidente tempPresidente;
        

};