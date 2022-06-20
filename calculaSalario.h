#include "time.h"
#include "gerenciamento.h"

/**

Essa classe irá calcular o salário de um funcionário.
Será considerado possíveis descontos de contribuição/imposto de renda, aplicado as seguintes regras:

- Salário mínimo: 1212.00
- INSS (7.65%) desconto;
- IR (11.5%) desconto;
- VALE TRANSPORTE (6% do SALARIO) desconto;
- VALE REFEICAO (10% do SALARIO) desconto;
-> Hora extra trabalhada: vale o dobro do salário.

Valor da hora para os funcionários, considerado:
- 23 dias úteis (media: 31-fins de semana)
- 8hrs/dia
-> Resulta, considerado o salário mínimo de R$1212.00: R$6.58/hr


--------------------------------------------------------------------------------------------
Em caso de assalariado, o salário será calculado de acordo com o seguinte modelo:
R$1212.00 - (7.65% do salário) - (11.5% do salário) - (6% do salário) - (10% do salário)
um total de 35.15 porcento
Resultando em R$1089.00
--------------------------------------------------------------------------------------------
*/


class CalculaSalarioFuncC:public GerenciaBD {

    CalculaSalarioFuncC();
    ~CalculaSalarioFuncC();
    float calculaSalario(float salario, float horas);
    void folhaDescritaFunc(float salario, float horas);
    void calculaFolhaEmpresa();

    private:
        float salarioMinimo = 1212.00;
        float percentualINSS = 0.0765;
        float percentualIR = 0.115;
        float percentualValeTransporte = 0.06;
        float percentualValeRefeicao = 0.1;
        float valorHora = 6.58;
        float valorHoraExtra = 12.58;
        float totalSalarioBrutoTemp;
        float totalSalarioLiquidoTemp;


};