#include "gerenciamento.h"

GerenciaBD::GerenciaBD(){
};
GerenciaBD::~GerenciaBD(){

};
void GerenciaBD::listarFuncionarios(){
    //imprimindo cada linha do arquivo que começa com o caracter 'O'
    string linha;
    ifstream arq("funcionarios.txt");
    if(arq.is_open()){
        while(getline(arq, linha)){
            if(linha[0]=='1'){
                cout << linha << endl;
            }
            
        };
    }
    else{
        cout << "Erro ao abrir arquivo" << endl;
    }
};
//void GerenciaBD::listarFuncionarios(int desig);
//void GerenciaBD::listarFuncionarios(string nome);
/*void GerenciaBD::cadastrarOperador(mFuncionario novo){
    arq.open("funcionarios.txt", ios::app);
    string operador = "O,"+novo.getCodigo()+","+novo.getNome()+","+novo.getEndereco()+","+novo.getTelefone()+","+novo.getDataIngresso()+","+to_string(novo.getSalario())+","+to_string(novo.getDesig())+"\n";
    // abrindo o arquivo:
    // escrevendo a frase no arquivo:
    arq << operador;
    // fechando o arquivo:
    arq.close();
};*/


/*
● Gerente: nome da área de supervisão
● Diretor: nome da área de supervisão e área de formação
● Presidente: área de formação e qual formação acadêmica máxima (por exemplo,
especialista, mestre, doutor...)
*/
void GerenciaBD::cadastrarFuncionario(int tipo){
    fstream arq;
    arq.open("funcionarios.txt", ios::app);
    string funcionario;
    string codigo;
    float salario;
    string nome, endereco, telefone, dataIngresso, areaSupervisao, areaFormacao, formMax;
    switch(tipo){
        case 1:
            cout << "Adicionando Operador...\n";
            cout << "Digite o codigo do funcionario: ";
            cin >> codigo;
            cout << "Digite o nome do funcionario: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Digite o endereco do funcionario: \n";
            getline(cin, endereco);
            cout << "Digite o telefone do funcionario: \n";
            getline(cin, telefone);
            cout << "Digite a data de ingresso do funcionario: \n";
            getline(cin, dataIngresso);
            cout << "Digite o salario do funcionario: \n";
            cin >> salario;
            // Para o arquivo:
            funcionario = "\n"+to_string(tipo)+","+codigo+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+"!\n";            
            arq << funcionario;
            arq.close();
            break;
        case 2:
            cout << "Adicionando Gerente...\n";
            cout << "Digite o codigo do gerente: ";
            cin >> codigo;
            cout << "Digite o nome do gerente: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Digite o endereco do gerente: \n";
            getline(cin, endereco);
            cout << "Digite o telefone do gerente: \n";
            getline(cin, telefone);
            cout << "Digite a data de ingresso do gerente: \n";
            getline(cin, dataIngresso);
            cout << "Digite a área de supervisão do gerente: \n";
            getline(cin, areaSupervisao);
            cout << "Digite o salario do gerente: \n";
            cin >> salario;
            // Para o arquivo:
            funcionario = "\n"+to_string(tipo)+","+codigo+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+","+areaSupervisao+"!\n";            
            arq << funcionario;
            arq.close();
            break;
        case 3:
            cout << "Adicionando Diretor...\n";
            cout << "Digite o codigo do diretor: ";
            cin >> codigo;
            cout << "Digite o nome do diretor: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Digite o endereco do diretor: \n";
            getline(cin, endereco);
            cout << "Digite o telefone do diretor: \n";
            getline(cin, telefone);
            cout << "Digite a data de ingresso do diretor: \n";
            getline(cin, dataIngresso);
            cout << "Digite a área de supervisão do diretor: \n";
            getline(cin, areaSupervisao);
            cout << "Digite a área de formação do diretor: \n";
            getline(cin, areaFormacao);
            cout << "Digite o salario do diretor: \n";
            cin >> salario;
            // Para o arquivo:
            funcionario = "\n"+to_string(tipo)+","+codigo+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+","+areaSupervisao+","+areaFormacao+"!\n";            
            arq << funcionario;
            arq.close();
            break;
        case 4:
            cout << "Adicionando Presidente...\n";
            cout << "Digite o codigo do presidente: ";
            cin >> codigo;
            cout << "Digite o nome do presidente: ";
            cin.ignore();
            getline(cin, nome);
            cout << "Digite o endereco do presidente: \n";
            getline(cin, endereco);
            cout << "Digite o telefone do presidente: \n";
            getline(cin, telefone);
            cout << "Digite a data de ingresso do presidente: \n";
            getline(cin, dataIngresso);
            cout << "Digite a área de formação do presidente: \n";
            getline(cin, areaFormacao);
            cout << "Digite a formação acadêmica máxima do presidente: \n";
            getline(cin, formMax);
            cout << "Digite o salario do presidente: \n";
            cin >> salario;
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



    cout << "Removendo funcionario...\n";
    cout << "Você tem certeza?";
    char opcao;
    cin >> opcao;
    if(opcao == 's'){
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
                cout << "Funcionario removido com sucesso!\n";
            }else{
                cout << "Funcionario nao encontrado!\n";   
            }   
            }
    }
};
void GerenciaBD::consulta(string codigo1){
    
    string linha;
    int funcEncontrado = 0;

    cout << "Procurando funcionario...\n";    

    fstream arq;
    arq.open("funcionarios.txt", ios::in);
    if(arq.is_open()){
        while(getline(arq, linha)){
            if(linha.find(codigo1) != string::npos){
                funcEncontrado = 1;
                string codigo = "";
                string nome = "";
                string endereco = "";
                string telefone = "";
                string dataIngresso = "";
                string salario = "";
                string areaSupervisao = "";
                string areaFormacao = "";
                string formMax = "";
                
                if(linha[0]=='0'){
                    int atributos = 2;
                    tempOperario.setDesig(0);

                    cout << "Funcionario encontrado!\n";
                    for(int i=2; linha[i]!='!'; i++){ // I começando em 2 porque 0 é o idFunc, 1 é a vírgula.
                        
                        if(linha[i]=='!'){
                        }else if(linha[i]==','){
                            atributos++;
                            continue;
                        }else{
                            //funcionario = "\n"+to_string(tipo)+","+codigo+","+nome+","+endereco+","+telefone+","+dataIngresso+","+to_string(salario)+","+areaFormacao+","+formMax+"!\n";       
                            switch(atributos){
                                case 2:
                                    codigo = codigo + linha[i];
                                    break;
                                case 3:
                                    nome = nome + linha[i];
                                    break;
                                case 4:
                                    endereco = endereco + linha[i];
                                    break;
                                case 5:
                                    telefone = telefone + linha[i];
                                    break;
                                case 6:
                                    dataIngresso = dataIngresso + linha[i];
                                    break;
                                case 7:
                                    salario = salario + linha[i];
                                    break;
                                case 8: 
                                    areaFormacao = areaFormacao + linha[i];     
                                    break;
                                case 9: 
                                    formMax = formMax + linha[i];
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                }
            }
        }
        arq.close();
        if(funcEncontrado==0){
            cout << "Funcionario nao encontrado!\n";
        }else{
            cout << "Codigo: " << codigo << "\n";
            cout << "Nome: " << nome << "\n";
            cout << "Endereco: " << endereco << "\n";
            cout << "Telefone: " << telefone << "\n";
            cout << "Data de ingresso: " << dataIngresso << "\n";
            cout << "Salario: " << salario << "\n";
            cout << "Area de supervisao: " << areaSupervisao << "\n";
            cout << "Area de formacao: " << areaFormacao << "\n";
        }
        
        
    }      
}




