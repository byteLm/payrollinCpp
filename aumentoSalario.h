/*
Essa classe representa aumento de salario de um ou mais funcionarios.
g) Conceder aumento para os funcionários: este recurso ao ser solicitado deverá rodar uma
rotina de aumento de salário para todos os funcionários. Sendo os percentuais de aumento:
● Operador: 5%
● Gerente: 10%
● Diretor: 20%
● Presidente 30%
*/


#include "presidente.h"
class aumentoSalario : public c1Gerente
{
    public:
        aumentoSalario();
        virtual ~aumentoSalario();
        float aumentaSalario(int tipo, float salario);
        
    private:    
        float percentuaLOperador = 0.05;
        float percentualGerente = 0.10;
        float percentualDiretor = 0.20;
        float percentualPresidente = 0.30;

};