/*
O sistema deve possuir os tipos Operador, Gerente, Diretor e Presidente. Todos devem possuir
os atributos: número do código do funcionário, nome, endereço, telefone, data de ingresso,
designação (indica se é operador, gerente, diretor ou presidente) e salário.
*/

/*
Designação são de acordo com a tabela abaixo:
1 - Operador
2 - Gerente
3 - Diretor 
4 - Presidente
*/


#include <iostream>
#include <string.h>

using namespace std;

class mFuncionario
{
    public:
        mFuncionario();
        mFuncionario(int codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig);
      
        
        //Getters
        int getCodigo();
        int getDesig();
        string getNome();
        string getEndereco();
        string getTelefone();
        string getDataIngresso();
        float getSalario();

        //Setters
        void setCodigo(int codigo);
        void setDesig(int desig);
        void setNome(string nome);
        void setEndereco(string endereco);
        void setTelefone(string telefone);
        void setDataIngresso(string dataIngresso);
        void setSalario(float salario);

    protected:
        int codigo;
        int desig;

        string nome;
        string endereco;
        string telefone;
        string dataIngresso;
        float salario;

};
