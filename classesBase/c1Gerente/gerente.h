#include "Classes/motherFuncionario/motherFuncionario.h"

//Classe gerente herda de mFuncionario
class c1Gerente : public mFuncionario{

    public:
        c1Gerente();
        c1Gerente(int codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig, string AreaSupervisao);
        virtual ~c1Gerente();
        void setAreaSupervisao(string areaSuperfisao);
        string getAreaSupervisao();
    protected:
        string areaSupervisao;



};
