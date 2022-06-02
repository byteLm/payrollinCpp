#include "classesBase\c1Gerente\gerente.h"

class c2Diretor : public c1Gerente{

    public:
        c2Diretor();
        c2Diretor(int codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig, string AreaSupervisao, string areaFormacao);
        virtual ~c2Diretor();
        void setAreaFormacao(string areaFormacao);
        string getAreaFormacao();

    protected:
        string areaFormacao;
    
    


};






