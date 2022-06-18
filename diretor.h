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




