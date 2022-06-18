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

