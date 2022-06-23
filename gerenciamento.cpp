#include "gerenciamento.h"
#include <windows.h>
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

---------------------------------------------------------------------------------------------------------------------
.listarFuncionarios();✅
---------------------------------------------------------------------------------------------------------------------
Ap.1.
Caso o filtro cargo '1' seja passado será impresso todos os funcionários de OPERADORES, e assim por diante.
Caso o filtro cargo seja '0' será impresso todos os funcionários.

Ap.2.
Para utilizar qualquer outro filtro basta passar o desejado em formato de string, será visto em todos os funcionários
aqueles que possuírem o designado.
*/

void GerenciaBD::listarFuncionarios(int filtroCargo, string qualquerAtributo){ // ✅

    fstream arqParaQT;
    int qt = -1;
    string temp;
    string cod[100];
    int tipo;
    
    // Obtenção do código de todos os funcionários
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

    // Caso filtro == 0: imprime todos os funcionários
    // Caso seja entre 1 e 4: imprime todos os funcionários de determinado cargo
    if(filtroCargo == 0){          
        for(int i=0; i<=qt; i++){
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
            }
        }
    }else if(filtroCargo == 1){
        for(int i=0; i<=qt; i++){
            tipo = retornaTipo(cod[i]);
            if(tipo == 1){
                this->tempOperario = this->consultaOperario(cod[i]);
                tempOperario.imprime();
            }
        }
    }else if(filtroCargo == 2){
        for(int i=0; i<=qt; i++){
            tipo = retornaTipo(cod[i]);
            if(tipo == 2){
                this->tempGerente = this->consultaGerente(cod[i]);
                tempGerente.imprime();  
            }
        }
    }else if(filtroCargo == 3){
        for(int i=0; i<=qt; i++){
            tipo = retornaTipo(cod[i]);
            if(tipo == 3){
                this->tempDiretor = this->consultaDiretor(cod[i]);
                tempDiretor.imprime();      
            }
        }
    }else if(filtroCargo == 4){
        for(int i=0; i<=qt; i++){
            tipo = retornaTipo(cod[i]);
            if(tipo == 4){
                this->tempPresidente = this->consultaPresidente(cod[i]);
                tempPresidente.imprime();    
            }
        }
        
    }

    // Caso a busca seja parcial por qualquer atributo:
    // Necessário que filtroCargo == -1.
    if(qualquerAtributo != "" && filtroCargo == -1){
        int total = 0;    
        string codComString[100];

        // Preenchimento de todos os códigos de funcionários como string
        for(int i = 0; i<100; i++){
            codComString[i] = "";
        }


        arqParaQT.open("funcionarios.txt", ios::in);
        // Caso seja encontrado qualque atributo parcialmente
        // Será copiado o código do funcionário para o array de strings

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


        // Impressão de todos os funcionários que possuem parcialmente ou completamente
        // o atributo desejado.
        for(int i=0; i<=total; i++){
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

/*----------------------------------------------------------------------------------------------------------------------
.cadastrarOperario();
.cadastrarGerente();
.cadastrarDiretor();
.cadastrarPresidente();
//----------------------------------------------------------------------------------------------------------------------

Funções para cadastro de funcionário à partir do OBJETO de cada funcionário referente.
As funções abaixo são uma otimização da função .cadastrarFuncionario(), utilizada para cadastrar o funcionário
diretamente no BD.

Não é pedido ao usuário dados nestas funções para o cadastro do funcionário, são para cadastros já existentes.
Para cadastrar um funcionário, a partir de dados digitados pelo usuário, utilize a função .cadastrarFuncionario().

*/
void GerenciaBD::cadastrarOperario(mFuncionario novo){
    //cadastrando novo operario
    fstream arq;
    int tipo = 1;
    arq.open("funcionarios.txt", ios::app);
    string funcionario;
    funcionario = to_string(tipo)+","+novo.getCodigo()+","+novo.getNome()+","+novo.getEndereco()+","+novo.getTelefone()+","+novo.getDataIngresso()+","+to_string(novo.getSalario())+","+to_string(novo.getDiasTrabalhados())+","+to_string(novo.getTotalHorasExtras())+"!\n";            
    arq << funcionario;
    arq.close();
};
void GerenciaBD::cadastrarGerente(c1Gerente novo){
    //cadastrando novo gerente
    fstream arq;
    int tipo = 2;
    arq.open("funcionarios.txt", ios::app);
    string funcionario;
    funcionario = to_string(tipo)+","+novo.getCodigo()+","+novo.getNome()+","+novo.getEndereco()+","+novo.getTelefone()+","+novo.getDataIngresso()+","+to_string(novo.getSalario())+","+to_string(novo.getDiasTrabalhados())+","+to_string(novo.getTotalHorasExtras())+","+novo.getAreaSupervisao()+"!\n";
    arq << funcionario;
    arq.close();
};
void GerenciaBD::cadastrarDiretor(c2Diretor novo){
    //cadastrando novo diretor
    fstream arq;
    int tipo = 3;
    arq.open("funcionarios.txt", ios::app);
    string funcionario;
    if(novo.getAreaFormacao().find("!")!=string::npos){
        string nova = novo.getAreaFormacao();
        nova.erase(nova.find("!"), 1);
        novo.setAreaFormacao(nova);
    }
    funcionario = to_string(tipo)+","+novo.getCodigo()+","+novo.getNome()+","+novo.getEndereco()+","+novo.getTelefone()+","+novo.getDataIngresso()+","+to_string(novo.getSalario())+","+to_string(novo.getDiasTrabalhados())+","+to_string(novo.getTotalHorasExtras())+","+novo.getAreaSupervisao()+","+novo.getAreaFormacao()+"!\n";
    arq << funcionario;
    arq.close();
};
void GerenciaBD::cadastrarPresidente(c3Presidente novo){
    //cadastrando novo presidente
    fstream arq;
    int tipo = 4;
    arq.open("funcionarios.txt", ios::app);
    string funcionario;
    funcionario = to_string(tipo)+","+novo.getCodigo()+","+novo.getNome()+","+novo.getEndereco()+","+novo.getTelefone()+","+novo.getDataIngresso()+","+to_string(novo.getSalario())+","+to_string(novo.getDiasTrabalhados())+","+to_string(novo.getTotalHorasExtras())+","+novo.getAreaSupervisao()+","+novo.getAreaFormacao()+","+novo.getFormacaoMax()+"!\n";
    arq << funcionario;
    arq.close();
};


/*
----------------------------------------------------------------------------------------------------------------------
.cadastrarFuncionario();
----------------------------------------------------------------------------------------------------------------------

    A partir da designação (tipo) do funcionário, a função irá colher os dados referente a cada funcionário.
    Todos os dados são cadastros automaticamente no BD.

    -> Será seguido, para todos os tipos de funcionário, o padrão de cadastro.
        -> Código do funcionário
        -> Nome do funcionário
        -> Endereço do funcionário
        -> Telefone do funcionário
        -> Data de ingresso do funcionário
        -> Salário do funcionário
        -> Área de supervisão do funcionário
        -> Área de formação do funcionário
        -> Formação máxima do funcionário
    *Essa função possui 'cout' para cada pergunta.

*/
void GerenciaBD::cadastrarFuncionario(int tipo){
    fstream arq;
    arq.open("funcionarios.txt", ios::app);
    string funcionario;
    string codigo;
    float salario;
    string nome, endereco, telefone, dataIngresso, areaSupervisao, areaFormacao, formMax;


    cout << "Digite o codigo do funcionario: ";
    cin >> codigo;
    if(codigo.find(",")!= string::npos){
        codigo.erase(codigo.find(","), 1);
    }
    cout << "Digite o nome do funcionario: ";
    cin.ignore();
    getline(cin, nome);
    if(nome.find(",")!= string::npos){
        nome.erase(nome.find(","), 1);
    }
    cout << "Digite o endereco do funcionario: \n";
    getline(cin, endereco);
    if(endereco.find(",")!= string::npos){
        endereco.erase(endereco.find(","), 1);
    }
    cout << "Digite o telefone do funcionario: \n";
    getline(cin, telefone);
    if(telefone.find(",")!= string::npos){
        telefone.erase(telefone.find(","), 1);
    }
    cout << "Digite a data de ingresso do funcionario: \n";
    getline(cin, dataIngresso);
    if(dataIngresso.find(",")!= string::npos){
        dataIngresso.erase(dataIngresso.find(","), 1);
    }
    cout << "Digite o salario do funcionario: \n";
    cin >> salario;
    
    switch(tipo){
        case 1:
            // Para o arquivo:
            funcionario = "\n"+to_string(tipo)+","+codigo+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+",0,"+"23"+"!\n";            
            arq << funcionario;
            arq.close();
            break;
        case 2:
            cin.ignore();
            cout << "Digite a área de supervisão do gerente: \n";
            getline(cin, areaSupervisao);
            if(areaSupervisao.find(",")!= string::npos){
                areaSupervisao.erase(areaSupervisao.find(","), 1);
            }
            if(areaSupervisao.find("!")!= string::npos){
                areaSupervisao.erase(areaSupervisao.find("!"), 1);
            }
            funcionario = "\n"+to_string(tipo)+","+codigo+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+",0,"+"23"+","+areaSupervisao+"!\n";            
            arq << funcionario;
            arq.close();
            break;
        case 3:
            cin.ignore();
            cout << "Digite a área de supervisão do diretor: \n";
            getline(cin, areaSupervisao);
            if(areaSupervisao.find(",")!= string::npos){
                areaSupervisao.erase(areaSupervisao.find(","), 1);
            }
            
            cout << "Digite a área de formação do diretor: \n";
            getline(cin, areaFormacao);
            if(areaFormacao.find(",")!= string::npos){
                areaFormacao.erase(areaFormacao.find(","), 1);
            }
            if(areaFormacao.find("!")!= string::npos){
                areaFormacao.erase(areaFormacao.find("!"), 1);
            }
            // Para o arquivo:
            funcionario = "\n"+to_string(tipo)+","+codigo+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+",0,"+"23"+","+areaSupervisao+","+areaFormacao+"!\n";            
            arq << funcionario;
            arq.close();
            break;
        case 4:
            cin.ignore();
            cout << "Digite a área de supervisão do presidente: \n";
            getline(cin, areaSupervisao);
            if(areaSupervisao.find(",")!= string::npos){
                areaSupervisao.erase(areaSupervisao.find(","), 1);
            }
            cout << "Digite a área de formação do presidente: \n";
            getline(cin, areaFormacao);
            if(areaFormacao.find(",")!= string::npos){
                areaFormacao.erase(areaFormacao.find(","), 1);
            }
            cout << "Digite a formação acadêmica máxima do presidente: \n";
            getline(cin, formMax);
            if(formMax.find(",")!= string::npos){
                formMax.erase(formMax.find(","), 1);
            }
            if(formMax.find("!")!= string::npos){
                formMax.erase(formMax.find("!"), 1);
            }
            // Para o arquivo:
            funcionario = "\n"+to_string(tipo)+","+codigo+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+",0,"+"23"+","+areaSupervisao+","+areaFormacao+","+formMax+"!\n";           
            arq << funcionario;
            arq.close();
            break;
    }
    cout << "Deseja adicionar uma fotografia do funcionario? (s/n) \n";
    char opcao;
    cin >> opcao;
    
    if(opcao == 's'|| opcao == 'S'){
        this->tirarFotografia(tipo, codigo);
    }else{
        cout << "Fotografia não adicionada.\n";
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
    }else if(tipo == 2){
        c1Gerente tempGerente = c1Gerente();
        tempGerente = this->consultaGerente(codigo1);
        while(1){
            cout << "O que voce deseja alterar?\n";
            cout << "1 - Nome\n";
            cout << "2 - Endereco\n";
            cout << "3 - Telefone\n";
            cout << "4 - Data de ingresso\n";
            cout << "5 - Salario\n";
            cout << "6 - Criar novo CF\n";
            cout << "7 - Area de supervisao\n";            
            cout << "8 - Cancelar operacao\n";
            int opcao;
            cin >> opcao;
            if(opcao == 8){
                break;
            }else if(opcao == 1){
                cout << "Digite o novo nome: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempGerente.setNome(tempString);
                cout << "Nome alterado com sucesso!\n";
            }else if(opcao == 2){
                cout << "Digite o novo endereco: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempGerente.setEndereco(tempString);
                cout << "Endereco alterado com sucesso!\n";
            }else if(opcao == 3){
                cout << "Digite o novo telefone: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempGerente.setTelefone(tempString);
                cout << "Digite a nova data de ingresso: \n";
            }else if(opcao == 4){
                cout << "Digite a nova data de ingresso: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempGerente.setDataIngresso(tempString);
                cout << "Data alterada com sucesso!\n";
            }else if(opcao == 5){
                cout << "Digite o novo salario: \n";
                float salarioNovo;
                cin >> salarioNovo;
                tempGerente.setSalario(salarioNovo);
                cout << "Salario alterado com sucesso!\n";
            }else if(opcao == 6){
                cout << "Digite o novo codigo do CF: \n";
                string codigoNovo;
                cin >> codigoNovo;
                tempGerente.setCodigo(codigoNovo);
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
        this->cadastrarGerente(tempGerente);
    }else if(tipo == 3){
        c2Diretor tempDiretor = c2Diretor();
        tempDiretor = this->consultaDiretor(codigo1);
        while(1){
            cout << "O que voce deseja alterar?\n";
            cout << "1 - Nome\n";
            cout << "2 - Endereco\n";
            cout << "3 - Telefone\n";
            cout << "4 - Data de ingresso\n";
            cout << "5 - Salario\n";
            cout << "6 - Criar novo CF\n";
            cout << "7 - Area de supervisao\n";
            cout << "8 - Area de Formacao\n";
            cout << "9 - Cancelar operacao\n";
            int opcao;
            cin >> opcao;
            if(opcao == 9){
                break;
            }else if(opcao == 1){
                cout << "Digite o novo nome: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempDiretor.setNome(tempString);
                cout << "Nome alterado com sucesso!\n";
            }else if(opcao == 2){
                cout << "Digite o novo endereco: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempDiretor.setEndereco(tempString);
                cout << "Endereco alterado com sucesso!\n";
            }else if(opcao == 3){
                cout << "Digite o novo telefone: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempDiretor.setTelefone(tempString);
                cout << "Digite a nova data de ingresso: \n";
            }else if(opcao == 4){
                cout << "Digite a nova data de ingresso: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempDiretor.setDataIngresso(tempString);
                cout << "Data alterada com sucesso!\n";
            }else if(opcao == 5){
                cout << "Digite o novo salario: \n";
                float salarioNovo;
                cin >> salarioNovo;
                tempDiretor.setSalario(salarioNovo);
                cout << "Salario alterado com sucesso!\n";
            }else if(opcao == 6){
                cout << "Digite o novo codigo do CF: \n";
                string codigoNovo;
                cin >> codigoNovo;
                tempDiretor.setCodigo(codigoNovo);
                cout << "Codigo atualizado!\n";
            }else if(opcao == 7){
                cout << "Digite a nova area de supervisao: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempDiretor.setAreaSupervisao(tempString);
                cout << "Area de supervisao alterada com sucesso!\n";
            }else if(opcao == 8){
                cout << "Digite a nova area de formacao: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempDiretor.setAreaFormacao(tempString);
                cout << "Area de formacao alterada com sucesso!\n";
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
        this->cadastrarDiretor(tempDiretor);
    }else if(tipo == 4){
        c3Presidente tempPresidente = c3Presidente();
        tempPresidente = this->consultaPresidente(codigo1);
        while(1){
            cout << "O que voce deseja alterar?\n";
            cout << "1 - Nome\n";
            cout << "2 - Endereco\n";
            cout << "3 - Telefone\n";
            cout << "4 - Data de ingresso\n";
            cout << "5 - Salario\n";
            cout << "6 - Criar novo CF\n";
            cout << "7 - Area de supervisao\n";
            cout << "8 - Area de Formacao\n";
            cout << "9 - Formacao Maxima\n";
            cout << "10 - Cancelar operacao\n";
            int opcao;
            cin >> opcao;
            if(opcao == 10){
                break;
            }else if(opcao == 1){
                cout << "Digite o novo nome: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempPresidente.setNome(tempString);
                cout << "Nome alterado com sucesso!\n";
            }else if(opcao == 2){
                cout << "Digite o novo endereco: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempPresidente.setEndereco(tempString);
                cout << "Endereco alterado com sucesso!\n";
            }else if(opcao == 3){
                cout << "Digite o novo telefone: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempPresidente.setTelefone(tempString);
                cout << "Digite a nova data de ingresso: \n";
            }else if(opcao == 4){
                cout << "Digite a nova data de ingresso: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempPresidente.setDataIngresso(tempString);
                cout << "Data alterada com sucesso!\n";
            }else if(opcao == 5){
                cout << "Digite o novo salario: \n";
                float salarioNovo;
                cin >> salarioNovo;
                tempPresidente.setSalario(salarioNovo);
                cout << "Salario alterado com sucesso!\n";
            }else if(opcao == 6){
                cout << "Digite o novo codigo do CF: \n";
                string codigoNovo;
                cin >> codigoNovo;
                tempPresidente.setCodigo(codigoNovo);
                cout << "Codigo atualizado!\n";
            }else if(opcao == 7){
                cout << "Digite a nova area de supervisao: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempPresidente.setAreaSupervisao(tempString);
                cout << "Area de supervisao alterada com sucesso!\n";
            }else if(opcao == 8){
                cout << "Digite a nova area de formacao: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempPresidente.setAreaFormacao(tempString);
                cout << "Area de formacao alterada com sucesso!\n";
            }else if(opcao == 9){
                cout << "Digite a nova formacao maxima: \n";
                cin.ignore();
                string tempString;
                getline(cin, tempString);
                tempPresidente.setFormacaoMax(tempString);
                cout << "Formacao maxima alterada com sucesso!\n";
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
            this->cadastrarPresidente(tempPresidente);
    }else{
        cout << "Operação cancelada!\n";
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
    string totalHorasExtras = "";
    string diasTrabalhados = "";
    
        
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
                                totalHorasExtras += tempString[i];
                                break;
                            case 9:
                                diasTrabalhados += tempString[i];
                                break;
                            case 10:
                                break;
                        }
                        if(tempString[i]=='!'){
                            tempOperario.setCodigo(codigo);
                            tempOperario.setNome(nome);
                            tempOperario.setEndereco(endereco);
                            tempOperario.setTelefone(telefone);
                            tempOperario.setDataIngresso(dataIngresso);
                            tempOperario.setSalario(stof(salario));
                            tempOperario.setTotalHorasExtras(stoi(totalHorasExtras));
                            tempOperario.setDiasTrabalhados(stoi(diasTrabalhados));
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
    string diasTrabalhados = "";
    string totalHorasExtras = "";

    
        
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
                                totalHorasExtras += tempString[i];
                                break;
                            case 9:
                                diasTrabalhados += tempString[i];
                                break;
                            case 11:
                                areaSupervisao += tempString[i];
                                break;
                            case 12:
                                break;    
                        }
                        if(tempString[i]=='!'){
                            tempGerente.setCodigo(codigo);
                            tempGerente.setNome(nome);
                            tempGerente.setEndereco(endereco);
                            tempGerente.setTelefone(telefone);
                            tempGerente.setDataIngresso(dataIngresso);
                            tempGerente.setSalario(stof(salario));
                            tempGerente.setTotalHorasExtras(stoi(totalHorasExtras));
                            tempGerente.setDiasTrabalhados(stoi(diasTrabalhados));
                            if(areaSupervisao.find("!")!=string::npos){
                                areaSupervisao.erase(areaSupervisao.find("!"), 1);
                            }
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
    string diasTrabalhados = "";
    string totalHorasExtras = "";

    

        
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
                                totalHorasExtras += tempString[i];
                                break;
                            case 9:
                                diasTrabalhados += tempString[i];
                                break;
                            case 10:
                                areaSupervisao += tempString[i];
                                break;
                            case 11:
                                areaFormacao += tempString[i];
                                break;
                            case 12:
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
                            if(areaFormacao.find("!")!=string::npos){
                                areaFormacao.erase(areaFormacao.find("!"), 1);
                            }
                            tempDiretor.setDiasTrabalhados(stoi(diasTrabalhados));
                            tempDiretor.setTotalHorasExtras(stoi(totalHorasExtras));
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
    string diasTrabalhados = "";
    string totalHorasExtras = "";


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
                                totalHorasExtras += tempString[i];
                                break;
                            case 9:
                                diasTrabalhados += tempString[i];
                                break;
                            case 10:
                                areaSupervisao += tempString[i];
                                break;
                            case 11:
                                areaFormacao += tempString[i];
                                break;  
                            case 12:
                                formMax += tempString[i];
                            case 13:
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
                            
                            if(formMax.find("!")!=string::npos){
                                formMax.erase(formMax.find("!"), 1);
                            }
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
void GerenciaBD::tirarFotografia(int designacao, string codigo){

   
    bool sair = false;
    while(sair != true){
        system(".\\cam");
        system(".\\tempFoto.png");
        cout << "Deseja tirar outra foto? (s/n)\n";
        char opcao;
        cin >> opcao;
        if(opcao == 's'){
            sair = false;
        }else{
            sair = true;
        }
    };      
    string novoNome = to_string(designacao) + "_" + codigo + ".png";
    rename("tempFoto.png", novoNome.c_str());
    string tempCmd;
    
    if(designacao == 1){
       tempCmd = "Copy .\\" + novoNome + " fotoOperarios\\" + novoNome;
    }else if(designacao == 2){
        tempCmd = "Copy .\\" + novoNome + " fotoGerentes\\" + novoNome;
    }else if(designacao == 3){
        tempCmd = "Copy " + novoNome + " fotoDiretores\\" + novoNome;
    }else if(designacao == 4){
        tempCmd = "Copy .\\"+novoNome+" fotoPresidentes\\"+novoNome;
    }
    system(tempCmd.c_str());
    system("cls");
    cout << "Foto tirada com sucesso!\n";
    system("pause");

    
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
    qt = -1;
    arq.open("funcionarios.txt", ios::in);
    if(arq.is_open()){
        while(getline(arq, temp)){
            qt++;
            for(int i=2; temp[i]!=','; i++){
                cod[qt] += temp[i];
            }
            }
    }
    arq.close();

    aumentoSalario aumento;

    for(int i=0; i<=qt; i++){
        tipo = retornaTipo(cod[i]);
        if(tipo == 1){
            cout << "----------------------------------------------------\n";
            this->tempOperario = this->consultaOperario(cod[i]);
            cout << "Salario antigo de " << tempOperario.getNome() << " (Operador)" <<": " << tempOperario.getSalario() << endl;
            int novoSalario = aumento.aumentaSalario(1, tempOperario.getSalario());
            tempOperario.setSalario(novoSalario);
            this->atualizaOperario(tempOperario);
            cout << "Salario atualizado de " << tempOperario.getNome() << " (Operador)" <<": " << tempOperario.getSalario() << endl;
            cout << "----------------------------------------------------\n";

        }else if(tipo == 2){
            cout << "----------------------------------------------------\n";
            this->tempGerente = this->consultaGerente(cod[i]);
            cout << "Salario antigo de " << tempGerente.getNome() << " (Gerente)" <<": " << tempGerente.getSalario() << endl;
            int novoSalario = aumento.aumentaSalario(2, tempGerente.getSalario());  
            tempGerente.setSalario(novoSalario);
            if(tempGerente.getAreaSupervisao().find("!")!=string::npos){
                string temp = tempGerente.getAreaSupervisao();
                temp.erase(temp.find("!"), 1);
                tempGerente.setAreaSupervisao(temp);
            }
            this->atualizaGerente(tempGerente);
            cout << "Salario atualizado de " << tempGerente.getNome() << " (Gerente)" <<": " << tempGerente.getSalario() << endl;
            cout << "----------------------------------------------------\n";
        }else if(tipo == 3){
            cout << "----------------------------------------------------\n";
            this->tempDiretor = this->consultaDiretor(cod[i]);
            cout << "Salario antigo de " << tempDiretor.getNome() << " (Diretor)" <<": " << tempDiretor.getSalario() << endl;
            int novoSalario = aumento.aumentaSalario(3, tempDiretor.getSalario());
            tempDiretor.setSalario(novoSalario);
            this->atualizaDiretor(tempDiretor);
            cout << "Salario atualizado de " << tempDiretor.getNome() << " (Diretor)" <<": " << tempDiretor.getSalario() << endl;
            cout << "----------------------------------------------------\n";
        }else if(tipo == 4){
            cout << "----------------------------------------------------\n";
            this->tempPresidente = this->consultaPresidente(cod[i]);
            cout << "Salario antigo de " << tempPresidente.getNome() << " (Presidente)" <<": " << tempPresidente.getSalario() << endl;
            int novoSalario = aumento.aumentaSalario(4, tempPresidente.getSalario());
            tempPresidente.setSalario(novoSalario);
            this->atualizaPresidente(tempPresidente);
            cout << "Salario atualizado de " << tempPresidente.getNome() << " (Presidente)" <<": " << tempPresidente.getSalario() << endl;
            cout << "----------------------------------------------------\n";
        }else{
            cout << "Erro ao aumentar salario de: \n" << cod[i] << endl;
        }


    }
                
}
void GerenciaBD::aumentaSalarioEspecifico(string codigo){
    int tipo = retornaTipo(codigo);
    if(tipo == 1){
        cout << "----------------------------------------------------\n";
        this->tempOperario = this->consultaOperario(codigo);
        cout << "Salario antigo de " << tempOperario.getNome() << " (Operador)" <<": " << tempOperario.getSalario() << endl;
        aumentoSalario aumento;
        float salarioAumentado = aumento.aumentaSalario(1, tempOperario.getSalario());
        tempOperario.setSalario(salarioAumentado);
        this->atualizaOperario(tempOperario);
        cout << "Salario atualizado de " << tempOperario.getNome() << " (Operador)" <<": " << tempOperario.getSalario() << endl;
        cout << "----------------------------------------------------\n";
    }else if(tipo == 2){
        cout << "----------------------------------------------------\n";
        this->tempGerente = this->consultaGerente(codigo);
        cout << "Salario antigo de " << tempGerente.getNome() << " (Gerente)" <<": " << tempGerente.getSalario() << endl;
        aumentoSalario aumento;
        float salarioAumentado = aumento.aumentaSalario(2, tempGerente.getSalario());
        tempGerente.setSalario(salarioAumentado);
        this->atualizaGerente(tempGerente);
        cout << "Salario atualizado de " << tempGerente.getNome() << " (Gerente)" <<": " << tempGerente.getSalario() << endl;
        cout << "----------------------------------------------------\n";
    }else if(tipo == 3){
        cout << "----------------------------------------------------\n";
        this->tempDiretor = this->consultaDiretor(codigo);
        cout << "Salario antigo de " << tempDiretor.getNome() << " (Diretor)" <<": " << tempDiretor.getSalario() << endl;
        aumentoSalario aumento;
        float salarioAumentado = aumento.aumentaSalario(3, tempDiretor.getSalario());
        tempDiretor.setSalario(salarioAumentado);
        this->atualizaDiretor(tempDiretor);
        cout << "Salario atualizado de " << tempDiretor.getNome() << " (Diretor)" <<": " << tempDiretor.getSalario() << endl;
        cout << "----------------------------------------------------\n";
    }else if(tipo == 4){
        cout << "----------------------------------------------------\n";
        this->tempPresidente = this->consultaPresidente(codigo);
        cout << "Salario antigo de " << tempPresidente.getNome() << " (Presidente)" <<": " << tempPresidente.getSalario() << endl;
        aumentoSalario aumento;
        float salarioAumentado = aumento.aumentaSalario(4, tempPresidente.getSalario());
        tempPresidente.setSalario(salarioAumentado);
        this->atualizaPresidente(tempPresidente);
        cout << "Salario atualizado de " << tempPresidente.getNome() << " (Presidente)" <<": " << tempPresidente.getSalario() << endl;
        cout << "----------------------------------------------------\n";
    }else{
        cout << "----------------------------------------------------\n";
        cout << "Codigo invalido\n";
        cout << "----------------------------------------------------\n";
    }



};


/*
Essa função aleatoriza todas as horas extras e todos os dias trabalhados de todos os funcionários.
*/
void GerenciaBD::aleatorizaHD(){
    fstream arq;
    string temp;
    int qt;
    string cod[100];
    qt = -1;
    arq.open("funcionarios.txt", ios::in);
    if(arq.is_open()){
        while(getline(arq, temp)){
            qt++;
            for(int i=2; temp[i]!=','; i++){
                cod[qt] += temp[i];
            }
            }
    }
    arq.close();

    for(int i=0; i<=qt; i++){
        int tipo = this->retornaTipo(cod[i]);//ok
        if(tipo == 1){
            this->tempOperario = this->consultaOperario(cod[i]);//
            tempOperario.aleatorio();
            this->atualizaOperario(tempOperario);
        }else if(tipo == 2){
            this->tempGerente = this->consultaGerente(cod[i]);
            tempGerente.aleatorio();
            this->atualizaGerente(tempGerente);
        }else if(tipo == 3){
            this->tempDiretor = this->consultaDiretor(cod[i]);
            tempDiretor.aleatorio();
            this->atualizaDiretor(tempDiretor);
        }else if(tipo == 4){
            this->tempPresidente = this->consultaPresidente(cod[i]);
            tempPresidente.aleatorio();
            this->atualizaPresidente(tempPresidente);
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

