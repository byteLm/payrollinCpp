/*
-> Classe 'Mãe' do projeto.
Todas as classes c1Gerente, c2Diretor e c3Presidente irão
derivar dessa classes.
Essa classes, além de implementar atributos gerais referentes ao funcionários (base)
também implementa o sistema de designação (linha 43).
*/



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
        int getTotalHorasExtras();
         int getDiasTrabalhados();
        //Setters
        void setCodigo(string codigo);
        void setDesig(int desig);
        void setNome(string nome);
        void setEndereco(string endereco);
        void setTelefone(string telefone);
        void setDataIngresso(string dataIngresso);
        void setSalario(float salario);
        void setTotalHorasExtras(float totalHorasExtras);
        void setDiasTrabalhados(int diasTrabalhados);
       
        void aleatorio();
        virtual void imprime();

    protected:
        string codigo;
        int desig; 
        string nome;
        string endereco;
        string telefone;
        string dataIngresso;
        float salario;
        int totalHorasExtras;
        int diasTrabalhados;


};
