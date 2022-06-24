#include "motherFuncionario.h"
//Classe gerente herda de mFuncionario
/*

Todos os atributos, base-gerais, de funcionário, estão sendo utilizados.
Essa classes é somente mFuncionário com novo atributo (Área de Supervisão).
*Também foi re-implementado nesta classe a função 'imprime'.

*/
class c1Gerente : public mFuncionario{

    public:
        c1Gerente();
        c1Gerente(int codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig, string AreaSupervisao);
        void setAreaSupervisao(string areaSupervisao);
        string getAreaSupervisao();
        virtual void imprime();
    protected:
        string areaSupervisao;

};