#include "presidente.h"
#include <fstream>
class GerenciaBD : public c3Presidente, ofstream{

    public:
        GerenciaBD();
        virtual ~GerenciaBD();
        
        void listarFuncionarios();
        void listarFuncionarios(int desig);

        void cadastrarFuncionario(int tipo);
        void cadastrarGerente(c1Gerente novo);
        void cadastrarDiretor(c2Diretor novo);
        void cadastrarPresidente(c3Presidente novo);
        void removerFuncionario(string codigo1);
        
        void consulta(string codigo1); 
    protected:
        ofstream arq;
        mFuncionario tempOperario;
        c1Gerente tempGerente;
        c2Diretor tempDiretor;
        c3Presidente tempPresidente;
        

};