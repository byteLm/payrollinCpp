#include "folhaDePagamento.h"

FolhaDePagamento::FolhaDePagamento(){
};
FolhaDePagamento::~FolhaDePagamento(){
};
float FolhaDePagamento::calculaPagamentoFunc(float salario, float horasExtras){
    float valorHora = salario/23/8;
    float valorHoraExtra = valorHora*2;
    float totalHorasExtras = 0;
    if(horasExtras!=0){
        float totalHorasExtras = valorHoraExtra*horasExtras;
    }

    float totalSalarioSemDescontos = salario + totalHorasExtras;
    float i = totalSalarioSemDescontos;
    float totalSalarioComDescontos = totalSalarioSemDescontos - (i*(0.3515));
    return totalSalarioComDescontos;
};
void FolhaDePagamento::folhaDescritaFunc(float salario, float horasExtras){
    float valorHora = salario/23/8;
    float valorHoraExtra = valorHora*2;
    float totalHorasExtras = 0;
    if(horasExtras!=0){
        float totalHorasExtras = valorHoraExtra*horasExtras;
    }
    float totalSalarioSemDescontos = salario + totalHorasExtras;
    float i = totalSalarioSemDescontos;
    float totalSalarioComDescontos = totalSalarioSemDescontos - (i*(0.3515));
    
    cout << "Salario sem descontos: " << totalSalarioSemDescontos << endl;
    cout << "INSS:" << salario * 0.0765 << endl;
    cout << "IR:" << salario * 0.115 << endl;
    cout << "Vale Transporte:" << salario * 0.06 << endl;
    cout << "Vale Refeicao:" << salario * 0.1 << endl;
    cout << "Salario com descontos: " << totalSalarioComDescontos << endl;
};
int FolhaDePagamento::calculaFolhaEmpresa(int mesRef){
      
    fstream arq;
    string temp;
    int tipo;
    int qt;
    int jaEmitido = 0;
    string cod[100];
    string mesRefS = "";
    arq.open("funcionarios.txt", ios::in);
    
    if(mesRef == 1 || mesRef == 2){
        mesRefS = "0" + to_string(mesRef);
    }else{
        mesRefS = to_string(mesRef);
    }

    string veri = "&&&ULTIMACONSULTAANOEMPRESA&&&:"+mesRefS;

    while(getline(arq, temp)){
        if(jaEmitido){
            cout<< "Não foi possível emitir. Já emitido em: " << endl;
            cout << temp << endl;
            return 1;
        }
        if(temp.find(veri) != string::npos){
            jaEmitido = 1;
        }
    }
    
    //cout << "Ate aqui ok" << endl;
    arq.close();

    qt = -1;
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
    //cout << "Ate aqui ok" << endl;
    
    float totalBruto = 0.0;
    float totalLiquido = 0.0;

    float salario = 0.0;
    float salarioBruto = 0.0;
    int horasExtras = 0;
    float salarioLiquido = 0.0;

    GerenciaBD gerencia;
    for(int i = 0; i <= qt; i++){
        int tipo = gerencia.retornaTipo(cod[i]);
        if(tipo == 1){
            
            mFuncionario tempOperario = gerencia.consultaOperario(cod[i]);
            salario = tempOperario.getSalario();
            horasExtras = 0;
            salarioLiquido = calculaPagamentoFunc(salario, horasExtras);
            totalBruto += salario;
            totalLiquido += salarioLiquido;
            tempOperario.~mFuncionario();
        }else if(tipo == 2){
            c1Gerente tempGerente = gerencia.consultaGerente(cod[i]);
            salario = tempGerente.getSalario();
            horasExtras = 0;
            salarioLiquido = calculaPagamentoFunc(salario, horasExtras);
            totalBruto += salario;
            totalLiquido += salarioLiquido;
            tempGerente.~c1Gerente();

        }else if(tipo == 3){
            c2Diretor tempDiretor = gerencia.consultaDiretor(cod[i]);
            salario = tempDiretor.getSalario();
            horasExtras = 0;
            salarioLiquido = calculaPagamentoFunc(salario, horasExtras);
            totalBruto += salario;
            totalLiquido += salarioLiquido;
            tempDiretor.~c2Diretor();
        }else if(tipo == 4){
            c3Presidente tempPresidente = gerencia.consultaPresidente(cod[i]);
            salario = tempPresidente.getSalario();
            horasExtras = 0;
            salarioLiquido = calculaPagamentoFunc(salario, horasExtras);
            totalBruto += salario;
            totalLiquido += salarioLiquido;
            tempPresidente.~c3Presidente();
        }

    }
    //Essa é a data atual utilizando o time:
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int mesAtual = tm.tm_mon + 1;
    int anoAtual = tm.tm_year + 1900;
    int diaAtual = tm.tm_mday;
    string dataAtual = to_string(diaAtual) + "/" + to_string(mesAtual) + "/" + to_string(anoAtual);
    /////////////////////////////
    
    arq.open("funcionarios.txt", ios::app);
    if(arq.is_open()){
        arq << "&&&ULTIMACONSULTAANOEMPRESA&&&:" << (mesRefS) << "&&&TOTALBRUTO&&&:" << totalBruto << "&&&TOTALLIQUIDO&&&:" << totalLiquido << "$ULTIMACONSULTA::"<< endl;
        arq << dataAtual << endl; 
    }
    arq.close();

    cout << "Folha de pagamento emitida com sucesso." << endl;
    cout << "Total bruto: " << totalBruto << endl;
    cout << "Total liquido: " << totalLiquido << endl;
    cout << "Mes de referencia: " << mesRefS << endl;
    cout << "Ano de referencia: " << tm.tm_year + 1900 << endl;
    cout << "Data de emissão: " << tm.tm_mday << "/" << tm.tm_mon + 1 << "/" << tm.tm_year + 1900 << endl;
    cout << "Hora de emissão: " << tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec << endl;
    cout << "----------------------------------------------------" << endl;


    arq.open("logEmissao"+mesRefS+".txt", ios::in);
    arq << "Folha de pagamento emitida com sucesso." << endl;
    arq << "Total bruto: " << totalBruto << endl;
    arq << "Total liquido: " << totalLiquido << endl;
    arq << "Mes de referencia: " << mesRefS << endl;
    arq << "Ano de referencia: " << tm.tm_year + 1900 << endl;
    arq << "Data de emissão: " << tm.tm_mday << "/" << tm.tm_mon + 1 << "/" << tm.tm_year + 1900 << endl;
    arq << "Hora de emissão: " << tm.tm_hour << ":" << tm.tm_min << ":" << tm.tm_sec << endl;
    arq << "----------------------------------------------------" << endl;
    arq << "Funcionarios Considerados:" << endl;
    for(int i = 0; i < qt; i++){
        arq << cod[i] << endl;
    }
    arq.close();


    return 0;
};