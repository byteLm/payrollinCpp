/*
Classe herda todos os atributos e funções de mFuncionario e de c1Gerente.
Nessa classe é somente acrescentado o atributo Área de Formação e é re-implemetando
a função 'imprime'.
*/

#include "gerente.h"
class c2Diretor : public c1Gerente{

    public:
        c2Diretor();
        c2Diretor(int codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig, string AreaSupervisao, string areaFormacao);
        void setAreaFormacao(string areaFormacao);
        string getAreaFormacao();
        virtual void imprime();
        

    protected:
        string areaFormacao;
};




