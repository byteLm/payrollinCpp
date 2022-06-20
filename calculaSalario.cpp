#include "calculaSalario.h"

CalculaSalarioFuncC::CalculaSalarioFuncCC(){
    this->salario = 0;
    this->horasExtras = 0;
};
CalculaSalarioFuncC::~CalculaSalarioFuncCC(){
};
float CalculaSalarioFuncC::calculaSalario(float salario, float horasExtras){
    float valorHora = salario/23/8;
    float valorHoraExtra = valorHora*2;
    float totalHorasExtras = 0;
    if(horasExtras!=0){
        float totalHorasExtras = valorHoraExtra*horasExtras;
    }

    float totalSalarioSemDescontos = salario + totalHorasExtras;
    float i = totalSalarioSemDescontos;
    float totalSalarioComDescontos = totalSalarioSemDescontos - (i*(35.15));
    return totalSalarioComDescontos;
};

void CalculaSalarioFuncC::folhaDescritaFunc(float salario, float horasExtras){
    float valorHora = salario/23/8;
    float valorHoraExtra = valorHora*2;
    float totalHorasExtras = 0;
    if(horasExtras!=0){
        float totalHorasExtras = valorHoraExtra*horasExtras;
    }
    float totalSalarioSemDescontos = salario + totalHorasExtras;
    float i = totalSalarioSemDescontos;
    float totalSalarioComDescontos = totalSalarioSemDescontos - (i*(35.15));
    
    cout << "Salario sem descontos: " << totalSalarioSemDescontos << endl;
    cout << "INSS:" << salario * 0.0765 << endl;
    cout << "IR:" << salario * 0.115 << endl;
    cout << "Vale Transporte:" << salario * 0.06 << endl;
    cout << "Vale Refeicao:" << salario * 0.1 << endl;
    cout << "Salario com descontos: " << totalSalarioComDescontos << endl;
};

void CalculaSalarioFuncC::calculaFolhaEmpresa(){
    
    int mesRef;
    cout << "Por favor, digite o mes de referencia: " << endl;
    cout << "Considere que a folha de pagamento só poderá ser gerada uma vez." << endl;
    cout << "1 - Janeiro" << endl;
    cout << "2 - Fevereiro" << endl;
    cout << "3 - Março" << endl;
    cout << "4 - Abril" << endl;
    cout << "5 - Maio" << endl;
    cout << "6 - Junho" << endl;
    cout << "7 - Julho" << endl;
    cout << "8 - Agosto" << endl;
    cout << "9 - Setembro" << endl;
    cout << "10 - Outubro" << endl;
    cout << "11 - Novembro" << endl;
    cout << "12 - Dezembro" << endl;
    cin >> mesRef;
    if(mesRef!=1 && mesRef!=2 && mesRef!=3 && mesRef!=4 && mesRef!=5 && mesRef!=6 && mesRef!=7 && mesRef!=8 && mesRef!=9 && mesRef!=10 && mesRef!=11 && mesRef!=12){
        cout << "Mes de referencia inválido." << endl;
    }else{
            
        fstream arq;
        string temp;
        int tipo;
        int qt;
        string cod[100];

        while(getline(arq, temp)){
            if(temp.find("&&&ULTIMACONSULTAANOEMPRESA&&&") != string::npos){
                cout << "Não foi possível emetir para esse mes. Ja emetido anteriormente." << endl;
                int posInicial = temp.find("&&&ULTIMACONSULTAANOEMPRESA&&&");
                for(int i = 0; i<posInicial; i++){
                    cout << temp[i];
                    if(i == 1||i==3){
                        cout << "/";
                    }

                }
            }
        }

        qt = 0;
        arq.open("funcionarios.txt", ios::in);
        if(arq.is_open()){
            while(getline(arq, temp)){
                qt++;
                for(int i=2; temp[i]!=','; i++){
                    cod[qt] += temp[i];
                }
        }
        arq.close();
    }


/*f) Imprimir uma Folha de Salário do Funcionário: Esse recurso também solicita o código do
funcionário ou nome completo. Deve constar o salário base, descontos e salário líquido do
empregado.
g) Imprimir a folha salarial empresa: Esse recurso dá opção de o usuário escolher ou a folha
anual calculando o somatório de salário de cada empregado ou uma folha mensal, sendo que
para esta última será solicitado qual mês do ano.*/



        float totalBruto = 0;
        float totalLiquido = 0;


        GerenciaBD gerencia;
        for(int i = 0; i <qt; i++){
            
            int tipo = gerencia.retornaTipo(cod[i]);
            if(tipo == 1){
                mFuncionario tempOperario = gerencia.consultaOperario(cod[i]);
                float salario = tempOperario.getSalario();
                float horasExtras = tempOperario.getTotalHorasExtras();
                float salarioLiquido = calculaSalario(salario, horasExtras);
                totalBruto += salario;
                totalLiquido += salarioLiquido;
            }else if(tipo == 2){
                c1Gerente tempGerente = gerencia.consultaGerente(cod[i]);
                float salario = tempGerente.getSalario();
                float horasExtras = tempGerente.getTotalHorasExtras();
                float salarioLiquido = calculaSalario(salario, horasExtras);
                totalBruto += salario;
                totalLiquido += salarioLiquido;
            }else if(tipo == 3){
                c2Diretor tempDiretor = gerencia.consultaDiretor(cod[i]);
                float salario = tempDiretor.getSalario();
                float horasExtras = tempDiretor.getTotalHorasExtras();
                float salarioLiquido = calculaSalario(salario, horasExtras);
                totalBruto += salario;
                totalLiquido += salarioLiquido;

            }else if(tipo == 4){
                c3Presidente tempPresidente = gerencia.consultaPresidente(cod[i]);
                float salario = tempPresidente.getSalario();
                float horasExtras = tempPresidente.getTotalHorasExtras();
                float salarioLiquido = calculaSalario(salario, horasExtras);
                totalBruto += salario;
                totalLiquido += salarioLiquido;
            }

        }
        //Esse é o mes atual utilizando o time:
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        int mesAtual = tm.tm_mon + 1;
        /////////////////////////////

        arq.open("funcionarios.txt", ios::app);
        if(arq.is_open()){
            arq << "&&&ULTIMACONSULTAANOEMPRESA&&&:" << (mesAtual) << "&&&TOTALBRUTO&&&:" << totalBruto << "&&&TOTALLIQUIDO&&&:" << totalLiquido << endl;
            arq.close();
        }

    }

};

/*
float salarioMinimo = 1212.00;
float percentualINSS = 0.0765;
float percentualIR = 0.115;
float percentualValeTransporte = 0.06;
float percentualValeRefeicao = 0.1;
float valorHora = 6.58;
float valorHoraExtra = 12.58;
*/