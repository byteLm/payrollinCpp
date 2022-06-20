/*
Essa classe herdará todos os atributos e funções de mFuncionario, c1Gerente e c2Diretor.
Nessa classe é somente acrescentado o atributo Formação Máxima e é re-implementado
a função 'imprime'.
*/

#include "diretor.h"

class c3Presidente : public c2Diretor{
    
    public:
        c3Presidente();
        c3Presidente(int codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig, string AreaSupervisao, string areaFormacao, string formMax);
        void setFormacaoMax(string FormacaoMax);
        string getFormacaoMax();
        virtual void imprime();
    protected:
        string FormacaoMax;
    
    
    
};

