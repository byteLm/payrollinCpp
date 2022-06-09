
#include <iostream>
#include <string.h>

using namespace std;

class mFuncionario
{
    public:
        mFuncionario();
        mFuncionario(string codigo, string nome, string endereco, string telefone, string dataIngresso, float salario, int desig);

        
        //Getters
        string getCodigo();
        int getDesig();
        string getNome();
        string getEndereco();
        string getTelefone();
        string getDataIngresso();
        float getSalario();

        //Setters
        void setCodigo(string codigo);
        void setDesig(int desig);
        void setNome(string nome);
        void setEndereco(string endereco);
        void setTelefone(string telefone);
        void setDataIngresso(string dataIngresso);
        void setSalario(float salario);

    protected:
        string codigo;
        int desig;

        string nome;
        string endereco;
        string telefone;
        string dataIngresso;
        float salario;

};
