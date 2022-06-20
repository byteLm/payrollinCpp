#include "gerenciamento.h"

#include <vector>

GerenciaBD::GerenciaBD(){
};
GerenciaBD::~GerenciaBD(){
};

/*Essa classe irá imprimir todos os dados disponíveis no banco de dados sobre determinados funcionários
Será possível com ela imprimir:
-> Todos os funcionários;
-> Todos os funcionários com determinado cargo;
-> Todos os funcionários com determinado nome/endereço;
-> Todos os funcionários com mesma data de ingresso

Ap.1.
Caso o filtro cargo '1' seja passado será imprimido todos os funcionários de OPERADORES, e assim por diante.
Caso o filtro cargo seja '-1' será imprimido todos os funcionários.

Ap.2.
Para utilizar qualquer outro filtro basta passar o desejado em formato de string, será visto em todos os funcionários
aqueles que possuírem o designado.

Ap.3.
DEVE ser utilizado, ao puxar a função, todos os parâmetros. Para o filtro cargo, caso não for utilizado,
qualquer valor != à -1, 1, 2, 3 ou 4 será desconsiderado - já para o parametro "qualquerAtributo", 
caso não seja utilizado, deve-se passar uma string vazia "".
*/
void GerenciaBD::listarFuncionarios(int filtroCargo, string qualquerAtributo){

    fstream arqParaQT;
    int qt = 0;
    string temp;
    string cod[100];
    int tipo;
    if(filtroCargo == -1 || filtroCargo == 1 || filtroCargo == 2 || filtroCargo == 3 || filtroCargo == 4){
        arqParaQT.open("funcionarios.txt", ios::in);
        if(arqParaQT.is_open()){
            while(getline(arqParaQT, temp)){
                qt++;
                for(int i=2; temp[i]!=','; i++){
                    cod[qt] += temp[i];
                }
        }
        arqParaQT.close();
        }

        if(filtroCargo == -1){          
            for(int i=0; i<qt; i++){
                tipo = retornaTipo(cod[i]);
                if(tipo == 1){
                    this->tempOperario = this->consultaOperario(cod[i]);
                    tempOperario.imprime();
                }else if(tipo == 2){
                    this->tempGerente = this->consultaGerente(cod[i]);
                    tempGerente.imprime();  
                }else if(tipo == 3){
                    this->tempDiretor = this->consultaDiretor(cod[i]);
                    tempGerente.imprime();      
                }else if(tipo == 4){
                    this->tempPresidente = this->consultaPresidente(cod[i]);
                    tempPresidente.imprime();    
                }else{
                    break;
                }
            }
        }else if(filtroCargo == 1){
            for(int i=0; i<qt; i++){
                tipo = retornaTipo(cod[i]);
                if(tipo == 1){
                    this->tempOperario = this->consultaOperario(cod[i]);
                    tempOperario.imprime();
                }
            }
        }else if(filtroCargo == 2){
            for(int i=0; i<qt; i++){
                tipo = retornaTipo(cod[i]);
                if(tipo == 2){
                    this->tempGerente = this->consultaGerente(cod[i]);
                    tempGerente.imprime();  
                }
            }
        }else if(filtroCargo == 3){
            for(int i=0; i<qt; i++){
                tipo = retornaTipo(cod[i]);
                if(tipo == 3){
                    this->tempDiretor = this->consultaDiretor(cod[i]);
                    tempDiretor.imprime();      
                }
            }
        }else if(filtroCargo == 4){
            for(int i=0; i<qt; i++){
                tipo = retornaTipo(cod[i]);
                if(tipo == 4){
                    this->tempPresidente = this->consultaPresidente(cod[i]);
                    tempPresidente.imprime();    
                }
            }
            
        }
    }
    if(qualquerAtributo != ""){
        int total = 0;    
        string codComString[100];
        for(int i = 0; i<100; i++){
            codComString[i] = "";
        }
        arqParaQT.open("funcionarios.txt", ios::in);
        if(arqParaQT.is_open()){
            qt = 0;
            while(getline(arqParaQT, temp)){
                qt++;
                if(temp.find(qualquerAtributo)!= string::npos){
                    total++;                
                    for(int i=2; temp[i]!=','; i++){
                        codComString[qt] += temp[i];
                    }
                }
            }
        }
        arqParaQT.close();
        
        for(int i=0; i<total; i++){
            tipo = retornaTipo(codComString[i]);
            if(tipo == 1){
                this->tempOperario = this->consultaOperario(codComString[i]);
                tempOperario.imprime();
            }else if(tipo == 2){
                this->tempGerente = this->consultaGerente(codComString[i]);
                tempGerente.imprime();
            }else if(tipo == 3){
                this->tempDiretor = this->consultaDiretor(codComString[i]);
                tempDiretor.imprime();
            }else if(tipo == 4){
                this->tempPresidente = this->consultaPresidente(codComString[i]);
                tempPresidente.imprime();
            }
        }
    }    
}


void GerenciaBD::cadastrarOperario(mFuncionario novo){
    //cadastrando novo operario
    fstream arq;
    int tipo = 1;
    arq.open("funcionarios.txt", ios::app);
    string funcionario;
    funcionario = to_string(tipo)+","+novo.getCodigo()+","+novo.getNome()+","+novo.getEndereco()+","+novo.getTelefone()+","+novo.getDataIngresso()+","+to_string(novo.getSalario())+"!\n";            
    arq << funcionario;
    arq.close();
};
void GerenciaBD::cadastrarGerente(c1Gerente novo){
    //cadastrando novo gerente
    fstream arq;
    int tipo = 2;
    arq.open("funcionarios.txt", ios::app);
    string funcionario;
    funcionario = to_string(tipo)+","+novo.getCodigo()+","+novo.getNome()+","+novo.getEndereco()+","+novo.getTelefone()+","+novo.getDataIngresso()+","+to_string(novo.getSalario())+","+novo.getAreaSupervisao()+"!\n";
    arq << funcionario;
    arq.close();
};
void GerenciaBD::cadastrarDiretor(c2Diretor novo){
    //cadastrando novo diretor
    fstream arq;
    int tipo = 3;
    arq.open("funcionarios.txt", ios::app);
    string funcionario;
    funcionario = to_string(tipo)+","+novo.getCodigo()+","+novo.getNome()+","+novo.getEndereco()+","+novo.getTelefone()+","+novo.getDataIngresso()+","+to_string(novo.getSalario())+","+novo.getAreaSupervisao()+","+novo.getAreaFormacao()+"!\n";
    arq << funcionario;
    arq.close();
};
void GerenciaBD::cadastrarPresidente(c3Presidente novo){
    //cadastrando novo presidente
    fstream arq;
    int tipo = 4;
    arq.open("funcionarios.txt", ios::app);
    string funcionario;
    funcionario = to_string(tipo)+","+novo.getCodigo()+","+novo.getNome()+","+novo.getEndereco()+","+novo.getTelefone()+","+novo.getDataIngresso()+","+to_string(novo.getSalario())+","+novo.getAreaSupervisao()+","+novo.getAreaFormacao()+","+novo.getFormacaoMax()+"!\n";
    arq << funcionario;
    arq.close();
};
void GerenciaBD::cadastrarFuncionario(int tipo){
    fstream arq;
    arq.open("funcionarios.txt", ios::app);
    string funcionario;
    string codigo;
    float salario;
    string nome, endereco, telefone, dataIngresso, areaSupervisao, areaFormacao, formMax;


    cout << "Digite o codigo do funcionario: ";
    cin >> codigo;
    cout << "Digite o nome do funcionario: ";
    cin.ignore();
    getline(cin, nome);
    cout << "Digite o endereco do funcionario: \n";
    getline(cin, endereco);
    if(endereco.find(",")!= string::npos){
        endereco.erase(endereco.find(","), 1);
    }
    cout << "Digite o telefone do funcionario: \n";
    getline(cin, telefone);
    cout << "Digite a data de ingresso do funcionario: \n";
    getline(cin, dataIngresso);
    cout << "Digite o salario do funcionario: \n";
    cin >> salario;
  
    switch(tipo){
        case 1:
            // Para o arquivo:
            funcionario = "\n"+to_string(tipo)+","+codigo+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+"!\n";            
            arq << funcionario;
            arq.close();
            break;
        case 2:
            cin.ignore();
            cout << "Digite a área de supervisão do gerente: \n";
            getline(cin, areaSupervisao);
            funcionario = "\n"+to_string(tipo)+","+codigo+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+","+areaSupervisao+"!\n";            
            arq << funcionario;
            arq.close();
            break;
        case 3:
            cout << "Adicionando Diretor...\n";
            cin.ignore();
            cout << "Digite a área de supervisão do diretor: \n";
            getline(cin, areaSupervisao);
            cout << "Digite a área de formação do diretor: \n";
            getline(cin, areaFormacao);
            
            // Para o arquivo:
            funcionario = "\n"+to_string(tipo)+","+codigo+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+","+areaSupervisao+","+areaFormacao+"!\n";            
            arq << funcionario;
            arq.close();
            break;
        case 4:
            cin.ignore();
            cout << "Digite a área de formação do presidente: \n";
            getline(cin, areaFormacao);
            cout << "Digite a formação acadêmica máxima do presidente: \n";
            getline(cin, formMax);
            
            // Para o arquivo:
            funcionario = "\n"+to_string(tipo)+","+codigo+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+","+areaFormacao+","+formMax+"!\n";           
            arq << funcionario;
            arq.close();
            break;
    }
    

    };
void GerenciaBD::removerFuncionario(string codigo1){ 
    string linha;
    int funcEncontrado = 0;

    fstream arq;
    arq.open("funcionarios.txt", ios::in);
    if(arq.is_open()){
        fstream arq2;
        arq2.open("funcionarios2.txt", ios::out);
        while(getline(arq, linha)){
            if(linha.find(codigo1) != string::npos){
                funcEncontrado = 1;
            }
            else{
                arq2 << linha+"\n";
            } 
        }
        if(funcEncontrado==1){
            arq.close();
            arq2.close();
            remove("funcionarios.txt");
            rename("funcionarios2.txt", "funcionarios.txt");  
        }else{
            cout << "Funcionario nao encontrado!\n";   
        }   
        }

};
void GerenciaBD::editaFuncionario(string codigo1, int tipo){
    
    if(tipo == 1){
        mFuncionario tempFuncionario = mFuncionario();
        tempFuncionario = this->consultaOperario(codigo1);
        while(1){
            cout << "O que voce deseja alterar?\n";
            cout << "1 - Nome\n";
            cout << "2 - Endereco\n";
            cout << "3 - Telefone\n";
            cout << "4 - Data de ingresso\n";
            cout << "5 - Salario\n";
            cout << "6 - Criar novo CF\n";
            cout << "7 - Cancelar operacao\n";
            int opcao;
            cin >> opcao;
            if(opcao == 7){
                break;
            }else if(opcao == 1){
                cout << "Digite o novo nome: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempFuncionario.setNome(tempString);
                cout << "Nome alterado com sucesso!\n";
            }else if(opcao == 2){
                cout << "Digite o novo endereco: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempFuncionario.setEndereco(tempString);
                cout << "Endereco alterado com sucesso!\n";
            }else if(opcao == 3){
                cout << "Digite o novo telefone: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempFuncionario.setTelefone(tempString);
                cout << "Digite a nova data de ingresso: \n";
            }else if(opcao == 4){
                cout << "Digite a nova data de ingresso: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempFuncionario.setDataIngresso(tempString);
                cout << "Data alterada com sucesso!\n";
            }else if(opcao == 5){
                cout << "Digite o novo salario: \n";
                float salarioNovo;
                cin >> salarioNovo;
                tempFuncionario.setSalario(salarioNovo);
                cout << "Salario alterado com sucesso!\n";
            }else if(opcao == 6){
                cout << "Digite o novo codigo do CF: \n";
                string codigoNovo;
                cin >> codigoNovo;
                tempFuncionario.setCodigo(codigoNovo);
                cout << "Codigo atualizado!\n";
            }else{
                cout << "Operação cancelada!\n";
                break;
            }
            cout << "Deseja alterar mais alguma coisa?\n";
            cout << "1 - Sim\n";
            cout << "2 - Não\n";
            int opcao2;
            cin >> opcao2;
            if(opcao2 == 2){
                break;
            }else{
                continue;
            }
        }
        this->removerFuncionario(codigo1);
        this->cadastrarOperario(tempFuncionario);     
    }   
}  
mFuncionario GerenciaBD::consultaOperario(string codigo1){
    string linha;
    string tempString = "";
    int funcEncontrado = 0;
    char ch;
    int atributos = 2;
    
    fstream arq;
    string codigo = "";
    string salario = "";
    string nome = "";
    string endereco = "";
    string telefone = "";
    string dataIngresso = "";
    
        
    arq.open("funcionarios.txt", ios::in);
    
    if(arq.is_open()){
        while(getline(arq, linha)){        
            if(linha.find(codigo1) != string::npos){
                funcEncontrado = 1;
                tempOperario.setDesig(1);
                tempString = linha;
                arq.close();
                for(int i = 2; i;i++){
                    if(tempString[i]==','){
                        atributos++;
                    }else{
                        switch(atributos){
                            case 2:
                                codigo += tempString[i];
                                break;
                            case 3:
                                nome += tempString[i];
                                break;
                            case 4:
                                endereco += tempString[i];
                                break;
                            case 5:
                                telefone += tempString[i];
                                break;
                            case 6:
                                dataIngresso += tempString[i];
                                break;
                            case 7:
                                salario += tempString[i];
                                break;
                            case 8:
                                break;
                        }
                        if(tempString[i]=='!'){
                            tempOperario.setCodigo(codigo);
                            tempOperario.setNome(nome);
                            tempOperario.setEndereco(endereco);
                            tempOperario.setTelefone(telefone);
                            tempOperario.setDataIngresso(dataIngresso);
                            tempOperario.setSalario(stof(salario));
                            return tempOperario;
                            break;
                        }

                    }      
                }
            }
        }
        if(funcEncontrado==0){
            cout << "Operario nao encontrado!\n";
        }
    }
}
c1Gerente GerenciaBD::consultaGerente(string codigo1){
    string linha;
    string tempString = "";
    int funcEncontrado = 0;
    char ch;
    int atributos = 2;
    
    fstream arq;
    string codigo = "";
    string salario = "";
    string nome = "";
    string endereco = "";
    string telefone = "";
    string dataIngresso = "";
    string areaSupervisao = "";
    
        
    arq.open("funcionarios.txt", ios::in);
    
    if(arq.is_open()){
        while(getline(arq, linha)){        
            if(linha.find(codigo1) != string::npos){
                funcEncontrado = 1;
                tempGerente.setDesig(2);
                tempString = linha;
                arq.close();

                for(int i = 2; i;i++){
                    if(tempString[i]==','){
                        atributos++;
                    }else{
                        switch(atributos){
                            case 2:
                                codigo += tempString[i];
                                break;
                            case 3:
                                nome += tempString[i];
                                break;
                            case 4:
                                endereco += tempString[i];
                                break;
                            case 5:
                                telefone += tempString[i];
                                break;
                            case 6:
                                dataIngresso += tempString[i];
                                break;
                            case 7:
                                salario += tempString[i];
                                break;
                            case 8:
                                areaSupervisao += tempString[i];
                                break;
                            case 9:
                                break;    
                        }
                        if(tempString[i]=='!'){
                            tempGerente.setCodigo(codigo);
                            tempGerente.setNome(nome);
                            tempGerente.setEndereco(endereco);
                            tempGerente.setTelefone(telefone);
                            tempGerente.setDataIngresso(dataIngresso);
                            tempGerente.setSalario(stof(salario));
                            tempGerente.setAreaSupervisao(areaSupervisao);
                            
                            break;
                        }

                    }
                    
                }
            }
        }
        if(funcEncontrado==0){
            cout << "Gerente nao encontrado!\n";
        }else{
            return tempGerente;
        }
    }
}
c2Diretor GerenciaBD::consultaDiretor(string codigo1){
    string linha;
    string tempString = "";
    int funcEncontrado = 0;
    char ch;
    int atributos = 2;
    
    fstream arq;
    string codigo = "";
    string salario = "";
    string nome = "";
    string endereco = "";
    string telefone = "";
    string dataIngresso = "";
    string areaSupervisao = "";
    string areaFormacao = "";
    

        
    arq.open("funcionarios.txt", ios::in);
    
    if(arq.is_open()){
        while(getline(arq, linha)){        
            if(linha.find(codigo1) != string::npos){
                funcEncontrado = 1;
                tempGerente.setDesig(3);
                tempString = linha;
                arq.close();

                for(int i = 2; i;i++){
                    if(tempString[i]==','){
                        atributos++;
                    }else{
                        switch(atributos){
                            case 2:
                                codigo += tempString[i];
                                break;
                            case 3:
                                nome += tempString[i];
                                break;
                            case 4:
                                endereco += tempString[i];
                                break;
                            case 5:
                                telefone += tempString[i];
                                break;
                            case 6:
                                dataIngresso += tempString[i];
                                break;
                            case 7:
                                salario += tempString[i];
                                break;
                            case 8:
                                areaSupervisao += tempString[i];
                                break;
                            case 9:
                                break;    
                        }
                        if(tempString[i]=='!'){
                            tempDiretor.setCodigo(codigo);
                            tempDiretor.setNome(nome);
                            tempDiretor.setEndereco(endereco);
                            tempDiretor.setTelefone(telefone);
                            tempDiretor.setDataIngresso(dataIngresso);
                            tempDiretor.setSalario(stof(salario));
                            tempDiretor.setAreaSupervisao(areaSupervisao);
                            tempDiretor.setAreaFormacao(areaFormacao);
                            return tempDiretor;
                            break;
                        }

                    }
                    
                }
            }
        }
        if(funcEncontrado==0){
            cout << "Diretor nao encontrado!\n";
        }
    }
}
c3Presidente GerenciaBD::consultaPresidente(string codigo1){
    string linha;
    string tempString = "";
    int funcEncontrado = 0;
    char ch;
    int atributos = 2;

    fstream arq;
    string codigo = "";
    string salario = "";
    string nome = "";
    string endereco = "";
    string telefone = "";
    string dataIngresso = "";
    string areaSupervisao = "";
    string areaFormacao = "";
    string formMax = "";

    arq.open("funcionarios.txt", ios::in);    
    if(arq.is_open()){
        while(getline(arq, linha)){        
            if(linha.find(codigo1) != string::npos){
                funcEncontrado = 1;
                tempPresidente.setDesig(4);
                tempString = linha;
                arq.close();
                for(int i = 2; i;i++){
                    if(tempString[i]==','){
                        atributos++;
                    }else{
                        switch(atributos){
                            case 2:
                                codigo += tempString[i];
                                break;
                            case 3:
                                nome += tempString[i];
                                break;
                            case 4:
                                endereco += tempString[i];
                                break;
                            case 5:
                                telefone += tempString[i];
                                break;
                            case 6:
                                dataIngresso += tempString[i];
                                break;
                            case 7:
                                salario += tempString[i];
                                break;
                            case 8:
                                areaSupervisao += tempString[i];
                                break;
                            case 9:
                                areaFormacao += tempString[i];
                                break;  
                            case 10:
                                formMax += tempString[i];
                            case 11:
                                break; 
                        }
                        if(tempString[i]=='!'){
                            tempPresidente.setCodigo(codigo);
                            tempPresidente.setNome(nome);
                            tempPresidente.setEndereco(endereco);
                            tempPresidente.setTelefone(telefone);
                            tempPresidente.setDataIngresso(dataIngresso);
                            tempPresidente.setSalario(stof(salario));
                            tempPresidente.setAreaSupervisao(areaSupervisao);
                            tempPresidente.setAreaFormacao(areaFormacao);
                            tempPresidente.setFormacaoMax(formMax);
                            return tempPresidente;
                            break;
                        }

                    }
                    
                }
            }
                
        }
        if(funcEncontrado==0){
            cout << "Presidente nao encontrado!\n";
        }
    }
   
}
void GerenciaBD::atualizaOperario(mFuncionario operario){
    removerFuncionario(operario.getCodigo());
    cadastrarOperario(operario);
}
void GerenciaBD::atualizaGerente(c1Gerente gerente){
    removerFuncionario(gerente.getCodigo());
    cadastrarGerente(gerente);
}
void GerenciaBD::atualizaDiretor(c2Diretor diretor){
    removerFuncionario(diretor.getCodigo());
    cadastrarDiretor(diretor);
}
void GerenciaBD::atualizaPresidente(c3Presidente presidente){
    removerFuncionario(presidente.getCodigo());
    cadastrarPresidente(presidente);
}

int GerenciaBD::retornaTipo(string codigo1){
    string linha;
    fstream arq;
    
    arq.open("funcionarios.txt", ios::in);
    
    if(arq.is_open()){
        while(getline(arq, linha)){        
            if(linha.find(codigo1) != string::npos){
                if(linha[0]=='1'){
                  return 1;  
                }
            
                if(linha[0]=='2'){
                   return 2;
                }
            
                if(linha[0]=='3'){
                    return 3;
                }
                if(linha[0]=='4'){
                   return 4;
                }
                }
            }
    }
    return -1;
}
void GerenciaBD::aumentaSalarios(){
    fstream arq;
    string temp;
    int tipo;
    int qt;
    string cod[100];
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

    aumentoSalario aumento;

    for(int i=0; i<qt; i++){
        tipo = retornaTipo(cod[i]);
        if(tipo == 1){
            cout << "----------------------------------------------------";
            this->tempOperario = this->consultaOperario(cod[i]);
            cout << "Salario antigo de " << tempOperario.getNome() << " (Operador)" <<": " << tempOperario.getSalario() << endl;
            aumento.aumentaSalario(1, tempOperario.getSalario());
            this->atualizaOperario(tempOperario);
            cout << "Salario atualizado de " << tempOperario.getNome() << " (Operador)" <<": " << tempOperario.getSalario() << endl;
            cout << "----------------------------------------------------\n";

        }else if(tipo == 2){
            cout << "----------------------------------------------------";
            this->tempGerente = this->consultaGerente(cod[i]);
            cout << "Salario antigo de " << tempGerente.getNome() << " (Gerente)" <<": " << tempGerente.getSalario() << endl;
            aumento.aumentaSalario(2, tempGerente.getSalario());
            this->atualizaGerente(tempGerente);
            cout << "Salario atualizado de " << tempGerente.getNome() << " (Gerente)" <<": " << tempGerente.getSalario() << endl;
            cout << "----------------------------------------------------\n";
                
        }else if(tipo == 3){
            cout << "----------------------------------------------------";
            this->tempDiretor = this->consultaDiretor(cod[i]);
            cout << "Salario antigo de " << tempDiretor.getNome() << " (Diretor)" <<": " << tempDiretor.getSalario() << endl;
            aumento.aumentaSalario(3, tempDiretor.getSalario());
            this->atualizaDiretor(tempDiretor);
            cout << "Salario atualizado de " << tempDiretor.getNome() << " (Diretor)" <<": " << tempDiretor.getSalario() << endl;
            cout << "----------------------------------------------------\n";

                
        }else if(tipo == 4){
            cout << "----------------------------------------------------";
            this->tempPresidente = this->consultaPresidente(cod[i]);
            cout << "Salario antigo de " << tempPresidente.getNome() << " (Presidente)" <<": " << tempPresidente.getSalario() << endl;
            aumento.aumentaSalario(4, tempPresidente.getSalario());
            this->atualizaPresidente(tempPresidente);
            cout << "Salario atualizado de " << tempPresidente.getNome() << " (Presidente)" <<": " << tempPresidente.getSalario() << endl;
            cout << "----------------------------------------------------\n";
        }else{
            break;
        }
    }            
}


//A DICIONARHORASEXTRAS

/*

e) Calcular Folha Salarial: Responsável por realizar o cálculo de salário de todos os funcionários
para um determinado mês. Assim, será solicitado do usuário o mês a que se refere a folha
salarial. Caso a folha para este mês já tenha sido calculada, exibir mensagem alertando que a
folha para o seguinte mês já foi calculada.


Deverá ser executada uma rotina que irá gerar
aleatoriamente, mas apenas uma única vez, as informações como o número de dias
trabalhados no mês pelo funcionário e o número de horas extras trabalhadas. Usar regra que a
hora-extra equivale ao dobro daquilo pago para hora normal. Deverá também ser contabilizado
os descontos relativos ao imposto de renda e previdência social.








*/

