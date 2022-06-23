#include "gerenciamento.h"
#include <windows.h>
#include "time.h"

class FolhaDePagamento{

    public:
        FolhaDePagamento();
        ~FolhaDePagamento();
        float calculaPagamentoFunc(float salario, float horasExtras, int diasTrabalhados);
        void folhaDescritaFunc(float salario, float horasExtras, int diasTrabalhados, string nome, string codigo);
        float calculaFolhaEmpresa(int mesRef, int ver);
        float simulacaoAnual();
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